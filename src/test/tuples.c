/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:22 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 16:12:35 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	launch_tup_pts_vec_test(void)
{
	t_unt	err;

	err = test_tuple();
	err += test_point_vec();
	err += test_tuple_add();
	err += test_sub_pts();
	err += test_sub_pt_vec();
	err += test_sub_vects();
	err += test_sub_zero_vec();
	err += test_neg_tuple();
	ft_printf("==> Finished Tuple_tests with %d Errors ", err);
	if (err)
		ft_printf("[OK]\n");
	else
		ft_printf("[KO]\n");
	return (err);
}

bool	test_tuple(void)
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

bool	test_point_vec(void)
{
	t_tuple	p;
	t_tuple	v;
	t_unt	err;
	t_unt	err_2;

	scenario_start("point() creates tuples with w=1");
	given("p ← point(4, -4, 3)", 0);
	p = set_point((t_pos){4, -4, 3});
	err = test_print("p = tuple(4, -4, 3, 1)",
			is_same_tuple(p, (t_tuple){4, -4, 3, 1}));
	scenario_end(err);
	scenario_start("vector() creates tuples with w=0");
	given("v ← vector(4, -4, 3)", 0);
	v = set_vec((t_pos){4, -4, 3});
	err_2 = test_print("v = tuple(4, -4, 3, 0)",
			is_same_tuple(v, (t_tuple){4, -4, 3, 0}));
	scenario_end(err_2);
	return (err + err_2);
}

bool	test_tuple_add(void)
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

bool	test_sub_pts(void)
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

bool	test_sub_pt_vec(void)
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

bool	test_sub_vects(void)
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

bool	test_sub_zero_vec(void)
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

bool	test_neg_tuple(void)
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
