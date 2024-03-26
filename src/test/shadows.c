/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:21:58 by marvin            #+#    #+#             */
/*   Updated: 2024/03/24 10:21:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_unt	test_shadow_light_surface(void)
{
	t_tuple	eyev;
	t_tuple	normalv;
	t_obj	light;
	bool	in_shadow;
	t_color	result;
	t_unt	err;

	scenario_start("Lighting with the surface in shadow");
	given("eyev ← vector(0, 0, -1)", 0);
	given("normalv ← vector(0, 0, -1)", 1);
	given("light ← point_light(point(0, 0, -10), color(1, 1, 1))", 2);
	given("in_shadow ← true", 3);
	eyev = set_vec(0, 0, -1);
	normalv = set_vec(0, 0, -1);
	light = point_light(set_point(0, 0, -10), set_col(1, 1, 1));
	in_shadow = true;
	when("result ← lighting(m, light, position, eyev, normalv, in_shadow)", 0);
	result = lighting((t_lgting){material(), light, origin(), eyev, normalv, in_shadow});
	err = then("result = color(0.1, 0.1, 0.1)", is_same_col(result, set_col(0.1, 0.1, 0.1)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_shadow_point_between(void)
{
	t_unt	err[4];
	t_scene	w;
	t_tuple	p;

	scenario_start("There is no shadow when nothing is collinear with point and light");
	given("w ← default_world()", 0);
	given("p ← point(0, 10, 0)", 1);
	w = default_world();
	p = set_point(0, 10, 0);
	err[0] = then("is_shadowed(w, p) is false", !is_shadowed(w, p, w.light[0]), 0);
	scenario_end(err[0]);
	scenario_start("The shadow when an object is between the point and the light");
	given("w ← default_world()", 0);
	given("p ← point(10, -10, 10)", 1);
	p = set_point(10, -10, 10);
	err[1] = then("is_shadowed(w, p) is true", is_shadowed(w, p, w.light[0]), 0);
	scenario_end(err[1]);
	scenario_start("There is no shadow when an object is behind the light");
	given("w ← default_world()", 0);
	given("p ← point(-20, 20, -20)", 1);
	p = set_point(-20, 20, -20);
	err[2] = then("is_shadowed(w, p) is false", !is_shadowed(w, p, w.light[0]), 0);
	scenario_end(err[2]);
	scenario_start("There is no shadow when an object is behind the point");
	given("w ← default_world()", 0);
	given("p ← point(-2, 2, -2)", 1);
	p = set_point(-2, 2, -2);
	err[3] = then("is_shadowed(w, p) is false", !is_shadowed(w, p, w.light[0]), 0);
	scenario_end(err[3]);
	scene_free(&w);
	return (err[0] + err[1] + err[2] + err[3]);
}

t_unt	test_shade_hit_inter_shadowed(void)
{
	t_unt	err;
	t_scene	w;
	t_obj	s1;
	t_obj	s2;
	t_ray	r;
	t_inter	i;
	t_comps	comps;
	t_color	c;

	scenario_start("shade_hit() is given an intersection in shadow");
	given("w ← world()", 0);
	given("w.light ← point_light(point(0, 0, -10), color(1, 1, 1))", 1);
	w = scene_init();
	add_light(&w, point_light(set_point(0, 0, -10), set_col(1, 1, 1)));
	given("s1 ← sphere()", 2);
	given("s1 is added to w", 3);
	s1 = sphere();
	add_obj(&w, s1);
	given("s2 ← sphere() with:\n\t| transform | translation(0, 0, 10) |", 4);
	given("s2 is added to w", 5);
	s2 = sphere();
	set_transform(&s2, translation_mtrx(0, 0, 10));
	add_obj(&w, s2);
	given("r ← ray(point(0, 0, 5), vector(0, 0, 1))", 6);
	r = ray(set_point(0, 0, 5), set_vec(0, 0, 1));
	given("i ← intersection(4, s2)", 7);
	i = get_inter(4, &s2);
	when("comps ← prepare_computations(i, r)", 0);
	comps = prepare_computations(i, r);
	when("c ← shade_hit(w, comps)", 1);
	c = shade_hit(w, comps);
	err = then("c = color(0.1, 0.1, 0.1)", is_same_col(c, set_col(0.1, 0.1, 0.1)), 0);
	scenario_end(err);
	scene_free(&w);
	return (err);
}

t_unt	test_hit_offset_point(void)
{
	t_unt	err;
	t_ray	r;
	t_obj	shape;
	t_inter	i;
	t_comps	comps;

	scenario_start("The hit should offset the point");
	given("r ← ray(point(0, 0,-5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0,-5), set_vec(0, 0, 1));
	given("shape ← sphere() with:\n\t| transform | translation(0, 0, 1) |", 1);
	shape = sphere();
	set_transform(&shape, translation_mtrx(0, 0, 1));
	given("i ← intersection(5, shape)", 2);
	i = get_inter(5, &shape);
	when("comps ← prepare_computations(i, r)", 0);
	comps = prepare_computations(i, r);
	err = then("comps.over_point.z <-EPSILON/2", comps.over_point.z < -EPSILON / 2, 0);
	err += then("comps.point.z > comps.over_point.z", comps.point.z > comps.over_point.z, 1);
	scenario_end(err);
	return (err);
}
