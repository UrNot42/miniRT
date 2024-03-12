/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:04:11 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/12 18:23:57 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intrs	intersect(t_obj *sphere, t_ray ray)
{
	t_intrs	x;
	t_tuple	sphere_to_ray;
	float	a;
	float	b;
	float	c;

	ray = ray_transform(ray, inverse_4mtrx(sphere->transform));
	sphere_to_ray = ray.origin - set_point(0, 0, 0);
	a = vec_dot(ray.direction, ray.direction);
	b = 2 * vec_dot(ray.direction, sphere_to_ray);
	c = vec_dot(sphere_to_ray, sphere_to_ray) - 1;
	c = (b * b) - 4 * a * c;
	if (c >= 0)
	{
		x.i[0] = intersection((-b - sqrtf(c)) / (2 * a), sphere);
		x.i[1] = intersection((-b + sqrtf(c)) / (2 * a), sphere);
		x.count = 2;
	}
	else
		x.count = 0;
	return (x);
}

t_inter	intersection(float time, t_obj *obj)
{
	bool	state;

	state = false;
	if (obj)
		state = true;
	return ((t_inter){time, obj, state});
}

t_intrs	intersections(t_unt count, t_inter inters[INTER_MAX])
{
	t_intrs	x;
	t_unt	id;

	id = 0;
	while (id < count)
	{
		x.i[id] = inters[id];
		id++;
	}
	x.count = count;
	return (x);
}

t_inter	find_hit(t_intrs inters)
{
	t_unt	id;
	t_inter	hit;

	hit.t = 0;
	hit.obj = NULL;
	hit.def = false;
	id = 0;
	while (id < inters.count)
	{
		if (inters.i[id].t >= 0 && (!hit.obj || inters.i[id].t < hit.t))
			hit = inters.i[id];
		id++;
	}
	return (hit);
}

bool	is_same_inter(t_inter a, t_inter b)
{
	if (a.obj == b.obj && f_eq(a.t, b.t) && a.def == b.def)
		return (true);
	return (false);
}
