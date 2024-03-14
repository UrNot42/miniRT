/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:26:49 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/14 14:53:52 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_world(void)
{
	t_scene	w;
	t_unt	err;

	scenario_start("Creating a world");
	given("w ← world()", 0);
	w = scene_init();
	err = then("w contains no objects", w.obj_size.use == 0, 0);
	err = then("w has no light source", w.obj_size.use == 0, 1);
	scenario_end(err);
	return (err);
}

/*
Scenario:
Given light ← point_light(point(-10, 10, -10), color(1, 1, 1))
And s1 ← sphere() with:
| material.color
| (0.8, 1.0, 0.6)
|
| material.diffuse
| 0.7
|
| material.specular | 0.2
|
And s2 ← sphere() with:
| transform | scaling(0.5, 0.5, 0.5) |
When w ← default_world()
Then w.light = light
And w contains s1
And w contains s2
 */

t_unt	test_world_default(void)
{
	t_unt	err;

	scenario_start("The default world");
	given("", 0);
	given("", 1);
	when("", 0);
	err = then("", 0, 0);
	scenario_end(err);
	return (err);
}
