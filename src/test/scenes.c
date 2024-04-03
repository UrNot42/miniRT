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

#define SIZE 400

t_scene	scene_sphere(t_color backdrop)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	// Camera
	world.camera.camera = camera(SIZE, SIZE, M_PI / 3);
	set_transform(&world.camera.camera.mtx, view_transform(set_point(1, 4, -6), set_point(-2, 2.5, 1), set_vec(0, 1, 0)));
	add_light(&world, o_light(set_point(2 + 1.5, 3, -3), set_col(0.9, 0.9, 0.9)));
	// Floor
	s = o_plane();
	s.m.col = backdrop;
	s.m.specular = 0;
	set_transform(&s.sphere.mtx, translation_mtrx(0, -2, 0));
	add_obj(&world, s);
	// Sphere
	s = o_sphere();
	s.m = material();
	s.m.col = set_col(0.1, 0.6, 0.6);
	s.m.diffuse = 0.7;
	s.m.specular = 0.3;
	s.m.shininess = 8;
	set_transform(&s.sphere.mtx, translation_mtrx(-0.5, 1.6, 0.65) * rotation_y(M_PI / 3) * rotation_x(M_PI / 4) * scale_mtrx(1, 1, 1));
	add_obj(&world, s);
	return (world);
}

t_scene	scene_cube(t_color backdrop)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	// Camera
	world.camera.camera = camera(SIZE, SIZE, M_PI / 3);
	set_transform(&world.camera.camera.mtx, view_transform(set_point(0, 3, -7), set_point(0, 1, 0), set_vec(0, 1, 0)));
	add_light(&world, o_light(set_point(-7, 11, -4), set_col(1, 0, 0)));
	add_light(&world, o_light(set_point(-4, 11, -4), set_col(0, 1, 0)));
	add_light(&world, o_light(set_point(-4, 11, -7), set_col(0, 0, 1)));
	// Floor
	s = o_plane();
	s.m.col = backdrop;
	s.m.specular = 0;
	set_transform(&s.sphere.mtx, translation_mtrx(0, -2, 0));
	add_obj(&world, s);
	// Cube
	s = o_cube();
	s.m = material();
	s.m.col = set_col(0.1, 0.6, 0.6);
	s.m.diffuse = 0.7;
	s.m.specular = 0.3;
	set_transform(&s.sphere.mtx, translation_mtrx(-0.5, 1.6, 0.65) * rotation_z(-M_PI / 6.1) * rotation_y(M_PI / 4) * rotation_x(M_PI / 4) * scale_mtrx(1, 1, 1));
	add_obj(&world, s);
	return (world);
}

