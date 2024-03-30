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

t_cylinder	cylinder(void)
{
	t_cylinder	cylinder;

	cylinder = (t_cylinder){0};
	cylinder.def = true;
	cylinder.width = 1;
	cylinder.pos = origin();
	cylinder.minimum = -INFINITY;
	cylinder.maximum = INFINITY;
	set_transform(&cylinder.mtx, get_id4mtrx());
	cylinder.m = material();
	return (cylinder);
}

t_obj	o_cylinder(void)
{
	t_obj	obj;

	obj = (t_obj){0};
	obj.cylinder = cylinder();
	obj.kind = OBJ_CYLINDER;
	return (obj);
}

t_intrs	cy_get_inters(float t1, float t2, t_obj *obj, t_ray r)
{
	t_intrs	x;
	float	y[2];

	x.count = 0;
	if (t1 > t2)
		fswap(&t1, &t2);
	y[0] = r.origin.y + t1 * r.direction.y;
	if (obj->cylinder.minimum < y[0] && y[0] < obj->cylinder.maximum)
		x.i[x.count++] = get_inter(t1, obj);
	y[1] = r.origin.y + t2 * r.direction.y;
	if (obj->cylinder.minimum < y[1] && y[1] < obj->cylinder.maximum)
		x.i[x.count++] = get_inter(t2, obj);
	return (x);
}

t_intrs	cy_intersect(t_obj *obj, t_ray r)
{
	float	a;
	float	b;
	float	c;
	t_intrs	x;

	x.count = 0;
	r = ray_transform(r, obj->cylinder.inverse);
	a = (r.direction.x * r.direction.x) + (r.direction.z * r.direction.z);
	if (f_eq(a, 0))
		return (x);
	b = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	c = b * b - 4 * a * c;
	if (c < 0)
		return (x);
	x = cy_get_inters((-b - sqrtf(c)) / (2 * a), (-b + sqrtf(c)) / (2 * a),
			obj, r);
	cy_intersect_caps(obj, r, &x);
	return (x);
}
