/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:02:07 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/02 20:58:11 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_m(t_4mtrx a, char *name)
{
	printf("Matrix %s:\n", name);
	for (t_unt i = 0; i < 4; i++)
	{
		printf("[");
		for (t_unt j = 0; j < 4; j++)
		{
			printf("%5f", a[i][j]);
			if (j < 4 - 1)
				printf(" ");
		}
		printf("]\n");
	}
}

t_unt	test_matrix_4_init(void)
{
	t_4mtrx	m;
	t_unt	err;

	scenario_start("Constructing and inspecting a 4x4 matrix");
	given("the following 4x4 matrix M:\n |  1   |  2   |  3   |  4   |\n\
 |  5.5 |  6.5 |  7.5 |  8.5 |\n |  9   |  10  |  11  |  12  |\n\
 |  13.5|  14.5|  15.5|  16.5|", 0);
	m = set_4mtrx((t_i4mtr){1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9,
			10, 11, 12, 13.5, 14.5, 15.5, 16.5});
	err = then("M[0,0] = 1", f_eq(m[0][0], 1), 0);
	err += then("M[0,3] = 4", f_eq(m[0][3], 4), 1);
	err += then("M[1,0] = 5.5", f_eq(m[1][0], 5.5), 2);
	err += then("M[1,2] = 7.5", f_eq(m[1][2], 7.5), 3);
	err += then("M[2,2] = 11", f_eq(m[2][2], 11), 4);
	err += then("M[3,0] = 13.5", f_eq(m[3][0], 13.5), 5);
	err += then("M[3,2] = 15.5", f_eq(m[3][2], 15.5), 6);
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
	err[0] = then("M[0,0] = -3", f_eq(m2[0][0], -3), 0);
	err[0] += then("M[0,1] = 5", f_eq(m2[0][1], 5), 1);
	err[0] += then("M[1,0] = 1", f_eq(m2[1][0], 1), 2);
	err[0] += then("M[1,1] = -2", f_eq(m2[1][1], -2), 3);
	scenario_end(err[0]);
	scenario_start("A 3x3 matrix ought to be representable");
	given("the following 3x3 matrix M:\n | -3 |  5 |  0 |\n |  1 | -2 |  7 |\n\
 |  0 |  1 |  1 |", 0);
	m3 = set_3mtrx((t_i3mtr){-3, 5, 0, 1, -2, 7, 0, 1, 1});
	err[1] = then("M[0,0] = -3", f_eq(m3[0][0], -3), 0);
	err[1] += then("M[1,1] = -2", f_eq(m3[1][1], -2), 1);
	err[1] += then("M[2,2] = 1", f_eq(m3[2][2], 1), 2);
	scenario_end(err[1]);
	return (err[0] + err[1]);
}

