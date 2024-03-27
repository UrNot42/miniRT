/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:11:49 by marvin            #+#    #+#             */
/*   Updated: 2024/03/24 20:11:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_cube_inters(void)
{
	t_obj	c;
	t_ray	r;
	t_intrs	xs;
	t_unt	err;

	scenario_start("Outline: A ray intersects a cube");
	given("c ← cube()", 0);
	given("r ← ray(<origin>, <direction>)", 1);
	c = o_cube();
	when("xs ← local_intersect(c, r)", 0);
	then("xs.count = 2", 1, 0);
	then("xs[0].t = <t1>", 1, 1);
	then("xs[1].t = <t2>", 1, 2);
	printf("Examples:\n |		| origin		| direction		| t1 | t2 |\n");
	r = ray(set_point(5, 0.5, 0), set_vec(-1, 0, 0));
	xs = cube_intersect(&c, r);
	err = ex(" |  +x		| point(5, 0.5, 0)	| vector(-1, 0, 0)	|  4 |  6 |",
			f_eq(xs.i[0].t, 4) && f_eq(xs.i[1].t, 6) && xs.count == 2);
	r = ray(set_point(-5, 0.5, 0), set_vec(1, 0, 0));
	xs = cube_intersect(&c, r);
	err += ex(" | -x		| point(-5, 0.5, 0)	| vector(1, 0, 0)	|  4 |  6 |",
			f_eq(xs.i[0].t, 4) && f_eq(xs.i[1].t, 6) && xs.count == 2);
	r = ray(set_point(0.5, 5, 0), set_vec(0,-1, 0));
	xs = cube_intersect(&c, r);
	err += ex(" |  +y		| point(0.5, 5, 0)	| vector(0,-1, 0)	|  4 |  6 |",
			f_eq(xs.i[0].t, 4) && f_eq(xs.i[1].t, 6) && xs.count == 2);
	r = ray(set_point(0.5,-5, 0), set_vec(0, 1, 0));
	xs = cube_intersect(&c, r);
	err += ex(" | -y		| point(0.5,-5, 0)	| vector(0, 1, 0)	|  4 |  6 |",
			f_eq(xs.i[0].t, 4) && f_eq(xs.i[1].t, 6) && xs.count == 2);
	r = ray(set_point(0.5, 0, 5), set_vec(0, 0,-1));
	xs = cube_intersect(&c, r);
	err += ex(" |  +z		| point(0.5, 0, 5)	| vector(0, 0,-1)	|  4 |  6 |",
			f_eq(xs.i[0].t, 4) && f_eq(xs.i[1].t, 6) && xs.count == 2);
	r = ray(set_point(0.5, 0,-5), set_vec(0, 0, 1));
	xs = cube_intersect(&c, r);
	err += ex(" | -z		| point(0.5, 0,-5)	| vector(0, 0, 1)	|  4 |  6 |",
			f_eq(xs.i[0].t, 4) && f_eq(xs.i[1].t, 6) && xs.count == 2);
	r = ray(set_point(0, 0.5, 0), set_vec(0, 0, 1));
	xs = cube_intersect(&c, r);
	err += ex(" | inside	| point(0, 0.5, 0)	| vector(0, 0, 1)	| -1 |  1 |",
			f_eq(xs.i[0].t, -1) && f_eq(xs.i[1].t, 1) && xs.count == 2);
	scenario_end(err);
	return (err);
}

t_unt	test_cube_normal(void)
{
	t_obj	c;
	t_tuple	p;
	t_tuple	normal;
	t_unt	err;

	scenario_start("Outline: The normal on the surface of a cube");
	given("c ← cube()", 0);
	given("p ← <point>", 1);
	c = o_cube();
	when("normal ← local_normal_at(c, p)", 0);
	then("normal = <normal>", 1, 0);
	printf("Examples:\n | point			| normal		|\n");

	p = set_point(1,  0.5, -0.8);
	normal = normal_at(c, p);
	err = ex(" | point( 1,  0.5, -0.8)	| vector(1,  0,  0)	|",
			is_same_tuple(normal, set_vec(1,  0,  0)));

	p = set_point(-1, -0.2,  0.9);
	normal = normal_at(c, p);
	err += ex(" | point(-1, -0.2,  0.9)	| vector(-1, 0,  0)	|",
			is_same_tuple(normal, set_vec(-1, 0,  0)));

	p = set_point(-0.4,  1, -0.1);
	normal = normal_at(c, p);
	err += ex(" | point(-0.4,  1, -0.1)	| vector(0,  1,  0)	|",
			is_same_tuple(normal, set_vec(0,  1,  0)));

	p = set_point( 0.3, -1, -0.7);
	normal = normal_at(c, p);
	err += ex(" | point( 0.3, -1, -0.7)	| vector(0, -1,  0)	|",
			is_same_tuple(normal, set_vec(0, -1,  0)));

	p = set_point(-0.6, 0.3,   1);
	normal = normal_at(c, p);
	err += ex(" | point(-0.6, 0.3,   1)	| vector(0,  0,  1)	|",
			is_same_tuple(normal, set_vec(0,  0,  1)));

	p = set_point(0.4,  0.4,  -1);
	normal = normal_at(c, p);
	err += ex(" | point(0.4,  0.4,  -1)	| vector(0,  0, -1)	|",
			is_same_tuple(normal, set_vec(0,  0, -1)));

	p = set_point(  1,    1,   1);
	normal = normal_at(c, p);
	err += ex(" | point(  1,    1,   1)	| vector(1,  0,  0)	|",
			is_same_tuple(normal, set_vec(1,  0,  0)));

	p = set_point( -1,   -1,  -1);
	normal = normal_at(c, p);
	err += ex(" | point( -1,   -1,  -1)	| vector(-1, 0,  0)	|",
			is_same_tuple(normal, set_vec(-1, 0,  0)));

	scenario_end(err);
	return (err);
}
