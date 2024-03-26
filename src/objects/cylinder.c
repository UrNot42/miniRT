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

	cylinder = (t_obj){0};
	cylinder.type = OBJ_CYLINDER;
	cylinder.defined = true;
	cylinder.diameter = 1;
	cylinder.pos = origin();
	cylinder.ratio = -INFINITY;
	cylinder.fov = INFINITY;
	set_transform(&cylinder, get_id4mtrx());
	cylinder.m = material();
	return (cylinder);
}

t_intrs	cy_get_inters(float t1, float t2, t_obj *cylinder, t_ray r)
{
	t_intrs	x;
	float	y[2];

	x.count = 0;
	if (t1 > t2)
		fswap(&t1, &t2);
	y[0] = r.origin.y + t1 * r.direction.y;
	if (cylinder->ratio < y[0] && y[0] < cylinder->fov)
		x.i[x.count++] = get_inter(t1, cylinder);
	y[1] = r.origin.y + t2 * r.direction.y;
	if (cylinder->ratio < y[1] && y[1] < cylinder->fov)
		x.i[x.count++] = get_inter(t2, cylinder);
	return (x);
}

t_intrs	cy_intersect(t_obj *cylinder, t_ray r)
{
	float	a;
	float	b;
	float	c;
	t_intrs	x;

	x.count = 0;
	r = ray_transform(r, cylinder->inverse);
	a = (r.direction.x * r.direction.x) + (r.direction.z * r.direction.z);
	if (f_eq(a, 0))
		return (x);
	b = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	c = b * b - 4 * a * c;
	if (a < 0)
		return (x);
	x = cy_get_inters((-b - sqrtf(c)) / (2 * a), (-b + sqrtf(c)) / (2 * a),
			cylinder, r);
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
