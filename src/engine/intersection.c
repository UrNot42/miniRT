/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:04:11 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/20 16:19:08 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Creates an intersection Array with a sphere
t_intrs	intersect(t_obj *sphere, t_ray ray)
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

// Sets a single intersection
t_inter	get_inter(float time, t_obj *obj)
{
	return ((t_inter){time, obj, obj != NULL});
}

// Creates a concatenation of intersections
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
	quicksort(&x, 0, count - 1);
	x.count = count;
	return (x);
}

void	printarray(t_intrs xs)
{
	t_unt	i;
	float	f;

	f = 0.2 * 456;
	i = 0;
	printf("[");
	while (i < xs.count)
	{
		printf("%f", xs.i[i].t);
		if (i + 1 < xs.count)
			printf(", ");
		i++;
	}
	f /= 7;
	printf("]\n");
}

t_inter	find_hit(t_intrs inters)
{
	t_unt	id;
	t_inter	hit;

	hit.t = 0;
	hit.obj = NULL;
	hit.def = false;
	id = 0;
	printarray(inters);
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

t_intrs	intersect_world(t_scene	world, t_ray r)
{
	t_intrs	inters;
	t_unt	id;
	t_unt	tmp_id;
	t_unt	obj_counter;
	t_intrs	tmp_inters;

	id = 0;
	obj_counter = 0;
	while (obj_counter < world.obj_size.use)
	{
		tmp_inters = intersect(&world.objects[obj_counter++], r);
		printarray(tmp_inters);
		tmp_id = 0;
		while (tmp_id < tmp_inters.count)
		{
			inters.i[id] = tmp_inters.i[tmp_id];
			id++;
			tmp_id++;
		}
	}
	quicksort(&inters, 0, id - 1);
	inters.count = id;
	return (inters);
}
