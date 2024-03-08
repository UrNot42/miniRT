/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:22 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 15:29:41 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	launch_tup_pts_vec_test(void)
{
	t_unt	err;

	err = test_tuple();
	err += test_point_vec();
	err += test_tuple_add();
	err += test_tuple_sub();
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
	a1 = set_tuple((t_tuple){3, -2, 5, 1});
	given("a2 ← tuple(-2, 3, 1, 0)", 1);
	a2 = set_tuple((t_tuple){-2, 3, 1, 0});
	err = test_print("a1 + a2 = tuple(1, 1, 6, 1)",
			is_same_tuple(tup_add(a1, a2), (t_tuple){1, 1, 6, 1}));
	scenario_end(err);
	return (err);
}

bool	test_tuple_sub(void)
{
	t_tuple	p1;
	t_tuple	p2;
	t_unt	err;

	scenario_start("Subtracting two points");
	given("p1 ← point(3, 2, 1)", 0);
	p1 = set_point((t_pos){3, 2, 1});
	given("p2 ← point(5, 6, 7)", 1);
	p2 = set_point((t_pos){5, 6, 7});
	err = test_print("p1 - p2 = vector(-2, -4, -6)",
			is_same_tuple(tup_sub(p1, p2), set_vec((t_pos){-2, -4, -6})));
	scenario_end(err);
	return (err);
}
