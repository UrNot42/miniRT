/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:26:50 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/27 10:41:31 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_sphere_normal(void)
{
	t_obj	s;
	t_tuple	n;
	t_unt	err[4];

	s = o_sphere();
	scenario_start("The normal on a sphere at a point on the x axis");
	given("s ← sphere()", 0);
	when("n ← normal_at(s, point(1, 0, 0))", 0);
	n = normal_at(s, set_point(1, 0, 0));
	err[0] = then("n = vector(1, 0, 0)", is_same_tuple(n, set_vec(1, 0, 0)), 0);
	scenario_end(err[0]);

	scenario_start("The normal on a sphere at a point on the y axis");
	given("s ← sphere()", 0);
	when("n ← normal_at(s, point(0, 1, 0))", 0);
	n = normal_at(s, set_point(0, 1, 0));
	err[1] = then("n = vector(0, 1, 0)", is_same_tuple(n, set_vec(0, 1, 0)), 0);
	scenario_end(err[1]);

	scenario_start("The normal on a sphere at a point on the z axis");
	given("s ← sphere()", 0);
	when("n ← normal_at(s, point(0, 0, 1))", 0);
	n = normal_at(s, set_point(0, 0, 1));
	err[2] = then("n = vector(0, 0, 1)", is_same_tuple(n, set_vec(0, 0, 1)), 0);
	scenario_end(err[2]);

	scenario_start("The normal on a sphere at a nonaxial point");
	given("s ← sphere()", 0);
	when("n ← normal_at(s, point(√3/3, √3/3, √3/3))", 0);
	n = normal_at(s, set_point(sqrtf(3) / 3, sqrtf(3) / 3, sqrtf(3) / 3));
	err[3] = then("n = vector(√3/3, √3/3, √3/3)", is_same_tuple(n,
				set_vec(sqrtf(3) / 3, sqrtf(3) / 3, sqrtf(3) / 3)), 0);
	scenario_end(err[3]);
	return (err[0] + err[1] + err[2] + err[3]);
}

t_unt	test_norm_normal_vec(void)
{
	t_obj	s;
	t_tuple	n;
	t_unt	err;

	scenario_start("The normal is a normalized vector");
	given("s ← sphere()", 0);
	s = o_sphere();
	when("n ← normal_at(s, point(√3/3, √3/3, √3/3))", 0);
	n = normal_at(s, set_point(sqrtf(3) / 3, sqrtf(3) / 3, sqrtf(3) / 3));
	err = then("n = normalize(n)", is_same_tuple(n, vec_norm(n)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_normal_on_transformed(void)
{
	t_obj	s;
	t_tuple	n;
	t_4mtrx	m;
	t_unt	err[2];

	scenario_start("Computing the normal on a translated sphere");
	given("s ← sphere()", 0);
	s = o_sphere();
	given("set_transform(s, translation(0, 1, 0))", 1);
	set_transform(&s.sphere.mtx, translation_mtrx(0, 1, 0));
	when("n ← normal_at(s, point(0, 1.70711, -0.70711))", 0);
	n = normal_at(s, set_point(0, 1.70711, -0.70711));
	err[0] = then("n = vector(0, 0.70711, -0.70711)",
			is_same_tuple(n, set_vec(0, 0.70711, -0.70711)), 0);
	scenario_end(err[0]);

	scenario_start("Computing the normal on a transformed sphere");
	given("s ← sphere()", 0);
	given("m ← scaling(1, 0.5, 1) * rotation_z(π/5)", 1);
	m = scale_mtrx(1, 0.5, 1) * rotation_z(M_PI / 5);
	given("set_transform(s, m)", 2);
	set_transform(&s.sphere.mtx, m);
	when("n ← normal_at(s, point(0, √2/2, -√2/2))", 0);
	n = normal_at(s, set_point(0, sqrtf(2) / 2, -sqrtf(2) / 2));
	err[1] = then("n = vector(0, 0.97014, -0.24254)",
			is_same_tuple(n, set_vec(0, 0.97014, -0.24254)), 0);
	scenario_end(err[1]);
	return (err[0] + err[1]);
}
