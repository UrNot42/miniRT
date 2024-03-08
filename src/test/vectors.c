/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:39:57 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 18:10:19 by ulevallo         ###   ########.fr       */
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
	v = set_vec((t_pos){1, 0, 0});
	result = vec_magnitude(v);
	expected = 1.0f;
	err[0] = test_print("magnitude(v) = 1", f_eq(result, expected));
	scenario_end(err[0]);

	scenario_start("Computing the magnitude of vector(0, 1, 0)");
	given("v ← vector(0, 1, 0)", 0);
	v = set_vec((t_pos){0, 1, 0});
	result = vec_magnitude(v);
	expected = 1.0f;
	err[1] = test_print("magnitude(v) = 1", f_eq(result, expected));
	scenario_end(err[1]);

	scenario_start("Computing the magnitude of vector(0, 0, 1)");
	given("v ← vector(0, 0, 1)", 0);
	v = set_vec((t_pos){0, 0, 1});
	result = vec_magnitude(v);
	expected = 1.0f;
	err[2] = test_print("magnitude(v) = 1", f_eq(result, expected));
	scenario_end(err[2]);

	scenario_start("Computing the magnitude of vector(1, 2, 3)");
	given("v ← vector(1, 2, 3)", 0);
	v = set_vec((t_pos){1, 2, 3});
	result = vec_magnitude(v);
	expected = sqrtf(14.0f);
	err[3] = test_print("magnitude(v) = √14", f_eq(result, expected));
	scenario_end(err[3]);

	scenario_start("Computing the magnitude of vector(-1, -2, -3)");
	given("v ← vector(-1, -2, -3)", 0);
	v = set_vec((t_pos){-1, -2, -3});
	result = vec_magnitude(v);
	expected = sqrtf(14.0f);
	err[4] = test_print("magnitude(v) = √14", f_eq(result, expected));
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
	v = set_vec((t_pos){4, 0, 0});
	norm = vec_normalize(v);
	err[0] = test_print("normalize(v) = vector(1, 0, 0)",
			is_same_tuple(norm, set_vec((t_pos){1, 0, 0})));
	scenario_end(err[0]);

	scenario_start("Normalizing vector(1, 2, 3)");
	given("v ← vector(1, 2, 3)", 0);
	v = set_vec((t_pos){1, 2, 3});
	norm = vec_normalize(v);
	err[1] += test_print("normalize(v) = approximately vector(0.26726, 0.53452, 0.80178)",
			is_same_tuple(norm, set_vec((t_pos){0.26726, 0.53452, 0.801780})));
	scenario_end(err[1]);

	scenario_start("The magnitude of a normalized vector");
	given("v ← vector(1, 2, 3)", 0);
	v = set_vec((t_pos){1, 2, 3});
	norm = vec_normalize(v);
	magnitude_norm = vec_magnitude(norm);
	err[2] += test_print("magnitude(norm) = 1", f_eq(magnitude_norm, 1.0));
	scenario_end(err[2]);

	return (err[0] + err[1] + err[2]);
}
