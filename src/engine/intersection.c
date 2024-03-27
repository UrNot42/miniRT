/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:04:11 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/27 09:12:23 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Creates an intersection with selected object
 *
 * @param object object to intersect
 * @param ray
 * @return an array of intersections linked with their object
 */
t_intrs	intersect(t_obj *object, t_ray ray)
{
	t_intrs	intersections;

	intersections.count = 0;
	if (object->kind == OBJ_SPHERE)
		intersections = sp_intersect(object, ray);
	else if (object->kind == OBJ_PLANE)
		intersections = pl_intersect(object, ray);
	else if (object->kind == OBJ_CYLINDER)
		intersections = cy_intersect(object, ray);
	else if (object->kind == OBJ_CUBE)
		intersections = cube_intersect(object, ray);
	return (intersections);
}

/**
 * @brief Creates a concatenation of intersections
 *
 * @param count amount of intersections givent
 * @param inters
 * @return Creates
 */
t_intrs	add_inters(t_unt count, t_inter inters[INTER_MAX])
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

/**
 * @brief checks inside an array of intersection
 *
 * @param inters the given array
 * @return returns the first positive intersection
 */
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

/**
 * @brief Boolean check for intersections
 *
 * @param a
 * @param b
 * @return true if they are stricly identical
 * @return false
 */
bool	is_same_inter(t_inter a, t_inter b)
{
	if (a.obj == b.obj && f_eq(a.t, b.t) && a.def == b.def)
		return (true);
	return (false);
}

/**
 * @brief gives a sorted array of interstions with the ray
 *  and every object on the scene
 * @param world
 * @param r
 * @return t_intrs
 */
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
