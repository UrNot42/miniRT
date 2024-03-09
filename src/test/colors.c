/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:14:50 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 16:22:40 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_color_tuple(void)
{
	t_color	c;
	t_unt	err;

	scenario_start("Colors are (red, green, blue) tuples");

	given("c ← color(-0.5, 0.4, 1.7)", 0);
	c = set_col(-0.5, 0.4, 1.7);

	err = test_print("c.red = -0.5", f_eq(c.red, -0.5));
	err += test_print("c.green = 0.4", f_eq(c.green, 0.4));
	err += test_print("c.blue = 1.7", f_eq(c.blue, 1.7));

	scenario_end(err);

	return (err);
}

t_unt	test_color_operations(void)
{
	t_color	c1;
	t_color	c2;
	t_color	expected;
	t_color	result;
	t_unt	err[2];

	scenario_start("Adding colors");
	given("c1 ← color(0.9, 0.6, 0.75)", 0);
	given("c2 ← color(0.7, 0.1, 0.25)", 0);
	c1 = set_col(0.9, 0.6, 0.75);
	c2 = set_col(0.7, 0.1, 0.25);
	result.tuple = c1.tuple + c2.tuple;
	expected = set_col(1.6, 0.7, 1.0);
	err[0] = test_print("c1 + c2 = color(1.6, 0.7, 1.0)",
			is_same_tuple(result.tuple, expected.tuple));
	scenario_end(err[0]);

	scenario_start("Subtracting colors");
	given("c1 ← color(0.9, 0.6, 0.75)", 0);
	given("c2 ← color(0.7, 0.1, 0.25)", 0);
	c1 = set_col(0.9, 0.6, 0.75);
	c2 = set_col(0.7, 0.1, 0.25);
	result.tuple = c1.tuple - c2.tuple;
	expected = set_col(0.2, 0.5, 0.5);
	err[1] = test_print("c1 - c2 = color(0.2, 0.5, 0.5)",
			is_same_tuple(result.tuple, expected.tuple));
	scenario_end(err[1]);
	return (err[0] + err[1]);
}

t_unt	test_multiply_colors(void)
{
	t_color	c1;
	t_color	c2;
	t_color	expected;
	t_color	result;
	t_unt	err[2];

	scenario_start("Multiplying a color by a scalar");
	given("c ← color(0.2, 0.3, 0.4)", 0);
	c1 = set_col(0.2, 0.3, 0.4);
	result.tuple = c1.tuple * 2;
	expected = set_col(0.4, 0.6, 0.8);
	err[1] = test_print("c * 2 = color(0.4, 0.6, 0.8)",
			is_same_tuple(result.tuple, expected.tuple));
	scenario_end(err[1]);

	scenario_start("Multiplying colors");
	given("c1 ← color(1, 0.2, 0.4)", 0);
	given("c2 ← color(0.9, 1, 0.1)", 0);
	c1 = set_col(1, 0.2, 0.4);
	c2 = set_col(0.9, 1, 0.1);
	result = hadamard_product(c1, c2);
	expected = set_col(0.9, 0.2, 0.04);
	err[0] = test_print("c1 * c2 = color(0.9, 0.2, 0.04)",
			is_same_tuple(result.tuple, expected.tuple));
	scenario_end(err[0]);
	return (err[0] + err[1]);
}
