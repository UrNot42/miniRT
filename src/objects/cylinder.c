/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:27:30 by marvin            #+#    #+#             */
/*   Updated: 2024/03/23 10:27:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	cylinder(void)
{
	t_obj	cylinder;

	cylinder.type = OBJ_CYLINDER;
	cylinder.defined = true;
	cylinder.diameter = 1;
	cylinder.pos = origin();
	set_transform(&cylinder, get_id4mtrx());
	cylinder.m = material();
	return (cylinder);
}

t_intrs cy_intersect(t_obj *cylinder, t_ray r)
{
	float	a;
	float	b;
	float	c;
	float	t[2];
	t_intrs	x;

	r = ray_transform(r, cylinder->inverse);
	a = (r.direction.x * r.direction.x) + (r.direction.z * r.direction.z);
	x.count = 0;
	if (f_eq(a, 0))
		return (x);
	b = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	c = b * b - 4 * a * c;
	if (a < 0)
		return (x);
	t[0] = (-b - sqrtf(c)) / (2 * a);
	t[1] = (-b + sqrtf(c)) / (2 * a);
	x.i[0] = get_inter(t[0], cylinder);
	x.i[1] = get_inter(t[1], cylinder);
	x.count = 2;
	return (x);
}

t_tuple	cy_normal_at(t_obj cy, t_tuple point)
{
	t_ray	object;
	t_ray	world;

	world.origin = point;
	object.origin = tup_mtrx(cy.inverse, world.origin);
	object.direction = set_vec(object.origin.x, 0, object.origin.z);
	world.direction = tup_mtrx(cy.trans_inv, object.direction);
	world.direction.w = 0;
	return (vec_norm(world.direction));
}
