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

t_sphere	sphere(void)
{
	t_sphere	sphere;

	sphere = (t_sphere){0};
	sphere.pos = origin();
	sphere.m = material();
	sphere.diameter = 1;
	set_transform(&sphere.mtx, get_id4mtrx());
	return (sphere);
}

t_obj	o_sphere(void)
{
	t_obj	obj;

	obj = (t_obj){0};
	obj.sphere = sphere();
	obj.kind = OBJ_SPHERE;
	obj.defined = true;
	return (obj);
}

// Creates an intersection Array with a sphere
t_intrs	sp_intersect(t_obj *obj, t_ray ray)
{
	t_intrs	x;
	t_tuple	sphere_to_ray;
	float	a;
	float	b;
	float	c;

	ray = ray_transform(ray, obj->sphere.inverse);
	sphere_to_ray = ray.origin - origin();
	a = vec_dot(ray.direction, ray.direction);
	b = 2 * vec_dot(ray.direction, sphere_to_ray);
	c = vec_dot(sphere_to_ray, sphere_to_ray) - 1;
	c = (b * b) - 4 * a * c;
	if (c >= 0)
	{
		x.i[0] = get_inter((-b - sqrtf(c)) / (2 * a), obj);
		x.i[1] = get_inter((-b + sqrtf(c)) / (2 * a), obj);
		x.count = 2;
	}
	else
		x.count = 0;
	return (x);
}

t_tuple	sp_normal_at(t_sphere sphere, t_tuple point)
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
