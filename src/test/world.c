/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:26:49 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/23 11:29:25 by marvin           ###   ########.fr       */
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

t_unt	test_world_default(void)
{
	t_unt	err;
	t_obj	s1;
	t_obj	s2;
	t_obj	light;
	t_scene	w;

	(void)w;
	scenario_start("The default world");
	given("light ← point_light(point(-10, 10, -10), color(1, 1, 1))", 0);
	light = point_light(set_point(-10, 10, -10), set_col(1, 1, 1));
	given("s1 ← sphere() with:\n| material.color    |        (0.8, 1.0, 0.6) |\n\
| material.diffuse  |                    0.7 |\n\
| material.specular |                    0.2 |", 1);
	s1 = sphere();
	s1 = (t_obj){.m.col = set_col(0.8, 1.0, 0.6), .m.diffuse = 0.7,
		.m.specular = 0.2};
	given("s2 ← sphere() with:\n| transform         | scaling(0.5, 0.5, 0.5) |",
		2);
	s2 = sphere();
	set_transform(&s2, scale_mtrx(0.5, 0.5, 0.5));
	w = default_world();
	when("w ← default_world()", 0);
	err = then("w.light = light", is_same_tuple(w.light[0].pos,
				light.pos) && is_same_tuple(w.light[0].m.col.tuple,
				light.m.col.tuple), 0);
	err += then("w contains s1", is_same_col(w.objects[0].m.col, s1.m.col), 1);
	err += then("w contains s2", matr_4_eq(w.objects[1].transform, s2.transform), 2);
	scenario_end(err);
	return (err);
}

t_unt	test_inter_world(void)
{
	t_intrs	xs;
	t_scene	w;
	t_ray	r;
	t_unt	err;

	scenario_start("Intersect a world with a ray");
	given("w ← default_world()", 0);
	w = default_world();
	given("r ← ray(point(0, 0, -5), vector(0, 0, 1))", 1);
	r = ray(set_point(0, 0, -5), set_vec(0, 0, 1));
	when("xs ← intersect_world(w, r)", 0);
	xs = intersect_world(w, r);
	err = then("xs.count = 4", xs.count == 4, 0);
	err += then("xs[0].t = 4", f_eq(xs.i[0].t, 4), 1);
	err += then("xs[1].t = 4.5", f_eq(xs.i[1].t, 4.5), 2);
	err += then("xs[2].t = 5.5", f_eq(xs.i[2].t, 5.5), 3);
	err += then("xs[3].t = 6", f_eq(xs.i[3].t, 6), 4);
	scenario_end(err);
	return (err);
}
