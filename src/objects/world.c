/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:06:23 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/26 19:32:56 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief adds a new light to the scene, if necessary will realloc
 *
 * @param world
 * @param light
 * @return true
 * @return false
 */
bool	add_light(t_scene	*world, t_obj light)
{
	if (add_obj_sz(&world->light, &world->li_size))
		return (true);
	world->light[world->li_size.use - 1] = light;
	return (false);
}

/**
 * @brief adds a new object to the scene, if necessary will realloc
 *
 * @param world
 * @param obj
 * @return true
 * @return false
 */
bool	add_obj(t_scene	*world, t_obj obj)
{
	if (add_obj_sz(&world->objects, &world->obj_size))
		return (true);
	world->objects[world->obj_size.use - 1] = obj;
	return (false);
}

/**
 * @brief default world for simple testing
 *
 * @return t_scene
 */
t_scene	default_world(void)
{
	t_scene	world;
	t_obj	s1;
	t_obj	s2;
	t_obj	light;

	world = scene_init();
	light = point_light(set_point(-10, 10, -10), set_col(1, 1, 1));
	if (add_light(&world, light))
		return ((t_scene){0});
	s1 = sphere();
	s1.m.col = set_col(0.8, 1.0, 0.6);
	s1.m.diffuse = 0.7;
	s1.m.specular = 0.2;
	s2 = sphere();
	set_transform(&s2, scale_mtrx(0.5, 0.5, 0.5));
	if (add_obj(&world, s1))
		return ((t_scene){0});
	if (add_obj(&world, s2))
		return ((t_scene){0});
	return (world);
}
