/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:09:04 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/12 17:50:13 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_creating_ray(void)
{
	t_tuple	origin;
	t_tuple	direction;
	t_ray	r;
	t_unt	err;

	scenario_start("Creating and querying a ray");
	given("origin ← point(1, 2, 3)", 0);
	origin = set_point(1, 2, 3);
	given("direction ← vector(4, 5, 6)", 1);
	direction = set_vec(4, 5, 6);
	when("r ← ray(origin, direction)", 0);
	r = ray(origin, direction);
	err = then("r.origin = origin", is_same_tuple(r.origin, origin), 0);
	err += then("r.direction = direction",
			is_same_tuple(r.direction, direction), 1);
	scenario_end(err);
	return (err);
}

t_unt	test_position_ray(void)
{
	t_ray	r;
	t_unt	err;

	scenario_start("Computing a point from a distance");
	given("r ← ray(point(2, 3, 4), vector(1, 0, 0))", 0);
	r = ray(set_point(2, 3, 4), set_vec(1, 0, 0));
	err = then("position(r, 0) = point(2, 3, 4)",
			is_same_tuple(position(r, 0), set_point(2, 3, 4)), 0);
	err += then("position(r, 1) = point(3, 3, 4)",
			is_same_tuple(position(r, 1), set_point(3, 3, 4)), 1);
	err += then("position(r, -1) = point(1, 3, 4)",
			is_same_tuple(position(r, -1), set_point(1, 3, 4)), 2);
	err += then("position(r, 2.5) = point(4.5, 3, 4)",
			is_same_tuple(position(r, 2.5), set_point(4.5, 3, 4)), 2);
	scenario_end(err);
	return (err);
}

