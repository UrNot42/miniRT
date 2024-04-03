/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:39:57 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 13:29:01 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_magnitude_vector(void)
{
	t_tuple	v;
	float	result;
	float	expected;
	t_unt	err[5];

	scenario_start("Computing the magnitude of vector(1, 0, 0)");
	given("v ← vector(1, 0, 0)", 0);
	v = set_vec(1, 0, 0);
	result = vec_magn(v);
	expected = 1.0f;
	err[0] = then("magnitude(v) = 1", f_eq(result, expected), 0);
	scenario_end(err[0]);

	scenario_start("Computing the magnitude of vector(0, 1, 0)");
	given("v ← vector(0, 1, 0)", 0);
	v = set_vec(0, 1, 0);
	result = vec_magn(v);
	expected = 1.0f;
	err[1] = then("magnitude(v) = 1", f_eq(result, expected), 0);
	scenario_end(err[1]);

	scenario_start("Computing the magnitude of vector(0, 0, 1)");
	given("v ← vector(0, 0, 1)", 0);
	v = set_vec(0, 0, 1);
	result = vec_magn(v);
	expected = 1.0f;
	err[2] = then("magnitude(v) = 1", f_eq(result, expected), 0);
	scenario_end(err[2]);

	scenario_start("Computing the magnitude of vector(1, 2, 3)");
	given("v ← vector(1, 2, 3)", 0);
	v = set_vec(1, 2, 3);
	result = vec_magn(v);
	expected = sqrtf(14.0f);
	err[3] = then("magnitude(v) = √14", f_eq(result, expected), 0);
	scenario_end(err[3]);

	scenario_start("Computing the magnitude of vector(-1, -2, -3)");
	given("v ← vector(-1, -2, -3)", 0);
	v = set_vec(-1, -2, -3);
	result = vec_magn(v);
	expected = sqrtf(14.0f);
	err[4] = then("magnitude(v) = √14", f_eq(result, expected), 0);
	scenario_end(err[4]);

	return (err[0] + err[1] + err[2] + err[3] + err[4]);
}

t_unt	test_vector_normalization(void)
{
	t_tuple	v;
	t_tuple	norm;
	double	magnitude_norm;
	t_unt	err[3];

	scenario_start("Normalizing vector(4, 0, 0) gives (1, 0, 0)");
	given("v ← vector(4, 0, 0)", 0);
	v = set_vec(4, 0, 0);
	norm = vec_norm(v);
	err[0] = then("normalize(v) = vector(1, 0, 0)",
			tup_eq(norm, set_vec(1, 0, 0)), 0);
	scenario_end(err[0]);

	scenario_start("Normalizing vector(1, 2, 3)");
	given("v ← vector(1, 2, 3)", 0);
	v = set_vec(1, 2, 3);
	norm = vec_norm(v);
	err[1] = then("normalize(v) = approximately vector(0.26726,\
 0.53452, 0.80178)",
			tup_eq(norm, set_vec(0.26726, 0.53452, 0.801780)), 0);
	scenario_end(err[1]);

	scenario_start("The magnitude of a normalized vector");
	given("v ← vector(1, 2, 3)", 0);
	v = set_vec(1, 2, 3);
	norm = vec_norm(v);
	magnitude_norm = vec_magn(norm);
	err[2] = then("magnitude(norm) = 1", f_eq(magnitude_norm, 1.0), 0);
	scenario_end(err[2]);

	return (err[0] + err[1] + err[2]);
}

t_unt	test_dot_product(void)
{
	t_tuple	a;
	t_tuple	b;
	float	result;
	t_unt	err;

	scenario_start("The dot product of two tuples");
	given("a ← vector(1, 2, 3)", 0);
	given("b ← vector(2, 3, 4)", 1);
	a = set_vec(1, 2, 3);
	b = set_vec(2, 3, 4);
	result = vec_dot(a, b);
	err = then("dot(a, b) = 20", f_eq(result, 20.0), 0);
	scenario_end(err);

	return (err);
}

t_unt	test_cross_product(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	result[2];
	t_unt	err;

	scenario_start("The cross product of two vectors");
	given("a ← vector(1, 2, 3)", 0);
	given("b ← vector(2, 3, 4)", 0);
	a = set_vec(1, 2, 3);
	b = set_vec(2, 3, 4);
	result[0] = vec_cross(a, b);
	err = then("cross(a, b) = vector(-1, 2, -1)",
			tup_eq(result[0], set_vec(-1, 2, -1)), 0);
	result[1] = vec_cross(b, a);
	err += then("cross(b, a) = vector(1, -2, 1)",
			tup_eq(result[1], set_vec(1, -2, 1)), 0);
	scenario_end(err);

	return (err);
}
