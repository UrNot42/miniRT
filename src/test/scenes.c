/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:15:47 by marvin            #+#    #+#             */
/*   Updated: 2024/03/24 12:15:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	scene_cube(t_color backdrop)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	add_light(&world, point_light(set_point(-10, 10, -10), set_col(0, 0, 1)));
	add_light(&world, point_light(set_point(-15, 10, -15), set_col(1, 0, 0)));
	add_light(&world, point_light(set_point(0, 10, -10), set_col(0, 1, 0)));
	add_light(&world, point_light(set_point(-10, 10, 0), set_col(1, 1, 1)));
	// Floor
	s = plane();
	s.m.col = backdrop;
	s.m.specular = 0;
	set_transform(&s, translation_mtrx(0, -2, 0));
	add_obj(&world, s);
	// Left wall
	set_transform(&s, translation_mtrx(0, 0, 5) * rotation_y(-M_PI / 4)
		* rotation_x(M_PI / 2) * scale_mtrx(10, 0.01, 10));
	add_obj(&world, s);
	// Right wall
	set_transform(&s, translation_mtrx(0, 0, 5) * rotation_y(M_PI / 4)
		* rotation_x(M_PI / 2) * scale_mtrx(10, 0.01, 10));
	add_obj(&world, s);
	// Cube
	s = cube();
	s.m = material();
	s.m.col = set_col(0.1, 0.6, 0.6);
	s.m.diffuse = 0.7;
	s.m.specular = 0.3;
	set_transform(&s, translation_mtrx(-0.5, 1.6, 0.65) * rotation_y(M_PI / 3) * rotation_x(M_PI / 4) * scale_mtrx(1, 1, 1));
	add_obj(&world, s);
	return (world);
}

t_scene	scene_studio(t_color backdrop)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	add_light(&world, point_light(set_point(0, 5, -10), set_col(1, 1, 1)));
	// Floor
	s = plane();
	s.m.col = backdrop;
	s.m.specular = 0;
	add_obj(&world, s);
	// Left wall
	set_transform(&s, translation_mtrx(0, 0, 5) * rotation_y(-M_PI / 4)
		* rotation_x(M_PI / 2) * scale_mtrx(10, 0.01, 10));
	add_obj(&world, s);
	// Right wall
	set_transform(&s, translation_mtrx(0, 0, 5) * rotation_y(M_PI / 4)
		* rotation_x(M_PI / 2) * scale_mtrx(10, 0.01, 10));
	add_obj(&world, s);
	// Sphere Mid
	s = sphere();
	s.m = material();
	s.m.col = set_col(0.1, 0.6, 0.6);
	s.m.diffuse = 0.7;
	s.m.specular = 0.3;
	set_transform(&s, translation_mtrx(-0.5, 1.6, 0.65)
		* scale_mtrx(1.5, 1.5, 1.5));
	add_obj(&world, s);
	s.m.col = set_col(0.6, 0.6, 0.1);
	set_transform(&s, translation_mtrx(0, 2, -0.5)
		* scale_mtrx(0.5, 0.5, 0.5));
	add_obj(&world, s);
	// Sphere Right
	s.m.specular = 2;
	s.m.col = set_col(0.3, 0.2, 1);
	set_transform(&s,
		translation_mtrx(1.5, 0.5, -0.5) * shearing((t_shear){1, 0, 0, 0, 0, 0})
		* scale_mtrx(0.5, 0.5, 0.5));
	add_obj(&world, s);
	// Sphere Left
	s.m.specular = 0;
	s.m.col = set_col(0.6, 0.2, 0.8);
	set_transform(&s,
		translation_mtrx(-1.8, 0.66, -0.75) * rotation_z(M_PI / 3)
		* scale_mtrx(0.33, 0.7, 0.44));
	add_obj(&world, s);
	return (world);
}

#define SPACING 2.5

t_scene	scene_hex(t_color backdrop)
{
	t_scene	world;
	t_obj	o;

	// Init
	world = scene_init();
	add_light(&world, point_light(set_point(0, 6, 0), set_col(1, 1, 1)));
	// Floor
	o = plane();
	o.m.col = backdrop;
	add_obj(&world, o);
	// 1st
	set_transform(&o,
		translation_mtrx(0, 0, SPACING / sqrt(2)) * rotation_x(M_PI / 2));
	add_obj(&world, o);
	// 2nd
	set_transform(&o,
		translation_mtrx(0, 0, -SPACING / sqrt(2)) * rotation_x(M_PI / 2));
	add_obj(&world, o);
	// 3rd
	set_transform(&o,
		translation_mtrx(SPACING * sqrt(2), 0, 0) * rotation_y(-M_PI / 4) * rotation_z(M_PI / 2));
	add_obj(&world, o);
	// 4th
	set_transform(&o,
		translation_mtrx(-SPACING * sqrt(2), 0, 0) * rotation_y(-M_PI / 4) * rotation_z(M_PI / 2));
	add_obj(&world, o);
	// 5th
	set_transform(&o,
		translation_mtrx(SPACING * sqrt(2), 0, 0) * rotation_y(M_PI / 4) * rotation_z(M_PI / 2));
	add_obj(&world, o);
	// 6th
	set_transform(&o,
		translation_mtrx(-SPACING * sqrt(2), 0, 0) * rotation_y(M_PI / 4) * rotation_z(M_PI / 2));
	add_obj(&world, o);
	return (world);
}

// 	// 3rd
// 	set_transform(&o,
// 		translation_mtrx(0, 0, 5) * rotation_x(M_PI / 2) * rotation_y((M_PI * 2) / 3));
// 	add_obj(&world, o);
// 	// 4th
// 	set_transform(&o,
// 		translation_mtrx(0, 0, 5) * rotation_x(M_PI / 2) * rotation_y(M_PI));
// 	add_obj(&world, o);
// 	// 5th
// 	set_transform(&o,
// 		translation_mtrx(0, 0, 5) * rotation_x(M_PI / 2) * rotation_y(-(M_PI * 2) / 3));
// 	add_obj(&world, o);
// 	// 6th
// 	set_transform(&o,
// 		translation_mtrx(0, 0, 5) * rotation_x(M_PI / 2) * rotation_y(-M_PI / 3));
// 	add_obj(&world, o);