t_scene	scene_studio(t_color backdrop)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	// Camera
	world.camera.camera = camera(SIZE, SIZE, M_PI / 3);
	set_transform(&world.camera.camera.mtx, view_transform(set_point(1, 4, -6), set_point(0, 2, 0), set_vec(0, 1, 0)));
	add_light(&world, o_light(set_point(5, 5, -10), set_col(1, 1, 1)));
	// Floor
	s = o_plane();
	s.m.col = backdrop;
	s.m.specular = 0;
	add_obj(&world, s);
	// Left wall
	set_transform(&s.sphere.mtx, translation_mtrx(0, 0, 5) * rotation_y(-M_PI / 4)
		* rotation_x(M_PI / 2) * scale_mtrx(10, 0.01, 10));
	add_obj(&world, s);
	// Right wall
	set_transform(&s.sphere.mtx, translation_mtrx(0, 0, 5) * rotation_y(M_PI / 4)
		* rotation_x(M_PI / 2) * scale_mtrx(10, 0.01, 10));
	add_obj(&world, s);
	// Sphere Mid
	s = o_sphere();
	s.m = material();
	s.m.col = set_col(0.1, 0.6, 0.6);
	s.m.diffuse = 0.7;
	s.m.specular = 0.3;
	set_transform(&s.sphere.mtx, translation_mtrx(-0.5, 1.6, 0.65)
		* scale_mtrx(1.5, 1.5, 1.5));
	add_obj(&world, s);
	s.m.col = set_col(0.6, 0.6, 0.1);
	set_transform(&s.sphere.mtx, translation_mtrx(0, 2, -0.5)
		* scale_mtrx(0.5, 0.5, 0.5));
	add_obj(&world, s);
	// Sphere Right
	s.m.specular = 2;
	s.m.col = set_col(0.3, 0.2, 1);
	set_transform(&s.sphere.mtx,
		translation_mtrx(1.5, 0.5, -0.5) * shearing((t_shear){1, 0, 0, 0, 0, 0})
		* scale_mtrx(0.5, 0.5, 0.5));
	add_obj(&world, s);
	// Sphere Left
	s.m.specular = 0;
	s.m.col = set_col(0.6, 0.2, 0.8);
	set_transform(&s.sphere.mtx,
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
	// Camera
	world.camera.camera = camera(SIZE, SIZE, M_PI / 3);
	set_transform(&world.camera.camera.mtx, view_transform(set_point(0, 1.5, -0.21), set_point(0, 0, 0), set_vec(0, 1, 0)));
	add_light(&world, o_light(set_point(0, 6, 0), set_col(1, 1, 1)));
	// Floor
	o = o_plane();
	o.m.col = backdrop;
	add_obj(&world, o);
	// 1st
	set_transform(&o.sphere.mtx,
		translation_mtrx(0, 0, SPACING / sqrt(2)) * rotation_x(M_PI / 2));
	add_obj(&world, o);
	// 2nd
	set_transform(&o.sphere.mtx,
		translation_mtrx(0, 0, -SPACING / sqrt(2)) * rotation_x(M_PI / 2));
	add_obj(&world, o);
	// 3rd
	set_transform(&o.sphere.mtx,
		translation_mtrx(SPACING * sqrt(2), 0, 0) * rotation_y(-M_PI / 4) * rotation_z(M_PI / 2));
	add_obj(&world, o);
	// 4th
	set_transform(&o.sphere.mtx,
		translation_mtrx(-SPACING * sqrt(2), 0, 0) * rotation_y(-M_PI / 4) * rotation_z(M_PI / 2));
	add_obj(&world, o);
	// 5th
	set_transform(&o.sphere.mtx,
		translation_mtrx(SPACING * sqrt(2), 0, 0) * rotation_y(M_PI / 4) * rotation_z(M_PI / 2));
	add_obj(&world, o);
	// 6th
	set_transform(&o.sphere.mtx,
		translation_mtrx(-SPACING * sqrt(2), 0, 0) * rotation_y(M_PI / 4) * rotation_z(M_PI / 2));
	add_obj(&world, o);
	return (world);
}

t_scene	scene_cylinder(t_color backdrop)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	// Camera
	world.camera.camera = camera(SIZE, SIZE, M_PI / 3);
	set_transform(&world.camera.camera.mtx, view_transform(set_point(1, 4, -8), set_point(0, 2, 0), set_vec(0, 1, 0)));
	add_light(&world, o_light(set_point(-10, 10, -10), set_col(1, 1, 1)));
	// Floor
	s = o_plane();
	s.m.col = backdrop;
	s.m.specular = 0;
	set_transform(&s.sphere.mtx, translation_mtrx(0, -2, 0));
	add_obj(&world, s);
	// Left wall
	set_transform(&s.sphere.mtx, translation_mtrx(0, 0, 5) * rotation_y(-M_PI / 4)
		* rotation_x(M_PI / 2) * scale_mtrx(10, 0.01, 10));
	add_obj(&world, s);
	// Right wall
	set_transform(&s.sphere.mtx, translation_mtrx(0, 0, 5) * rotation_y(M_PI / 4)
		* rotation_x(M_PI / 2) * scale_mtrx(10, 0.01, 10));
	add_obj(&world, s);
	// Cylinder
	s = o_cylinder();
	s.m = material();
	s.m.diffuse = 0.7;
	s.m.col = set_col(0.6, 0.1, 0.6);
	set_transform(&s.cone.mtx, translation_mtrx(-3, 0.5, 1) * rotation_y(-M_PI / 6) * rotation_z(M_PI / 6) * scale_mtrx(1.2, 1.2, 1.2));
	add_obj(&world, s);
	s.m.specular = 0.3;
	s.m.col = set_col(0.1, 0.6, 0.6);
	s.cone.minimum = 1;
	s.cone.maximum = 4;
	set_transform(&s.cone.mtx, translation_mtrx(0, 1.6, 0.65) * rotation_x(M_PI / 2.2));
	add_obj(&world, s);
	s.m.col = set_col(0.6, 0.6, 0.1);
	s.cone.minimum = 0;
	s.cone.maximum = 1;
	s.cone.min_caped = true;
	s.cone.max_caped = true;
	set_transform(&s.cone.mtx, translation_mtrx(3, 1.2, 0.65) * rotation_y(-M_PI / 6) * rotation_x(-M_PI / 4) * scale_mtrx(0.8, 0.8, 0.8));
	add_obj(&world, s);
	return (world);
}

