/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:02:07 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 20:51:11 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_matrix_4_init(void)
{
	t_4mtrx	m;
	t_unt	err;

	scenario_start("Constructing and inspecting a 4x4 matrix");
	given("the following 4x4 matrix M:\n |  1   |  2   |  3   |  4   |\n |  5.5 |  6.5 |  7.5 |  8.5 |\n |  9   |  10  |  11  |  12  |\n |  13.5|  14.5|  15.5|  16.5|", 0);
	m = set_4mtrx((t_i4mtr){1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9,
			10, 11, 12, 13.5, 14.5, 15.5, 16.5});
	err = test_print("M[0,0] = 1", f_eq(m[0][0], 1));
	err += test_print("M[0,3] = 4", f_eq(m[0][3], 4));
	err += test_print("M[1,0] = 5.5", f_eq(m[1][0], 5.5));
	err += test_print("M[1,2] = 7.5", f_eq(m[1][2], 7.5));
	err += test_print("M[2,2] = 11", f_eq(m[2][2], 11));
	err += test_print("M[3,0] = 13.5", f_eq(m[3][0], 13.5));
	err += test_print("M[3,2] = 15.5", f_eq(m[3][2], 15.5));
	scenario_end(err);
	return (err);
}

t_unt	test_matrix_2_3_init(void)
{
	t_3mtrx	m3;
	t_2mtrx	m2;
	t_unt	err[2];

	scenario_start("A 2x2 matrix ought to be representable");
	given("the following 2x2 matrix M:\n | -3 |  5 |\n |  1 | -2 |", 0);
	m2 = set_2mtrx((t_i2mtr){-3, 5, 1, -2});
	err[0] = test_print("M[0,0] = -3", f_eq(m2[0][0], -3));
	err[0] += test_print("M[0,1] = 5", f_eq(m2[0][1], 5));
	err[0] += test_print("M[1,0] = 1", f_eq(m2[1][0], 1));
	err[0] += test_print("M[1,1] = -2", f_eq(m2[1][1], -2));
	scenario_end(err[0]);

	scenario_start("A 3x3 matrix ought to be representable");
	given("the following 3x3 matrix M:\n | -3 |  5 |  0 |\n |  1 | -2 |  7 |\n |  0 |  1 |  1 |", 0);
	m3 = set_3mtrx((t_i3mtr){-3, 5, 0, 1, -2, 7, 0, 1, 1});
	err[1] = test_print("M[0,0] = -3", f_eq(m3[0][0], -3));
	err[1] += test_print("M[1,1] = -2", f_eq(m3[1][1], -2));
	err[1] += test_print("M[2,2] = 1", f_eq(m3[2][2], 1));
	scenario_end(err[1]);
	return (err[0] + err[1]);
}

t_unt	test_matrix_equality(void)
{
	t_4mtrx	a;
	t_4mtrx	b;
	t_unt	err[2];

	scenario_start("Matrix equality with identical matrices");
	given("the following matrix A:\n | 1 | 2 | 3 | 4 |\n | 5 | 6 | 7 | 8 |\n | 9 | 8 | 7 | 6 |\n | 5 | 4 | 3 | 2 |", 0);
	given("the following matrix B:\n | 1 | 2 | 3 | 4 |\n | 5 | 6 | 7 | 8 |\n | 9 | 8 | 7 | 6 |\n | 5 | 4 | 3 | 2 |", 1);
	a = set_4mtrx((t_i4mtr){1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
	b = set_4mtrx((t_i4mtr){1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
	err[0] = test_print("A = B", matr_4_eq(a, b));
	scenario_end(err[0]);

	scenario_start("Matrix equality with different matrices");
	given("the following matrix A:\n | 1 | 2 | 3 | 4 |\n | 5 | 6 | 7 | 8 |\n | 9 | 8 | 7 | 6 |\n | 5 | 4 | 3 | 2 |", 1);
	given("the following matrix B:\n | 2 | 3 | 4 | 5 |\n | 6 | 7 | 8 | 9 |\n | 8 | 7 | 6 | 5 |\n | 4 | 3 | 2 | 1 |", 1);
	a = set_4mtrx((t_i4mtr){1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
	b = set_4mtrx((t_i4mtr){2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1});
	err[1] = test_print("A != B", !matr_4_eq(a, b));
	scenario_end(err[1]);
	return (err[0] + err[1]);
}


t_unt	test_matrix_mult(void)
{
	t_4mtrx	a;
	t_4mtrx	b;
	t_4mtrx	result;
	t_unt	err;

	scenario_start("Multiplying two matrices");
	given("the following matrix A:\n | 1 | 2 | 3 | 4 |\n | 5 | 6 | 7 | 8 |\n | 9 | 8 | 7 | 6 |\n | 5 | 4 | 3 | 2 |", 0);
	given( "And the following matrix B:\n |-2 | 1 | 2 | 3 |\n | 3 | 2 | 1 |-1 |\n | 4 | 3 | 6 | 5 |\n | 1 | 2 | 7 | 8 |", 1);
	a = set_4mtrx((t_i4mtr){1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
	b = set_4mtrx((t_i4mtr){-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8});
	result = set_4mtrx((t_i4mtr){20, 22, 50, 48, 44, 54, 114, 108, 40, 58, 110, 102, 16, 26, 46, 42});
	err = test_print("A * B is the following 4x4 matrix:\n | 20| 22 | 50 | 48 |\n | 44| 54 | 114 | 108 |\n | 40| 58 | 110 | 102 |\n | 16| 26 | 46 | 42 |", matr_4_eq(a * b, result));
	scenario_end(err);

	return (err);
}