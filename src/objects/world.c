/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:06:23 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 09:43:55 by ulevallo         ###   ########.fr       */
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
bool	add_light(t_scene *world, t_obj light)
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
	light = o_light(set_point(-10, 10, -10), set_col(1, 1, 1));
	if (add_light(&world, light))
		return ((t_scene){0});
	world.ambient_light.color = set_col(1, 1, 1);
	world.ambient_light.alght.ratio = 0.1;
	s1 = o_sphere();
	s1.m.col = set_col(0.8, 1.0, 0.6);
	s1.m.diffuse = 0.7;
	s1.m.specular = 0.2;
	s2 = o_sphere();
	set_transform(&s2.sphere.mtx, scale_mtrx(0.5, 0.5, 0.5));
	if (add_obj(&world, s1))
		return ((t_scene){0});
	if (add_obj(&world, s2))
		return ((t_scene){0});
	return (world);
}

void	regularize_light(t_scene *world)
{
	t_color	total;
	t_color	divide;
	t_unt	i;

	total = set_col(0, 0, 0);
	i = 0;
	while (i < world->li_size.use)
	{
		total.tuple += world->light[i].color.tuple;
		i++;
	}
	divide = total;
	if (divide.red < 1)
		divide.red = 1;
	if (divide.green < 1)
		divide.green = 1;
	if (divide.blue < 1)
		divide.blue = 1;
	i = 0;
	while (i < world->li_size.use)
	{
		world->light[i].color.tuple /= divide.tuple;
		i++;
	}
}
