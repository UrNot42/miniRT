/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:42:12 by marvin            #+#    #+#             */
/*   Updated: 2024/03/23 11:42:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	sphere(void)
{
	t_obj	sphere;

	sphere.type = OBJ_SPHERE;
	sphere.defined = true;
	sphere.diameter = 1;
	sphere.pos = origin();
	set_transform(&sphere, get_id4mtrx());
	sphere.m = material();
	return (sphere);
}

// Creates an intersection Array with a sphere
t_intrs	sp_intersect(t_obj *sphere, t_ray ray)
{
	t_intrs	x;
	t_tuple	sphere_to_ray;
	float	a;
	float	b;
	float	c;

	ray = ray_transform(ray, sphere->inverse);
	sphere_to_ray = ray.origin - origin();
	a = vec_dot(ray.direction, ray.direction);
	b = 2 * vec_dot(ray.direction, sphere_to_ray);
	c = vec_dot(sphere_to_ray, sphere_to_ray) - 1;
	c = (b * b) - 4 * a * c;
	if (c >= 0)
	{
		x.i[0] = get_inter((-b - sqrtf(c)) / (2 * a), sphere);
		x.i[1] = get_inter((-b + sqrtf(c)) / (2 * a), sphere);
		x.count = 2;
	}
	else
		x.count = 0;
	return (x);
}

t_tuple	sp_normal_at(t_obj sphere, t_tuple point)
{
	t_ray	object;
	t_ray	world;

	world.origin = point;
	object.origin = tup_mtrx(sphere.inverse, world.origin);
	object.direction = object.origin - origin();
	world.direction = tup_mtrx(sphere.trans_inv, object.direction);
	world.direction.w = 0;
	return (vec_norm(world.direction));
}
