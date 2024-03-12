/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:00:03 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/12 11:17:40 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	new_beam;

	new_beam.origin = origin;
	new_beam.direction = direction;
	return (new_beam);
}

t_tuple	position(t_ray beam, float time)
{
	return (beam.origin + beam.direction * time);
}

t_hit	intersect(t_obj *sphere, t_ray ray)
{
	t_hit	x;
	t_tuple	sphere_to_ray;
	float	a;
	float	b;
	float	c;

	sphere_to_ray = ray.origin - sphere->pos;
	a = vec_dot(ray.direction, ray.direction);
	b = 2 * vec_dot(ray.direction, sphere_to_ray);
	c = vec_dot(sphere_to_ray, sphere_to_ray) - 1;
	c = (b * b) - 4 * a * c;
	if (c >= 0)
	{
		x.t[0] = (-b - sqrtf(c)) / (2 * a);
		x.t[1] = (-b + sqrtf(c)) / (2 * a);
		x.count = 2;
	}
	else
		x.count = 0;
	return (x);
}