t_scene	scene_cone(t_color backdrop)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	// Camera
	world.camera.camera = camera(SIZE, SIZE, M_PI / 3);
	set_transform(&world.camera.camera.mtx, view_transform(set_point(0, 5, -13), set_point(0, 3, 0), set_vec(0, 1, 0)));
	add_light(&world, o_light(set_point(-10, 5, -10), set_col(1, 1, 1)));
	add_light(&world, o_light(set_point(10, 5, -10), set_col(1, 1, 1)));
	regularize_light(&world);
	// Floor
	s = o_plane();
	s.m.col = backdrop;
	s.m.specular = 0;
	set_transform(&s.sphere.mtx, translation_mtrx(0, -2, 0));
	add_obj(&world, s);
	// Cone
	s = o_cone();
	s.m = material();
	s.color = set_col(1, 0.4, 0.4);
	s.m.diffuse = 0.7;
	s.m.specular = 0.3;
	set_transform(&s.cone.mtx, translation_mtrx(0, 3, 2) * scale_mtrx(0.5, 1, 0.5));
	add_obj(&world, s);
	s.color = set_col(0.4, 0.4, 1);
	s.cone.min_caped = true;
	s.cone.minimum = 4;
	set_transform(&s.cone.mtx, translation_mtrx(6, 3, 2) * scale_mtrx(0.5, 1, 0.5));
	add_obj(&world, s);
	s.cone.min_caped = false;
	s.cone.minimum = -INFINITY;
	s.cone.max_caped = true;
	s.cone.maximum = -2;
	set_transform(&s.cone.mtx, translation_mtrx(6, 3, 2) * scale_mtrx(0.5, 1, 0.5));
	add_obj(&world, s);
	s.cone.max_caped = false;
	s.cone.maximum = -2.5;
	s.color = set_col(0.4, 1, 0.4);
	set_transform(&s.cone.mtx, translation_mtrx(-6, 3, 2) * scale_mtrx(0.5, 1, 0.5));
	add_obj(&world, s);
	// s.cone.maximum = 0;
	// s.color = set_col(0.2, 0.6, 0.4);
	// set_transform(&s.cone.mtx, translation_mtrx(-6, 3, 2) * scale_mtrx(0.5, 1, 0.5));
	// add_obj(&world, s);
	return (world);
}