t_unt	test_intersect_sphere(void)
{
	t_ray	r;
	t_obj	*s;
	t_intrs	xs;
	t_unt	err;

	scenario_start("A ray intersects a sphere at two points");
	given("r ← ray(point(0, 0, -5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0, -5), set_vec(0, 0, 1));
	given("s ← sphere()", 1);
	s = sphere();
	when("xs ← intersect(s, r)", 0);
	xs = intersect(s, r);
	err = then("xs.count = 2", xs.count == 2, 0);
	err += then("xs[0] = 4.0", f_eq(xs.i[0].t, 4), 1);
	err += then("xs[1] = 6.0", f_eq(xs.i[1].t, 6), 2);
	scenario_end(err);
	return (err);
}

t_unt	test_sphere_tangent(void)
{
	t_ray	r;
	t_obj	*s;
	t_intrs	xs;
	t_unt	err;

	scenario_start("A ray intersects a sphere at a tangent");
	given("r ← ray(point(0, 1, -5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 1, -5), set_vec(0, 0, 1));
	given("s ← sphere()", 1);
	s = sphere();
	when("xs ← intersect(s, r)", 0);
	xs = intersect(s, r);
	err = then("xs.count = 2", xs.count == 2, 0);
	err += then("xs[0] = 4.0", f_eq(xs.i[0].t, 5), 1);
	err += then("xs[1] = 6.0", f_eq(xs.i[1].t, 5), 2);
	scenario_end(err);
	return (err);
}

t_unt	test_ray_miss_sphere(void)
{
	t_ray	r;
	t_obj	*s;
	t_intrs	xs;
	t_unt	err;

	scenario_start("A ray misses a sphere");
	given("r ← ray(point(0, 2, -5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 2, -5), set_vec(0, 0, 1));
	given("s ← sphere()", 1);
	s = sphere();
	when("xs ← intersect(s, r)", 0);
	xs = intersect(s, r);
	err = then("xs.count = 0", xs.count == 0, 0);
	scenario_end(err);
	return (err);
}

t_unt	test_ray_inside_sphere(void)
{
	t_ray	r;
	t_obj	*s;
	t_intrs	xs;
	t_unt	err;

	scenario_start("A ray originates inside a sphere");
	given("r ← ray(point(0, 0, 0), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0, 0), set_vec(0, 0, 1));
	given("s ← sphere()", 1);
	s = sphere();
	when("xs ← intersect(s, r)", 0);
	xs = intersect(s, r);
	err = then("xs.count = 2", xs.count == 2, 0);
	err += then("xs[0] = 4.0", f_eq(xs.i[0].t, -1), 1);
	err += then("xs[1] = 6.0", f_eq(xs.i[1].t, 1), 2);
	scenario_end(err);
	return (err);
}

t_unt	test_sphere_behind_ray(void)
{
	t_ray	r;
	t_obj	*s;
	t_intrs	xs;
	t_unt	err;

	scenario_start("A sphere is behind a ray");
	given("r ← ray(point(0, 0, 5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0, 5), set_vec(0, 0, 1));
	given("s ← sphere()", 1);
	s = sphere();
	when("xs ← intersect(s, r)", 0);
	xs = intersect(s, r);
	err = then("xs.count = 2", xs.count == 2, 0);
	err += then("xs[0] = 4.0", f_eq(xs.i[0].t, -6), 1);
	err += then("xs[1] = 6.0", f_eq(xs.i[1].t, -4), 2);
	scenario_end(err);
	return (err);
}

t_unt	test_inter_struct(void)
{
	t_obj	*s;
	t_inter	i;
	t_unt	err;

	scenario_start("An intersection encapsulates t and object");
	given("s ← sphere()", 0);
	s = sphere();
	when("i ← intersection(3.5, s)", 0);
	i = intersection(3.5, s);
	err = then("i.t = 3.5", f_eq(i.t, 3.5), 0);
	err += then("i.object = s", i.obj == s, 1);
	scenario_end(err);
	return (err);
}

t_unt	test_agregating_inter(void)
{
	t_intrs	xs;
	t_obj	*s;
	t_inter	i[2];
	t_unt	err;

	scenario_start("Aggregating intersections");
	given("s ← sphere()", 0);
	s = sphere();
	given("i ← intersection(1, s)", 0);
	i[0] = intersection(1, s);
	given("i ← intersection(2, s)", 1);
	i[1] = intersection(2, s);
	when("xs ← intersections(i1, i2)", 0);
	xs = intersections(2, (t_inter[2]){i[0], i[1]});
	err = then("xs.count = 2", xs.count == 2, 0);
	err += then("xs[0].t = 1", f_eq(xs.i[0].t, 1), 1);
	err += then("xs[1].t = 2", f_eq(xs.i[1].t, 2), 2);
	scenario_end(err);
	return (err);
}

t_unt	test_intersect_obj(void)
{
	t_obj	*s;
	t_ray	r;
	t_intrs	xs;
	t_unt	err;

	scenario_start("Intersect sets the object on the intersection");
	given("r ← ray(point(0, 0, -5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0, -5), set_vec(0, 0, 1));
	given("s ← sphere()", 1);
	s = sphere();
	when("xs ← intersect(s, r)", 0);
	xs = intersect(s, r);
	err = then("xs.count = 2", xs.count == 2, 0);
	err += then("xs[0].object = 1", xs.i[0].obj == s, 1);
	err += then("xs[1].object = 2", xs.i[1].obj == s, 2);
	scenario_end(err);
	return (err);
}

t_unt	test_hits(void)
{
	t_obj	*s;
	t_intrs	xs;
	t_inter	i[4];
	t_inter	hit;
	t_unt	err[4];

	s = sphere();
	scenario_start("The hit, when all intersections have positive t");
	given("s ← sphere()", 0);
	given("i1 ← intersection(1, s)", 1);
	i[0] = intersection(1, s);
	given("i2 ← intersection(2, s)", 2);
	i[1] = intersection(2, s);
	given("xs ← intersections(i2, i1)", 3);
	xs = intersections(2, (t_inter[2]){i[0], i[1]});
	when("i ← hit(xs)", 0);
	hit = find_hit(xs);
	err[0] = then("i = i1", is_same_inter(hit, i[0]), 0);
	scenario_end(err[0]);

	scenario_start("The hit, when some intersections have negative t");
	given("s ← sphere()", 0);
	given("i1 ← intersection(-1, s)", 1);
	i[0] = intersection(-1, s);
	given("i2 ← intersection(1, s)", 2);
	i[1] = intersection(1, s);
	given("xs ← intersections(i2, i1)", 3);
	xs = intersections(2, (t_inter[2]){i[0], i[1]});
	when("i ← hit(xs)", 0);
	hit = find_hit(xs);
	err[1] = then("i = i2", is_same_inter(hit, i[1]), 0);
	scenario_end(err[1]);

	scenario_start("The hit, when all intersections have negative t");
	given("s ← sphere()", 0);
	given("i1 ← intersection(-2, s)", 1);
	i[0] = intersection(-2, s);
	given("i2 ← intersection(-1, s)", 2);
	i[1] = intersection(-1, s);
	given("xs ← intersections(i2, i1)", 3);
	xs = intersections(2, (t_inter[2]){i[0], i[1]});
	when("i ← hit(xs)", 0);
	hit = find_hit(xs);
	err[2] = then("i is nothing", !hit.def, 0);
	scenario_end(err[2]);

	scenario_start("The hit is always the lowest nonnegative intersection");
	given("s ← sphere()", 0);
	given("i1 ← intersection(5, s)", 1);
	i[0] = intersection(5, s);
	given("i2 ← intersection(7, s)", 2);
	i[1] = intersection(7, s);
	given("i3 ← intersection(-3, s)", 2);
	i[2] = intersection(-3, s);
	given("i4 ← intersection(2, s)", 2);
	i[3] = intersection(2, s);
	given("xs ← intersections(i1, i2, i3, i4)", 3);
	xs = intersections(4, (t_inter[4]){i[0], i[1], i[2], i[3]});
	when("i ← hit(xs)", 0);
	hit = find_hit(xs);
	err[3] = then("i = i4", hit.t == i[3].t, 0);
	scenario_end(err[3]);
	return (err[0] + err[1] + err[2] + err[3]);
}

/*
Scenario:
Given
And
When
Then
And
*/

t_unt	test_translate_ray(void)
{
	t_ray	r[2];
	t_4mtrx	m;
	t_unt	err[2];

	scenario_start("Translating a ray");
	given("r ← ray(point(1, 2, 3), vector(0, 1, 0))", 0);
	r[0] = ray(set_point(1, 2, 3), set_vec(0, 1, 0));
	given("m ← translation(3, 4, 5)", 1);
	m = translation_mtrx(3, 4, 5);
	when("r2 ← transform(r, m)", 0);
	r[1] = ray_transform(r[0], m);
	err[0] = then("r2.origin = point(4, 6, 8)",
			is_same_tuple(r[1].origin, set_point(4, 6, 8)), 0);
	err[0] += then("r2.direction = vector(0, 1, 0)",
			is_same_tuple(r[1].direction, set_vec(0, 1, 0)), 1);
	scenario_end(err[0]);

	scenario_start("Scaling a ray");
	given("r ← ray(point(1, 2, 3), vector(0, 1, 0))", 0);
	given("m ← scaling(2, 3, 4)", 1);
	m = scale_mtrx(2, 3, 4);
	when("r2 ← transform(r, m)", 0);
	r[1] = ray_transform(r[0], m);
	err[1] = then("r2.origin = point(2, 6, 12)",
			is_same_tuple(r[1].origin, set_point(2, 6, 12)), 0);
	err[1] += then("r2.direction = vector(0, 3, 0)",
			is_same_tuple(r[1].direction, set_vec(0, 3, 0)), 1);
	scenario_end(err[1]);
	return (err[0] + err[1]);
}

t_unt	test_sphere_transformation(void)
{
	t_obj	*s;
	t_4mtrx	t;
	t_unt	err[2];

	scenario_start("A sphere's default transformation");
	given("s ← sphere()", 0);
	s = sphere();
	err[0] = then("s.transform = identity_matrix",
			matr_4_eq(s->transform, get_id4mtrx()), 0);
	scenario_end(err[0]);
	scenario_start("Changing a sphere's transformation");
	given("s ← sphere()", 0);
	given("t ← translation(2, 3, 4)", 1);
	t = translation_mtrx(2, 3, 4);
	s->transform = t;
	when("set_transform(s, t)", 0);
	set_transform(s, t);
	err[1] = then("s.transform = t", matr_4_eq(s->transform, t), 0);
	scenario_end(err[1]);
	return (err[0] + err[1]);
}

t_unt	test_ray_sphere_transform(void)
{
	t_obj	*s;
	t_ray	r;
	t_intrs	xs;
	t_unt	err[2];

	scenario_start("Intersecting a scaled sphere with a ray");
	given("r ← ray(point(0, 0, -5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0, -5), set_vec(0, 0, 1));
	given("s ← sphere()", 1);
	s = sphere();
	when("set_transform(s, scaling(2, 2, 2))", 0);
	set_transform(s, scale_mtrx(2, 2, 2));
	when("xs ← intersect(s, r)", 1);
	xs = intersect(s, r);
	err[0] = then("xs.count = 2", xs.count == 2, 0);
	err[0] += then("xs[0].t = 3", f_eq(xs.i[0].t, 3), 0);
	err[0] += then("xs[1].t = 7", f_eq(xs.i[1].t, 7), 0);
	scenario_end(err[0]);

	scenario_start("Intersecting a translated sphere with a ray");
	given("r ← ray(point(0, 0, -5), vector(0, 0, 1))", 0);
	given("s ← sphere()", 1);
	when("set_transform(s, translation(5, 0, 0))", 0);
	s->transform = translation_mtrx(5, 0, 0);
	when("xs ← intersect(s, r)", 1);
	xs = intersect(s, r);
	err[1] = then("xs.count = 0", xs.count == 0, 0);
	scenario_end(err[1]);
	return (err[0] + err[1]);
}