t_unt	test_matrix_equality(void)
{
	t_4mtrx	a;
	t_4mtrx	b;
	t_unt	err[2];

	scenario_start("Matrix equality with identical matrices");
	given("the following matrix A:\n | 1 | 2 | 3 | 4 |\n | 5 | 6 | 7 | 8 |\n\
 | 9 | 8 | 7 | 6 |\n | 5 | 4 | 3 | 2 |", 0);
	given("the following matrix B:\n | 1 | 2 | 3 | 4 |\n | 5 | 6 | 7 | 8 |\n\
 | 9 | 8 | 7 | 6 |\n | 5 | 4 | 3 | 2 |", 1);
	a = set_4mtrx((t_i4mtr){1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
	b = set_4mtrx((t_i4mtr){1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
	err[0] = then("A = B", matr_4_eq(a, b), 0);
	scenario_end(err[0]);
	scenario_start("Matrix equality with different matrices");
	given("the following matrix A:\n | 1 | 2 | 3 | 4 |\n | 5 | 6 | 7 | 8 |\n\
 | 9 | 8 | 7 | 6 |\n | 5 | 4 | 3 | 2 |", 1);
	given("the following matrix B:\n | 2 | 3 | 4 | 5 |\n | 6 | 7 | 8 | 9 |\n\
 | 8 | 7 | 6 | 5 |\n | 4 | 3 | 2 | 1 |", 1);
	a = set_4mtrx((t_i4mtr){1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
	b = set_4mtrx((t_i4mtr){2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1});
	err[1] = then("A != B", !matr_4_eq(a, b), 0);
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
	given("the following matrix A:\n | 1 | 2 | 3 | 4 |\n | 5 | 6 | 7 | 8 |\n\
 | 9 | 8 | 7 | 6 |\n | 5 | 4 | 3 | 2 |", 0);
	given("And the following matrix B:\n |-2 | 1 | 2 | 3 |\n\
 | 3 | 2 | 1 |-1 |\n | 4 | 3 | 6 | 5 |\n | 1 | 2 | 7 | 8 |", 1);
	a = set_4mtrx((t_i4mtr){1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
	b = set_4mtrx((t_i4mtr){-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8});
	result = set_4mtrx((t_i4mtr){20, 22, 50, 48, 44, 54, 114, 108,
			40, 58, 110, 102, 16, 26, 46, 42});
	err = then("A * B is the following 4x4 matrix:\n |  20 |  22 |  50 |  48 |\
\n |  44 |  54 | 114 | 108 |\n |  40 |  58 | 110 | 102 |\n\
 |  16 |  26 |  46 |  42 |",
			matr_4_eq(a * b, result), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_matrix_by_tuple(void)
{
	t_4mtrx	a;
	t_tuple	b;
	t_tuple	expected;
	t_tuple	result;
	t_unt	err;

	scenario_start("A matrix multiplied by a tuple");
	given("the following matrix A:\n | 1 | 2 | 3 | 4 |\n | 2 | 4 | 4 | 2 |\n\
 | 8 | 6 | 4 | 1 |\n | 0 | 0 | 0 | 1 |", 0);
	given("b ← tuple(1, 2, 3, 1)", 0);
	a = set_4mtrx((t_i4mtr){1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1});
	b = set_tuple(1, 2, 3, 1);
	expected = set_tuple(18, 24, 33, 1);
	result = tup_mtrx(a, b);
	err = then("A * b = tuple(18, 24, 33, 1)",
			is_same_tuple(result, expected), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_matrix_identity(void)
{
	t_4mtrx	a_m;
	t_tuple	a_t;
	t_4mtrx	identity_matrix;
	t_unt	err[2];

	scenario_start("Multiplying a matrix by the identity matrix");
	given("the following matrix A:\n | 0 | 1 | 2 | 4 |\n | 1 | 2 | 4 | 8 |\n\
 | 2 | 4 | 8 | 16|\n | 4 | 8 | 16| 32|", 0);
	a_m = set_4mtrx((t_i4mtr){0, 1, 2, 4, 1, 2, 4, 8,
			2, 4, 8, 16, 4, 8, 16, 32});
	identity_matrix = get_id4mtrx();
	err[0] = then("A * identity_matrix = A",
			matr_4_eq(a_m * identity_matrix, a_m), 0);
	scenario_end(err[0]);
	scenario_start("Multiplying the identity matrix by a tuple");
	given("a ← tuple(1, 2, 3, 4)", 0);
	a_t = set_tuple(1, 2, 3, 4);
	err[1] = then("identity_matrix * a = a",
			is_same_tuple(tup_mtrx(identity_matrix, a_t), a_t), 0);
	scenario_end(err[1]);
	return (err[0] + err[1]);
}

t_unt	test_matrix_transpose(void)
{
	t_4mtrx	a;
	t_4mtrx	expected;
	t_unt	err;

	scenario_start("Transposing a matrix");
	given("the following matrix A:\n | 0 | 9 | 3 | 0 |\n | 9 | 8 | 0 | 8 |\n\
 | 1 | 8 | 5 | 3 |\n | 0 | 0 | 5 | 8 |", 0);
	a = set_4mtrx((t_i4mtr){0, 9, 3, 0, 9, 8, 0, 8, 1, 8, 5, 3, 0, 0, 5, 8});
	expected = set_4mtrx((t_i4mtr){0, 9, 1, 0, 9, 8, 8, 0, 3,
			0, 5, 5, 0, 8, 3, 8});
	err = then("transpose(A) is the following matrix:\n | 0 | 9 | 1 | 0 |\
\n | 9 | 8 | 8 | 0 |\n | 3 | 0 | 5 | 5 |\n | 0 | 8 | 3 | 8 |",
			matr_4_eq(transpose(a), expected), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_transpose_identity(void)
{
	t_4mtrx	identity_matrix;
	t_unt	err;

	scenario_start("Transposing the identity matrix");
	given("A ← transpose(identity_matrix)", 0);
	identity_matrix = get_id4mtrx();
	err = then("A = identity_matrix",
			matr_4_eq(transpose(identity_matrix), identity_matrix), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_2x2_matrix_det(void)
{
	t_2mtrx	a;
	float	det_a;
	float	expected_det;
	t_unt	err;

	scenario_start("Calculating the determinant of a 2x2 matrix");
	given("the following 2x2 matrix A:\n | 1 | 5 |\n |-3 | 2 |", 0);
	a = set_2mtrx((t_i2mtr){1, 5, -3, 2});
	det_a = det_2mtrx(a);
	expected_det = 17;
	err = then("determinant(A) = 17", f_eq(det_a, expected_det), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_submatrix(void)
{
	t_3mtrx	a_3;
	t_4mtrx	a_4;
	t_2mtrx	submtrx_2;
	t_3mtrx	submtrx_3;
	t_unt	err[2];

	scenario_start("Submatrix of a 3x3 matrix is a 2x2 matrix");
	given("the following 3x3 matrix A:\n | 1 | 5 | 0 |\n\
 |-3 | 2 | 7 |\n | 0 | 6 |-3 |", 0);
	a_3 = set_3mtrx((t_i3mtr){1, 5, 0, -3, 2, 7, 0, 6, -3});
	submtrx_2 = sub_3mtrx(a_3, 0, 2);
	err[0] = then("submatrix(A, 0, 2) is the following 2x2 matrix:\n\
 |-3 | 2 |\n | 0 | 6 |", matr_2_eq(submtrx_2,
				set_2mtrx((t_i2mtr){-3, 2, 0, 6})), 0);
	scenario_end(err[0]);
	scenario_start("Submatrix of a 4x4 matrix is a 3x3 matrix");
	given("the following 4x4 matrix A:\n |-6 | 1 | 1 | 6 |\n |-8 | 5 | 8 | 6 |\
\n |-1 | 0 | 8 | 2 |\n |-7 | 1 |-1 | 1 |", 0);
	a_4 = set_4mtrx((t_i4mtr){-6, 1, 1, 6, -8, 5, 8, 6,
			-1, 0, 8, 2, -7, 1, -1, 1});
	submtrx_3 = sub_4mtrx(a_4, 2, 1);
	a_3 = set_3mtrx((t_i3mtr){-6, 1, 6, -8, 8, 6, -7, -1, 1});
	err[1] = then("submatrix(A, 2, 1) is the following 3x3 matrix:\n\
 |-6 | 1 | 6 |\n |-8 | 8 | 6 |\n |-7 |-1 | 1 |",
			matr_3_eq(&submtrx_3, &a_3), 0);
	scenario_end(err[1]);
	return (err[0] + err[1]);
}

t_unt	test_minor_3x3(void)
{
	t_3mtrx	a;
	t_2mtrx	b;
	float	det_b;
	float	minor_val;
	t_unt	err;

	scenario_start("Calculating a minor of a 3x3 matrix");
	given("the following 3x3 matrix A:\n | 3 |  5 |  0 |\n | 2 | -1 | -7 |\n\
 | 6 | -1 |  5 |", 0);
	a = set_3mtrx((t_i3mtr){3, 5, 0, 2, -1, -7, 6, -1, 5});
	b = sub_3mtrx(a, 1, 0);
	det_b = det_2mtrx(b);
	minor_val = minor_3mtrx(a, 1, 0);
	err = then("determinant(B) = 25", f_eq(det_b, 25), 0);
	err += then("minor(A, 1, 0) = 25", f_eq(minor_val, 25), 1);
	scenario_end(err);
	return (err);
}

t_unt	test_cofactor_3x3(void)
{
	t_3mtrx	a;
	float	minor[2];
	float	cofactor[2];
	t_unt	err;

	scenario_start("Calculating a cofactor of a 3x3 matrix");
	given("the following 3x3 matrix A:\n | 3 |  5 |  0 |\n | 2 | -1 | -7 |\n\
 | 6 | -1 |  5 |", 0);
	a = set_3mtrx((t_i3mtr){3, 5, 0, 2, -1, -7, 6, -1, 5});
	minor[0] = minor_3mtrx(a, 0, 0);
	minor[1] = minor_3mtrx(a, 1, 0);
	cofactor[0] = cofactor_3mtrx(a, 0, 0);
	cofactor[1] = cofactor_3mtrx(a, 1, 0);
	err = then("minor(A, 0, 0) = -12", f_eq(minor[0], -12), 0);
	err += then("cofactor(A, 0, 0) = -12", f_eq(cofactor[0], -12), 1);
	err += then("minor(A, 1, 0) = 25", f_eq(minor[1], 25), 2);
	err += then("cofactor(A, 1, 0) = -25", f_eq(cofactor[1], -25), 3);
	scenario_end(err);
	return (err);
}

t_unt	test_determinant_3x3(void)
{
	t_3mtrx	a;
	float	cofactor[3];
	float	det_a;
	t_unt	err;

	scenario_start("Calculating the determinant of a 3x3 matrix");
	given("the following 3x3 matrix A:\n |  1 | 2 |  6 |\n\
 | -5 | 8 | -4 |\n |  2 | 6 |  4 |", 0);
	a = set_3mtrx((t_i3mtr){1, 2, 6, -5, 8, -4, 2, 6, 4});
	cofactor[0] = cofactor_3mtrx(a, 0, 0);
	cofactor[1] = cofactor_3mtrx(a, 0, 1);
	cofactor[2] = cofactor_3mtrx(a, 0, 2);
	det_a = det_3mtrx(a);
	err = then("cofactor(A, 0, 0) = 56", f_eq(cofactor[0], 56), 0);
	err += then("cofactor(A, 0, 1) = 12", f_eq(cofactor[1], 12), 1);
	err += then("cofactor(A, 0, 2) = -46", f_eq(cofactor[2], -46), 2);
	err += then("determinant(A) = -196", f_eq(det_a, -196), 3);
	scenario_end(err);
	return (err);
}

t_unt	test_determinant_4x4(void)
{
	t_4mtrx	a;
	float	cofactors[4];
	float	det_a;
	t_unt	err;

	scenario_start("Calculating the determinant of a 4x4 matrix");
	given("the following 4x4 matrix A:\n | -2 | -8 |  3 |  5 |\n \
| -3 |  1 |  7 |  3 |\n |  1 |  2 | -9 |  6 |\n | -6 |  7 |  7 | -9 |", 0);
	a = set_4mtrx((t_i4mtr){-2, -8, 3, 5, -3, 1, 7, 3,
			1, 2, -9, 6, -6, 7, 7, -9});
	for (int i = 0; i < 4; i++)
		cofactors[i] = cofactor_4mtrx(a, 0, i);
	det_a = det_4mtrx(a);
	err = then("cofactor(A, 0, 0) = 690", f_eq(cofactors[0], 690), 0);
	err += then("cofactor(A, 0, 1) = 447", f_eq(cofactors[1], 447), 1);
	err += then("cofactor(A, 0, 2) = 210", f_eq(cofactors[2], 210), 2);
	err += then("cofactor(A, 0, 3) = 51", f_eq(cofactors[3], 51), 3);
	err += then("determinant(A) = -4071", f_eq(det_a, -4071), 4);
	scenario_end(err);
	return (err);
}

t_unt	test_invertibility(void)
{
	t_4mtrx	a;
	float	det_a;
	t_unt	err[2];

	scenario_start("Testing an invertible matrix for invertibility");
	given("the following 4x4 matrix A:\n | 6 | 4 | 4 | 4 |\n \
| 5 | 5 | 7 | 6 |\n | 4 |-9 | 3 |-7 |\n | 9 | 1 | 7 |-6 |", 0);
	a = set_4mtrx((t_i4mtr){6, 4, 4, 4, 5, 5, 7, 6, 4, -9, 3, -7, 9, 1, 7, -6});
	det_a = det_4mtrx(a);
	err[0] = then("determinant(A) = -2120", f_eq(det_a, -2120), 0);
	err[0] += then("A is invertible", !f_eq(det_a, 0), 1);
	scenario_end(err[0]);
	scenario_start("Testing a noninvertible matrix for invertibility");
	given("the following 4x4 matrix A:\n |-4 | 2 |-2 |-3 |\n \
| 9 | 6 | 2 | 6 |\n | 0 |-5 | 1 |-5 |\n | 0 | 0 | 0 | 0 |", 0);
	a = set_4mtrx((t_i4mtr){-4, 2, -2, -3, 9, 6, 2, 6,
			0, -5, 1, -5, 0, 0, 0, 0});
	det_a = det_4mtrx(a);
	err[1] = then("determinant(A) = 0", f_eq(det_a, 0), 0);
	err[1] += then("A is not invertible", f_eq(det_a, 0), 1);
	scenario_end(err[1]);
	return (err[0] + err[1]);
}

t_unt	test_matrix_inverse(void)
{
	t_4mtrx	a;
	t_4mtrx	b;
	float	cofactor[2];
	t_unt	err;

	scenario_start("Calculating the inverse of a matrix");
	given("the following 4x4 matrix A:\n | -5 |  2 |  6 | -8 |\n \
|  1 | -5 |  1 |  8 |\n |  7 |  7 | -6 | -7 |\n |  1 | -3 |  7 |  4 |", 0);
	a = set_4mtrx((t_i4mtr){-5, 2, 6, -8, 1, -5, 1, 8,
			7, 7, -6, -7, 1, -3, 7, 4});
	err = then("determinant(A) = 532", f_eq(det_4mtrx(a), 532), 0);
	cofactor[0] = cofactor_4mtrx(a, 2, 3);
	cofactor[1] = cofactor_4mtrx(a, 3, 2);
	b = inverse_4mtrx(a);
	err += then("cofactor(A, 2, 3) = -160", f_eq(cofactor[0], -160), 1);
	err += then("B[3,2] = -160/532", f_eq(b[3][2], -160.0 / 532.0), 2);
	err += then("cofactor(A, 3, 2) = 105", f_eq(cofactor[1], 105), 3);
	err += then("B[2,3] = 105/532", f_eq(b[2][3], 105.0 / 532.0), 4);
	err += then("B is the following 4x4 matrix:\n |  0.21805 |  0.45113 |  \
0.24060 | -0.04511 |\n | -0.80827 | -1.45677 | -0.44361 |  0.52068 |\n \
| -0.07895 | -0.22368 | -0.05263 |  0.19737 |\n \
| -0.52256 | -0.81391 | -0.30075 |  0.30639 |", matr_4_eq(b,
				set_4mtrx((t_i4mtr){0.21805, 0.45113, 0.24060, -0.04511,
					-0.80827, -1.45677, -0.44361, 0.52068,
					-0.07895, -0.22368, -0.05263, 0.19737,
					-0.52256, -0.81391, -0.30075, 0.30639})), 5);
	scenario_end(err);
	return (err);
}

t_unt	test_matrix_inverse_another(void)
{
	t_4mtrx	a;
	t_4mtrx	b;
	t_unt	err;

	scenario_start("Calculating the inverse of another matrix");
	given("the following 4x4 matrix A:\n |  8 | -5 |  9 |  2 |\n \
|  7 |  5 |  6 |  1 |\n | -6 |  0 |  9 |  6 |\n | -3 |  0 | -9 | -4 |", 0);
	a = set_4mtrx((t_i4mtr){8, -5, 9, 2, 7, 5, 6, 1,
			-6, 0, 9, 6, -3, 0, -9, -4});
	b = inverse_4mtrx(a);
	err = then("inverse(A) is the following 4x4 matrix:\n \
| -0.15385 | -0.15385 | -0.28205 | -0.53846 |\n \
| -0.07692 |  0.12308 |  0.02564 |  0.03077 |\n \
| 0.35897  |  0.35897 |  0.43590 |  0.92308 |\n \
| -0.69231 | -0.69231 | -0.76923 | -1.92308 |", matr_4_eq(b,
				set_4mtrx((t_i4mtr){-0.15385, -0.15385, -0.28205, -0.53846,
					-0.07692, 0.12308, 0.02564, 0.03077,
					0.35897, 0.35897, 0.43590, 0.92308,
					-0.69231, -0.69231, -0.76923, -1.92308})), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_matrix_inverse_third(void)
{
	t_4mtrx	a;
	t_4mtrx	b;
	t_unt	err;

	scenario_start("Calculating the inverse of a third matrix");
	given("the following 4x4 matrix A:\n |  9 |  3 |  0 |  9 |\n \
| -5 | -2 | -6 | -3 |\n | -4 |  9 |  6 |  4 |\n | -7 |  6 |  6 |  2 |", 0);
	a = set_4mtrx((t_i4mtr){9, 3, 0, 9, -5, -2, -6, -3,
			-4, 9, 6, 4, -7, 6, 6, 2});
	b = inverse_4mtrx(a);
	err = then("inverse(A) is the following 4x4 matrix:\n \
| -0.04074 | -0.07778 |  0.14444 | -0.22222 |\n \
| -0.07778 |  0.03333 |  0.36667 | -0.33333 |\n \
| -0.02901 | -0.14630 | -0.10926 |  0.12963 |\n \
|  0.17778 |  0.06667 | -0.26667 |  0.33333 |", matr_4_eq(b,
				set_4mtrx((t_i4mtr){-0.04074, -0.07778, 0.14444, -0.22222,
					-0.07778, 0.03333, 0.36667, -0.33333,
					-0.02901, -0.14630, -0.10926, 0.12963,
					0.17778, 0.06667, -0.26667, 0.33333})), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_matrix_multiply_inverse(void)
{
	t_4mtrx	a;
	t_4mtrx	b;
	t_4mtrx	c;
	t_unt	err;

	scenario_start("Multiplying a product by its inverse");
	given("the following 4x4 matrix A:\n |  3 | -9 |  7 |  3 |\n \
|  3 | -8 |  2 | -9 |\n | -4 |  4 |  4 |  1 |\n | -6 |  5 | -1 |  1 |", 0);
	a = set_4mtrx((t_i4mtr){3, -9, 7, 3, 3, -8, 2, -9,
			-4, 4, 4, 1, -6, 5, -1, 1});
	given("the following 4x4 matrix B:\n |  8 |  2 |  2 |  2 |\n \
|  3 | -1 |  7 |  0 |\n |  7 |  0 |  5 |  4 |\n |  6 | -2 |  0 |  5 |", 0);
	b = set_4mtrx((t_i4mtr){8, 2, 2, 2, 3, -1, 7, 0,
			7, 0, 5, 4, 6, -2, 0, 5});
	given("C ← A * B", 0);
	c = a * b;
	c = c * inverse_4mtrx(b);
	err = then("C * inverse(B) = A", matr_4_eq(c, a), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_inverse_identity_matrix(void)
{
	t_4mtrx	i;
	t_4mtrx	result;
	t_unt	err;

	scenario_start("Inverting the identity matrix");
	given("the following 4x4 identity matrix I:\n | 1 | 0 | 0 | 0 |\n \
| 0 | 1 | 0 | 0 |\n | 0 | 0 | 1 | 0 |\n | 0 | 0 | 0 | 1 |", 0);
	i = get_id4mtrx();
	when("I ← inverse(I)", 0);
	result = inverse_4mtrx(i);
	err = then("I is the following 4x4 identity matrix:\n | 1 | 0 | 0 | 0 |\n \
| 0 | 1 | 0 | 0 |\n | 0 | 0 | 1 | 0 |\n | 0 | 0 | 0 | 1 |",
			matr_4_eq(result, i), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_matrix_mult_inverse(void)
{
	t_4mtrx	a;
	t_4mtrx	b;
	t_unt	err;

	scenario_start("Multiplying a matrix by its inverse");
	given("the following 4x4 matrix A:\n |  3 | -9 |  7 |  3 |\n \
|  3 | -8 |  2 | -9 |\n | -4 |  4 |  4 |  1 |\n | -6 |  5 | -1 |  1 |", 0);
	a = set_4mtrx((t_i4mtr){3, -9, 7, 3, 3, -8, 2, -9,
			-4, 4, 4, 1, -6, 5, -1, 1});
	given("B ← A * inverse(A)", 0);
	b = a * inverse_4mtrx(a);
	err = then("B is the 4x4 identity matrix:\n | 1 | 0 | 0 | 0 |\n \
| 0 | 1 | 0 | 0 |\n | 0 | 0 | 1 | 0 |\n | 0 | 0 | 0 | 1 |",
			matr_4_eq(b, get_id4mtrx()), 0);
	scenario_end(err);
	return (err);
}