t_scene	scene_cooloon(t_color backdrop)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	// Camera
	world.camera.camera = camera(SIZE * 1.5, SIZE * 1.5, M_PI / 3);
	set_transform(&world.camera.camera.mtx, view_transform(set_point(1, 5, -11), set_point(1, 5, 1), set_vec(0, 1, 1)));
	add_light(&world, o_light(set_point(1+ -9, 7, -11), set_col(0.5, 0.5, 0.5)));
	add_light(&world, o_light(set_point(1 + 9, 7, -11), set_col(0.5, 0.5, 0.5)));
	// Floor
	s = o_plane();
	s.color = backdrop;
	s.m.specular = 0;
	set_transform(&s.sphere.mtx, translation_mtrx(0, 1, 0));
	add_obj(&world, s);
	// Ceiling
	set_transform(&s.sphere.mtx, translation_mtrx(0, 8, 0));
	add_obj(&world, s);
	// Back wall
	s.color = set_col(0.3, 0.3, 0.8);
	set_transform(&s.sphere.mtx, translation_mtrx(0, 0, 14.5) * rotation_x(M_PI / 2));
	add_obj(&world, s);
	// Red sphere
	s = o_sphere();
	s.m = material();
	s.m.col = set_col(1, 0, 0);
	s.m.diffuse = 1;
	s.m.specular = 1;
	set_transform(&s.sphere.mtx, translation_mtrx(1, 2, -2) * scale_mtrx(0.5, 0.5, 0.5));
	add_obj(&world, s);
	// Columns
	s.m.shininess = 16;
	s.color = set_col(0.7, 0.7, 0.7);
	set_transform(&s.sphere.mtx, translation_mtrx(1 + -4, 1, -2) * scale_mtrx(1.5, 1.5, 1.5));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(1 + 4, 1, -2) * scale_mtrx(1.5, 1.5, 1.5));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(1 + 4, 1, 7) * scale_mtrx(1.5, 1.5, 1.5));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(1 + -4, 1, 7) * scale_mtrx(1.5, 1.5, 1.5));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(1 + -4, 8, -2) * scale_mtrx(1.5, 1.5, 1.5));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(1 + 4, 8, -2) * scale_mtrx(1.5, 1.5, 1.5));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(1 + 4, 8, 7) * scale_mtrx(1.5, 1.5, 1.5));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(1 + -4, 8, 7) * scale_mtrx(1.5, 1.5, 1.5));
	add_obj(&world, s);
	s.color = set_col(0.6, 0.6, 0.6);
	s = o_cylinder();
	set_transform(&s.sphere.mtx, translation_mtrx(1 + -4, 1.5, -2) * scale_mtrx(1, 1, 1));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(1 + 4, 1.5, -2) * scale_mtrx(1, 1, 1));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(1 + 4, 1.5, 7) * scale_mtrx(1, 1, 1));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(1 + -4, 1.5, 7) * scale_mtrx(1, 1, 1));
	add_obj(&world, s);
	return (world);
}

t_scene	scene_multi_light(t_dim size)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	// Cam
	world.camera.camera = camera(size.x, size.y, M_PI / 2);
	set_transform(&world.camera.camera.mtx, view_transform(set_point(10, 10, -18), set_point(9.4, 9.4, -17), set_vec(0, 1, 0)));
	// Ligths
	add_light(&world, o_light(set_point(-5, 5, 0), set_col(0, 0, 1)));
	world.light[0].light.ratio = 0.5;
	add_light(&world, o_light(set_point(5, 5, 0), set_col(1, 0, 0)));
	world.light[1].light.ratio = 0.5;
	add_light(&world, o_light(set_point(5, 0, 5), set_col(0, 1, 0)));
	world.light[2].light.ratio = 0.5;
	world.ambient_light.alght.color = set_col(1, 1, 1);
	world.ambient_light.alght.ratio = 0.2;
	// Floor
	s = o_plane();
	s.color = set_col(150.0 / COL_SCALE, 150.0 / COL_SCALE, 150.0 / COL_SCALE);
	set_transform(&s.sphere.mtx, translation_mtrx(0, -2, 0));
	add_obj(&world, s);
	s.color = set_col(150.0 / COL_SCALE, 50.0 / COL_SCALE, 100.0 / COL_SCALE);
	set_transform(&s.sphere.mtx, translation_mtrx(-60, -60, 100) * rotation_x(M_PI / 2));
	add_obj(&world, s);
	// Spheres
	s = o_sphere();
	s.m = material();
	s.m.col = set_col(1, 1, 1);
	// s.m.diffuse = 1;
	// s.m.specular = 1;
	set_transform(&s.sphere.mtx, translation_mtrx(10, 0, 0) * scale_mtrx(2, 2, 2));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(-4, 0,-10) * scale_mtrx(2, 2, 2));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(4, 0, -10) * scale_mtrx(2, 2, 2));
	add_obj(&world, s);
	set_transform(&s.sphere.mtx, translation_mtrx(0, 0, 0) * scale_mtrx(2, 2, 2));
	add_obj(&world, s);
	return (world);
}

