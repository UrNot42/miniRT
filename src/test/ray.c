/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:09:04 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/12 11:15:29 by ulevallo         ###   ########.fr       */
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
	t_hit	xs;
	t_unt	err;

	scenario_start("A ray intersects a sphere at two points");
	given("r ← ray(point(0, 0, -5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0, -5), set_vec(0, 0, 1));
	given("s ← sphere()", 1);
	s = sphere();
	when("xs ← intersect(s, r)", 0);
	xs = intersect(s, r);
	err = then("xs.count = 2", xs.count == 2, 0);
	err += then("xs[0] = 4.0", f_eq(xs.t[0], 4), 1);
	err += then("xs[1] = 6.0", f_eq(xs.t[1], 6), 2);
	scenario_end(err);
	return (err);
}

t_unt	test_sphere_tangent(void)
{
	t_ray	r;
	t_obj	*s;
	t_hit	xs;
	t_unt	err;

	scenario_start("A ray intersects a sphere at a tangent");
	given("r ← ray(point(0, 1, -5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 1, -5), set_vec(0, 0, 1));
	given("s ← sphere()", 1);
	s = sphere();
	when("xs ← intersect(s, r)", 0);
	xs = intersect(s, r);
	err = then("xs.count = 2", xs.count == 2, 0);
	err += then("xs[0] = 4.0", f_eq(xs.t[0], 5), 1);
	err += then("xs[1] = 6.0", f_eq(xs.t[1], 5), 2);
	scenario_end(err);
	return (err);
}

t_unt	test_ray_miss_sphere(void)
{
	t_ray	r;
	t_obj	*s;
	t_hit	xs;
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
	t_hit	xs;
	t_unt	err;

	scenario_start("A ray originates inside a sphere");
	given("r ← ray(point(0, 0, 0), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0, 0), set_vec(0, 0, 1));
	given("s ← sphere()", 1);
	s = sphere();
	when("xs ← intersect(s, r)", 0);
	xs = intersect(s, r);
	err = then("xs.count = 2", xs.count == 2, 0);
	err += then("xs[0] = 4.0", f_eq(xs.t[0], -1), 1);
	err += then("xs[1] = 6.0", f_eq(xs.t[1], 1), 2);
	scenario_end(err);
	return (err);
}

t_unt	test_sphere_behind_ray(void)
{
	t_ray	r;
	t_obj	*s;
	t_hit	xs;
	t_unt	err;

	scenario_start("A sphere is behind a ray");
	given("r ← ray(point(0, 0, 5), vector(0, 0, 1))", 0);
	r = ray(set_point(0, 0, 5), set_vec(0, 0, 1));
	given("s ← sphere()", 1);
	s = sphere();
	when("xs ← intersect(s, r)", 0);
	xs = intersect(s, r);
	err = then("xs.count = 2", xs.count == 2, 0);
	err += then("xs[0] = 4.0", f_eq(xs.t[0], -6), 1);
	err += then("xs[1] = 6.0", f_eq(xs.t[1], -4), 2);
	scenario_end(err);
	return (err);
}
