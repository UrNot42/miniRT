/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:15:04 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/29 18:55:54 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cone	cone(void)
{
	t_cone	cone;

	cone = (t_cone){0};
	cone.def = true;
	cone.width = 1;
	cone.pos = origin();
	cone.minimum = -INFINITY;
	cone.maximum = INFINITY;
	set_transform(&cone.mtx, get_id4mtrx());
	cone.m = material();
	return (cone);
}

t_obj	o_cone(void)
{
	t_obj	obj;

	obj = (t_obj){0};
	obj.cone = cone();
	obj.kind = OBJ_CONE;
	return (obj);
}

static t_tuple	cone_normal_vector(t_cone co, t_tuple point)
{
	float	dist;
	float	y;

	dist = point.x * point.x + point.z * point.z;
	y = co.minimum * co.minimum;
	if (dist < fabs(co.maximum * co.maximum) && point.y >= co.maximum - EPSILON)
		return (set_vec(0, 1, 0));
	else if (dist < fabs(y) && point.y <= co.minimum + EPSILON)
		return (set_vec(0, -1, 0));
	y = sqrtf((point.x * point.x) + (point.z * point.z));
	if (point.y > 0)
		y = -y;
	return (set_vec(point.x, y, point.z));
}

t_tuple	cone_normal_at(t_cone co, t_tuple point)
{
	t_ray	object;
	t_ray	world;

	world.origin = point;
	object.origin = tup_mtrx(co.inverse, world.origin);
	object.direction = cone_normal_vector(co, object.origin);
	world.direction = tup_mtrx(co.trans_inv, object.direction);
	world.direction.w = 0;
	return (vec_norm(world.direction));
}