t_scene	scene_example(t_color backdrop)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	// Camera
	world.camera.camera = camera(SIZE, SIZE, M_PI / 3);
	set_transform(&world.camera.camera.mtx, view_transform(set_point(1, 1, -7), set_point(0, 0, 0), set_vec(0, 1, 0)));
	// set_transform(&world.camera.camera.mtx, view_transform(set_point(8, 3, -5), set_point(2, -1, 0), set_vec(0, 1, 0)));
	add_light(&world, o_light(set_point(4, -1, -5), set_col(1, 1, 1)));
	// Floor
	s = o_plane();
	s.m.col = backdrop;
	s.m.specular = 0;
	set_transform(&s.sphere.mtx, translation_mtrx(0, -2, 0));
	add_obj(&world, s);
	s.color = set_col(0, 0, 1);
	set_transform(&s.sphere.mtx, translation_mtrx(0, 0, 6) * rotation_x(M_PI / 2));
	add_obj(&world, s);
	// Cone
	s = o_cone();
	s.m = material();
	s.color = set_col(1, 1, 0);
	s.m.diffuse = 0.7;
	s.m.specular = 1;
	set_transform(&s.cone.mtx, translation_mtrx(2, -0.8, 0.9) * rotation_z(M_PI / 7));
	add_obj(&world, s);
	s = o_sphere();
	s.color = set_col(2, 0, 0);
	s.m.shininess = 4;
	set_transform(&s.sphere.mtx, translation_mtrx(0.2, -0.9, 0.3) * scale_mtrx(1.5, 1.5, 1.5));
	add_obj(&world, s);
	s = o_cylinder();
	s.m.specular = 0;
	s.color = set_col(0, 1, 0);
	set_transform(&s.cylinder.mtx, translation_mtrx(-3, -2.5, 0.5) * rotation_z(-M_PI / 3.9));
	add_obj(&world, s);
	return (world);
}

t_scene	scene_aura(t_dim size)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	// Cam
	world.camera.camera = camera(size.x, size.y, M_PI / 2);
	set_transform(&world.camera.camera.mtx, view_transform(set_point(1, 4, 8), set_point(1, 4, 0), set_vec(0, 1, 0)));
	// Ligths
	add_light(&world, o_light(set_point(1, 5, 0), set_col(0, 0, 0.5)));
	add_light(&world, o_light(set_point(3, 6, 0), set_col(0.5, 0, 0)));
	add_light(&world, o_light(set_point(2, 4, 0), set_col(0, 0.5, 0)));
	world.ambient_light = o_light(origin(), set_col(1, 1, 1));
	world.ambient_light.alght.ratio = 0.2;
	s = o_cylinder();
	s.m = material();
	s.m.col = set_col(1, 1, 1);
	s.m.diffuse = 1;
	s.m.specular = 1;
	set_transform(&s.cylinder.mtx, translation_mtrx(1, 3, 0) * rotation_y(M_PI / 2) * rotation_z(M_PI / 2) * scale_mtrx(4, 4, 4));
	add_obj(&world, s);
	return (world);
}

t_scene	scene_cig(t_dim size)
{
	t_scene	world;
	t_obj	s;

	// Init
	world = scene_init();
	// Cam
	world.camera.camera = camera(size.x, size.y, (float)((70.0 / 180.0) * M_PI));
	set_transform(&world.camera.camera.mtx, view_transform(set_point(0, 0, 10), set_point(0, 0, 9), set_vec(0, 1, 0)));
	// Ligths
	add_light(&world, o_light(set_point(0, 10, -10), set_col(1, 1, 1)));
	world.light[0].light.ratio = 0.8;
	world.ambient_light = o_light(origin(), set_col(1, 1, 1));
	world.ambient_light.alght.ratio = 0.2;
	s = o_plane();
	s.color = set_col(125,125,125);
	s.color.tuple /= COL_SCALE;
	set_transform(&s.plane.mtx, translation_mtrx(0, -15, 0) * rotation_x(M_PI));
	add_obj(&world, s);
	s = o_cylinder();
	s.m = material();
	s.m.col = set_col(255, 140, 0);
	s.color.tuple /= COL_SCALE;
	s.cylinder.minimum = -10;
	s.cylinder.maximum = 10;
	s.cylinder.min_caped = true;
	s.cylinder.max_caped = true;
	set_transform(&s.cylinder.mtx, translation_mtrx(-0.5,-5,-33) * scale_mtrx(5, 1, 5));
	add_obj(&world, s);
	s.cylinder.minimum = -20;
	s.cylinder.maximum = 20;
	s.m.col = set_col(220, 220, 220);
	s.color.tuple /= COL_SCALE;
	set_transform(&s.cylinder.mtx, translation_mtrx(-0.5,25,-33) * scale_mtrx(5, 1, 5));
	add_obj(&world, s);
	return (world);
}
