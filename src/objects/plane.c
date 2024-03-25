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

t_obj	plane(void)
{
	t_obj	plane;

	plane.type = OBJ_PLANE;
	plane.defined = true;
	plane.pos = origin();
	set_transform(&plane, get_id4mtrx());
	plane.m = material();
	plane.m.specular = 0;
	return (plane);
}

t_intrs pl_intersect(t_obj *plane, t_ray r)
{
	float	t;
	t_intrs	x;

	x.count = 0;
	r = ray_transform(r, plane->inverse);
	if (fabs(r.direction.y) < EPSILON)
		return (x);
	t = -r.origin.y / r.direction.y;
	x.i[0] = get_inter(t, plane);
	x.count = 1;
	return (x);
}

t_tuple	pl_normal_at(t_obj plane, t_tuple point)
{
	t_tuple	vector;

	(void)point;
	vector = tup_mtrx(plane.trans_inv, set_vec(0, 1, 0));
	vector.w = 0;
	return (vec_norm(vector));
}
