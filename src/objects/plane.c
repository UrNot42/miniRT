/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:47:05 by marvin            #+#    #+#             */
/*   Updated: 2024/03/24 11:47:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	plane(void)
{
	t_plane	plane;

	plane = (t_plane){0};
	plane.def = true;
	plane.pos = origin();
	plane.m = material();
	plane.m.specular = 1;
	set_transform(&plane.mtx, get_id4mtrx());
	return (plane);
}

t_obj	o_plane(void)
{
	t_obj	obj;

	obj = (t_obj){0};
	obj.plane = plane();
	obj.kind = OBJ_PLANE;
	return (obj);
}

t_intrs	pl_intersect(t_obj *obj, t_ray r)
{
	float	t;
	t_intrs	x;

	x.count = 0;
	r = ray_transform(r, obj->plane.inverse);
	if (fabs(r.direction.y) < EPSILON)
		return (x);
	t = -r.origin.y / r.direction.y;
	x.i[0] = get_inter(t, obj);
	x.count = 1;
	return (x);
}

t_tuple	pl_normal_at(t_plane plane, t_tuple point)
{
	t_tuple	vector;

	(void)point;
	vector = tup_mtrx(plane.trans_inv, set_vec(0, 1, 0));
	vector.w = 0;
	return (vec_norm(vector));
}
