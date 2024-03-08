/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:22 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 18:13:10 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_tuple(void)
{
	t_tuple	a;
	t_unt	err;

	scenario_start("A tuple with w=1.0 is a point");
	given("a ← tuple(4.3, -4.2, 3.1, 1.0)", 0);
	a = set_tuple((t_tuple){4.3, -4.2, 3.1, 1.0});
	err = test_print("a.x = 4.3", f_eq(a.x, 4.3));
	err += test_print("a.y = -4.2", f_eq(a.y, -4.2));
	err += test_print("a.z = 3.1", f_eq(a.z, 3.1));
	err += test_print("a.w = 1.0", f_eq(a.w, 1.0));
	err += test_print("a is point", is_point(a));
	err += test_print("a is not vector", !is_vec(a));
	scenario_end(err);

	return (err);
}

t_unt	test_point_vec(void)
{
	t_tuple	p;
	t_tuple	v;
	t_unt	err[2];

	scenario_start("point() creates tuples with w=1");
	given("p ← point(4, -4, 3)", 0);
	p = set_point((t_pos){4, -4, 3});
	err[0] = test_print("p = tuple(4, -4, 3, 1)",
			is_same_tuple(p, (t_tuple){4, -4, 3, 1}));
	scenario_end(err[0]);

	scenario_start("vector() creates tuples with w=0");
	given("v ← vector(4, -4, 3)", 0);
	v = set_vec((t_pos){4, -4, 3});
	err[1] = test_print("v = tuple(4, -4, 3, 0)",
			is_same_tuple(v, (t_tuple){4, -4, 3, 0}));
	scenario_end(err[1]);

	return (err[0] + err[1]);
}

t_unt	test_tuple_add(void)
{
	t_tuple	a1;
	t_tuple	a2;
	t_unt	err;

	scenario_start("Adding two tuples");
	given("a1 ← tuple(3, -2, 5, 1)", 0);
	given("a2 ← tuple(-2, 3, 1, 0)", 1);
	a1 = set_tuple((t_tuple){3, -2, 5, 1});
	a2 = set_tuple((t_tuple){-2, 3, 1, 0});
	err = test_print("a1 + a2 = tuple(1, 1, 6, 1)",
			is_same_tuple(tup_add(a1, a2), (t_tuple){1, 1, 6, 1}));
	scenario_end(err);

	return (err);
}

t_unt	test_sub_pts(void)
{
	t_tuple	p1;
	t_tuple	p2;
	t_unt	err;

	scenario_start("Subtracting two points");
	given("p1 ← point(3, 2, 1)", 0);
	given("p2 ← point(5, 6, 7)", 1);
	p1 = set_point((t_pos){3, 2, 1});
	p2 = set_point((t_pos){5, 6, 7});
	err = test_print("p1 - p2 = vector(-2, -4, -6)",
			is_same_tuple(tup_sub(p1, p2), set_vec((t_pos){-2, -4, -6})));
	scenario_end(err);

	return (err);
}

t_unt	test_sub_pt_vec(void)
{
	t_tuple	p;
	t_tuple	v;
	t_tuple	result;
	t_tuple	expected;
	t_unt	err;

	scenario_start("Subtracting a vector from a point");
	given("p ← point(3, 2, 1)", 0);
	given("v ← vector(5, 6, 7)", 1);
	p = set_point((t_pos){3, 2, 1});
	v = set_vec((t_pos){5, 6, 7});
	result = tup_sub(p, v);
	expected = set_point((t_pos){-2, -4, -6});
	err = test_print("p - v = point(-2, -4, -6)",
			is_same_tuple(result, expected));
	scenario_end(err);

	return (err);
}

t_unt	test_sub_vects(void)
{
	t_tuple	v1;
	t_tuple	v2;
	t_tuple	result;
	t_tuple	expected;
	t_unt	err;

	scenario_start("Subtracting two vectors");
	given("v1 ← vector(3, 2, 1)", 0);
	given("v2 ← vector(5, 6, 7)", 1);
	v1 = set_vec((t_pos){3, 2, 1});
	v2 = set_vec((t_pos){5, 6, 7});
	result = tup_sub(v1, v2);
	expected = set_vec((t_pos){-2, -4, -6});
	err = test_print("v1 - v2 = vector(-2, -4, -6)",
			is_same_tuple(result, expected));
	scenario_end(err);

	return (err);
}

t_unt	test_sub_zero_vec(void)
{
	t_tuple	zero;
	t_tuple	v;
	t_tuple	result;
	t_tuple	expected;
	t_unt	err;

	scenario_start("Subtracting a vector from the zero vector");
	given("zero ← vector(0, 0, 0)", 0);
	given("v ← vector(1, -2, 3)", 0);
	zero = set_vec((t_pos){0, 0, 0});
	v = set_vec((t_pos){1, -2, 3});
	result = tup_sub(zero, v);
	expected = set_vec((t_pos){-1, 2, -3});
	err = test_print("zero - v = vector(-1, 2, -3)",
			is_same_tuple(result, expected));
	scenario_end(err);

	return (err);
}

t_unt	test_neg_tuple(void)
{
	t_tuple	a;
	t_tuple	result;
	t_tuple	expected;
	t_unt	err;

	scenario_start("Negating a tuple");
	given("a ← tuple(1, -2, 3, -4)", 0);
	a = set_tuple((t_tuple){1, -2, 3, -4});
	expected = set_tuple((t_tuple){-1, 2, -3, 4});
	result = tup_neg(a);
	err = test_print("-a = tuple(-1, 2, -3, 4)",
			is_same_tuple(result, expected));
	scenario_end(err);

	return (err);
}

t_unt	test_multiply_tuple(void)
{
	t_tuple	a;
	t_tuple	result;
	t_unt	err[2];

	scenario_start("Multiplying a tuple by a scalar");
	given("a ← tuple(1, -2, 3, -4)", 0);
	a = set_tuple((t_tuple){1, -2, 3, -4});
	result = tup_scale(a, 3.5);
	err[0] = test_print("a * 3.5 = tuple(3.5, -7, 10.5, -14)",
			is_same_tuple(result, (t_tuple){3.5, -7, 10.5, -14}));
	scenario_end(err[0]);

	scenario_start("Multiplying a tuple by a fraction");
	given("a ← tuple(1, -2, 3, -4)", 0);
	a = set_tuple((t_tuple){1, -2, 3, -4});
	result = tup_scale(a, 0.5);
	err[1] = test_print("a * 0.5 = tuple(0.5, -1, 1.5, -2)",
			is_same_tuple(result, (t_tuple){0.5, -1, 1.5, -2}));
	scenario_end(err[1]);

	return (err[0] + err[1]);
}

t_unt	test_divide_tuple(void)
{
	t_tuple	a;
	t_tuple	result;
	t_unt	err;

	scenario_start("Dividing a tuple by a scalar");
	given("a ← tuple(1, -2, 3, -4)", 0);
	a = set_tuple((t_tuple){1, -2, 3, -4});
	result = tup_div(a, 2);
	err = test_print("a / 2 = tuple(0.5, -1, 1.5, -2)",
			is_same_tuple(result, (t_tuple){0.5, -1, 1.5, -2}));
	scenario_end(err);

	return (err);
}
