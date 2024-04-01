/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:59:14 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/01 19:00:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_precomputation(void)
{
	t_ray	r;
	t_inter	i;
	t_obj	shape;
	t_comps	comps;
	t_unt	err;

	scenario_start("Precomputing the state of an intersection");
	given("r ← ray(point(0, 0, -5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0, -5), set_vec(0, 0, 1));
	given("shape ← sphere()", 1);
	shape = o_sphere();
	given("i ← intersection(4, shape)", 2);
	i = get_inter(4, &shape);
	when("comps ← prepare_computations(i, r)", 0);
	comps = prepare_computations(i, r);
	err = then("comps.t = i.t", f_eq(comps.t, i.t), 0);
	err += then("comps.object = i.object", comps.obj == i.obj, 1);
	err += then("comps.point = point(0, 0, -1)",
			is_same_tuple(comps.point, set_point(0, 0, -1)), 2);
	err += then("comps.eyev = vector(0, 0, -1)",
			is_same_tuple(comps.eyev, set_vec(0, 0, -1)), 3);
	err += then("comps.normalv = vector(0, 0, -1)",
			is_same_tuple(comps.normalv, set_vec(0, 0, -1)), 4);
	scenario_end(err);
	return (err);
}

t_unt	test_hit_inoutside(void)
{
	t_ray	r;
	t_inter	i;
	t_obj	shape;
	t_comps	comps;
	t_unt	err[2];

	scenario_start("The hit, when an intersection occurs on the outside");
	given("r ← ray(point(0, 0, -5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0, -5), set_vec(0, 0, 1));
	given("shape ← sphere()", 1);
	shape = o_sphere();
	given("i ← intersection(4, shape)", 2);
	i = get_inter(4, &shape);
	when("comps ← prepare_computations(i, r)", 0);
	comps = prepare_computations(i, r);
	err[0] = then("comps.inside = false", comps.inside == false, 0);
	scenario_end(err[0]);
	scenario_start("The hit, when an intersection occurs on the inside");
	given("r ← ray(point(0, 0, 0), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0, 0), set_vec(0, 0, 1));
	given("shape ← sphere()", 1);
	shape = o_sphere();
	given("i ← intersection(1, shape)", 2);
	i = get_inter(1, &shape);
	when("comps ← prepare_computations(i, r)", 0);
	comps = prepare_computations(i, r);
	err[1] = then("comps.point = point(0, 0, 1)",
			is_same_tuple(comps.point, set_point(0, 0, 1)), 0);
	err[1] += then("comps.eyev = vector(0, 0, -1)",
			is_same_tuple(comps.eyev, set_vec(0, 0, -1)), 1);
	err[1] += then("comps.inside = true", comps.inside == true, 2);
	err[1] += then("comps.normalv = vector(0, 0, -1)",
			is_same_tuple(comps.normalv, set_vec(0, 0, -1)), 3);
	scenario_end(err[1]);
	return (err[0] + err[1]);
}

t_unt	test_shading_w_precomps(void)
{
	t_scene	w;
	t_ray	r;
	t_obj	shape;
	t_inter	i;
	t_comps	comps;
	t_color	c;
	t_unt	err[2];

	scenario_start("Shading an intersection");
	given("w ← default_world()", 0);
	w = default_world();
	given("r ← ray(point(0, 0, -5), vector(0, 0, 1))", 1);
	r = ray(set_point(0, 0, -5), set_vec(0, 0, 1));
	given("shape ← the first object in w", 2);
	shape = w.objects[0];
	given("i ← intersection(4, shape)", 3);
	i = get_inter(4, &shape);
	when("comps ← prepare_computations(i, r)", 0);
	comps = prepare_computations(i, r);
	when("c ← shade_hit(w, comps)", 1);
	c = shade_hit(w, comps);
	err[0] = then("c = color(0.38066, 0.47583, 0.2855)",
			is_same_col(c, set_col(0.38066, 0.47583, 0.2855)), 0);
	scenario_end(err[0]);

	scenario_start("Shading an intersection from the inside");
	given("w ← default_world()", 0);
	given("w.light ← point_light(point(0, 0.25, 0), color(1, 1, 1))", 1);
	w.light[0] = o_light(set_point(0, 0.25, 0), set_col(1, 1, 1));
	given("r ← ray(point(0, 0, 0), vector(0, 0, 1))", 2);
	r = ray(origin(), set_vec(0, 0, 1));
	given("shape ← the second object in w", 3);
	shape = w.objects[1];
	given("i ← intersection(0.5, shape)", 4);
	i = get_inter(0.5, &shape);
	when("comps ← prepare_computations(i, r)", 0);
	comps = prepare_computations(i, r);
	when("c ← shade_hit(w, comps)", 1);
	c = shade_hit(w, comps);
	err[1] = then("c = color(0.90498, 0.90498, 0.90498)",
			is_same_col(c, set_col(0.90498, 0.90498, 0.90498)), 0);
	scenario_end(err[1]);
	scene_free(&w);
	return (err[0] + err[1]);
}

t_unt	test_color_at(void)
{
	t_scene	w;
	t_ray	r;
	t_color	c;
	t_unt	err[2];

	scenario_start("The color when a ray misses");
	given("w ← default_world()", 0);
	w = default_world();
	given("r ← ray(point(0, 0, -5), vector(0, 1, 0))", 1);
	r = ray(set_point(0, 0, -5), set_vec(0, 1, 0));
	when("c ← color_at(w, r)", 0);
	c = color_at(w, r);
	err[0] = then("c = color(0, 0, 0)", is_same_col(c, set_col(0, 0, 0)), 0);
	scenario_end(err[0]);
	scenario_start("The color when a ray hits");
	given("w ← default_world()", 0);
	given("r ← ray(point(0, 0, -5), vector(0, 0, 1))", 1);
	r = ray(set_point(0, 0, -5), set_vec(0, 0, 1));
	when("c ← color_at(w, r)", 0);
	c = color_at(w, r);
	err[1] = then("c = color(0.38066, 0.47583, 0.2855)",
			is_same_col(c, set_col(0.38066, 0.47583, 0.2855)), 0);
	scenario_end(err[1]);
	scene_free(&w);
	return (err[0] + err[1]);
}

t_unt	test_color_behind(void)
{
	t_scene	w;
	t_ray	r;
	t_obj	*outer;
	t_obj	*inner;
	t_color	c;
	t_unt	err;

	scenario_start("The color with an intersection behind the ray");
	given("w ← default_world()", 0);
	w = default_world();
	given("outer ← the first object in w", 1);
	outer = &w.objects[0];
	given("outer.material.ambient ← 1", 2);
	outer->m.ambient = 1;
	given("inner ← the second object in w", 3);
	inner = &w.objects[1];
	given("inner.material.ambient ← 1", 4);
	inner->m.ambient = 1;
	given("r ← ray(point(0, 0, 0.75), vector(0, 0, -1))", 5);
	r = ray(set_point(0, 0, 0.75), set_vec(0, 0, -1));
	when("c ← color_at(w, r)", 0);
	c = color_at(w, r);
	err = then("c = inner.material.color", is_same_tuple(c.tuple, inner->m.col.tuple), 0);
	scenario_end(err);
	scene_free(&w);
	return (err);
}
