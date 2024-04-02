/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_method.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:21:15 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/02 09:45:40 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_cap(t_ray r, float t)
{
	float	x;
	float	z;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;
	return (((x * x) + (z * z)) <= 1);
}

void	cy_intersect_caps(t_obj *obj, t_ray r, t_intrs *xs)
{
	float		t;
	t_cylinder	cy;

	if (f_eq(r.direction.y, 0))
		return ;
	cy = obj->cylinder;
	if (cy.min_caped)
	{
		t = (cy.minimum - r.origin.y) / r.direction.y;
		if (check_cap(r, t))
			xs->i[xs->count++] = get_inter(t, obj);
	}
	if (cy.max_caped)
	{
		t = (cy.maximum - r.origin.y) / r.direction.y;
		if (check_cap(r, t))
			xs->i[xs->count++] = get_inter(t, obj);
	}
}

static t_tuple	cy_normal_vector(t_cylinder cy, t_tuple point)
{
	float	dist;

	dist = point.x * point.x + point.z * point.z;
	if (dist < 1 && point.y >= cy.maximum - EPSILON)
		return (set_vec(0, 1, 0));
	else if (dist < 1 && point.y <= cy.minimum + EPSILON)
		return (set_vec(0, -1, 0));
	else
		return (set_vec(point.x, 0, point.z));
}

t_tuple	cy_normal_at(t_cylinder cy, t_tuple point)
{
	t_ray	object;
	t_ray	world;

	world.origin = point;
	object.origin = tup_mtrx(cy.inverse, world.origin);
	object.direction = cy_normal_vector(cy, object.origin);
	world.direction = tup_mtrx(cy.trans_inv, object.direction);
	world.direction.w = 0;
	return (vec_norm(world.direction));
}
