/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:50:39 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 13:29:01 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_translation_multiplication(void)
{
	t_4mtrx	transform;
	t_tuple	p;
	t_unt	err;

	scenario_start("Multiplying by a translation matrix");
	given("transform ← translation(5, -3, 2)", 0);
	transform = translation_mtrx(5, -3, 2);
	given("p ← point(-3, 4, 5)", 1);
	p = set_point(-3, 4, 5);
	err = then("transform * p = point(2, 1, 7)",
			tup_eq(tup_mtrx(transform, p), set_point(2, 1, 7)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_translation_inverse(void)
{
	t_4mtrx	transform;
	t_tuple	p;
	t_unt	err;

	scenario_start("Multiplying by the inverse of a translation matrix");
	given("transform ← translation(5, -3, 2)", 0);
	transform = translation_mtrx(5, -3, 2);
	given("inv ← inverse(transform)", 1);
	transform = inverse_4mtrx(transform);
	given("p ← point(-3, 4, 5)", 2);
	p = set_point(-3, 4, 5);
	err = then("inv * p = point(-8, 7, 3)",
			tup_eq(tup_mtrx(transform, p), set_point(-8, 7, 3)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_translation_vector(void)
{
	t_4mtrx	transform;
	t_tuple	v;
	t_unt	err;

	scenario_start("Translation does not affect vectors");
	given("transform ← translation(5, -3, 2)", 0);
	transform = translation_mtrx(5, -3, 2);
	given("v ← vector(-3, 4, 5)", 1);
	v = set_vec(-3, 4, 5);
	err = then("transform * v = v",
			tup_eq(tup_mtrx(transform, v), v), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_scaling_matrix_point(void)
{
	t_4mtrx	transform;
	t_tuple	p;
	t_unt	err;

	scenario_start("A scaling matrix applied to a point");
	given("transform ← scaling(2, 3, 4)", 0);
	transform = scale_mtrx(2, 3, 4);
	given("p ← point(-4, 6, 8)", 1);
	p = set_point(-4, 6, 8);
	err = then("transform * p = point(-8, 18, 32)",
			tup_eq(tup_mtrx(transform, p), set_point(-8, 18, 32)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_scaling_matrix_vect(void)
{
	t_4mtrx	transform;
	t_tuple	v;
	t_unt	err;

	scenario_start("A scaling matrix applied to a vector");
	given("transform ← scaling(2, 3, 4)", 0);
	transform = scale_mtrx(2, 3, 4);
	given("v ← vector(-4, 6, 8)", 1);
	v = set_vec(-4, 6, 8);
	err = then("transform * v = vector(-8, 18, 32)",
			tup_eq(tup_mtrx(transform, v), set_vec(-8, 18, 32)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_scaling_matrix_inv_vect(void)
{
	t_4mtrx	transform;
	t_tuple	v;
	t_unt	err;

	scenario_start("Multiplying by the inverse of a scaling matrix");
	given("transform ← scaling(2, 3, 4)", 0);
	transform = scale_mtrx(2, 3, 4);
	given("inv ← inverse(transform)", 1);
	transform = inverse_4mtrx(transform);
	given("v ← vector(-4, 6, 8)", 2);
	v = set_vec(-4, 6, 8);
	err = then("inv * v = vector(-2, 2, 2)",
			tup_eq(tup_mtrx(transform, v), set_vec(-2, 2, 2)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_reflection_point(void)
{
	t_4mtrx	transform;
	t_tuple	p;
	t_unt	err;

	scenario_start("Reflection is scaling by a negative value");
	given("transform ← scaling(-1, 1, 1)", 0);
	transform = scale_mtrx(-1, 1, 1);
	given("p ← point(2, 3, 4)", 1);
	p = set_point(2, 3, 4);
	err = then("transform * p = point(-2, 3, 4)",
			tup_eq(tup_mtrx(transform, p), set_point(-2, 3, 4)), 0);
	scenario_end(err);
	return (err);
}

void	print_tup(t_tuple a, bool tab)
{
	if (tab)
		printf("\t\t");
	if (is_point(a))
		printf("Point");
	else if (is_vec(a))
		printf("Vector");
	printf(": {x: %f, y: %f, z: %f}\n", a.x, a.y, a.z);
}

t_unt	test_rotation_x(void)
{
	t_4mtrx	half_quarter;
	t_4mtrx	full_quarter;
	t_tuple	p;
	t_unt	err;

	scenario_start("Rotating a point around the x axis");
	given("p ← point(0, 1, 0)", 0);
	p = set_point(0, 1, 0);
	given("half_quarter ← rotation_x(π / 4)", 1);
	half_quarter = rotation_x(M_PI / 4);
	given("full_quarter ← rotation_x(π / 2)", 2);
	full_quarter = rotation_x(M_PI / 2);
	err = then("half_quarter * p = point(0, √2/2, √2/2)",
			tup_eq(tup_mtrx(half_quarter, p),
				set_point(0, sqrtf(2) / 2, sqrtf(2) / 2)), 0);
	err += then("full_quarter * p = point(0, 0, 1)",
			tup_eq(tup_mtrx(full_quarter, p), set_point(0, 0, 1)), 1);
	scenario_end(err);
	return (err);
}

t_unt	test_rotation_x_inv(void)
{
	t_4mtrx	half_quarter;
	t_tuple	p;
	t_unt	err;

	scenario_start("The inverse of an x-rotation rotates\
 in the opposite direction");
	given("p ← point(0, 1, 0)", 0);
	p = set_point(0, 1, 0);
	given("half_quarter ← rotation_x(π / 4)", 1);
	half_quarter = rotation_x(M_PI / 4);
	given("inv ← inverse(half_quarter)", 2);
	half_quarter = inverse_4mtrx(half_quarter);
	err = then("inv * p = point(0, √2/2, -√2/2)",
			tup_eq(tup_mtrx(half_quarter, p),
				set_point(0, sqrtf(2) / 2, -sqrtf(2) / 2)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_rotation_y(void)
{
	t_4mtrx	half_quarter;
	t_4mtrx	full_quarter;
	t_tuple	p;
	t_unt	err;

	scenario_start("Rotating a point around the y axis");
	given("p ← point(0, 0, 1)", 0);
	p = set_point(0, 0, 1);
	given("half_quarter ← rotation_y(π / 4)", 1);
	half_quarter = rotation_y(M_PI / 4);
	given("full_quarter ← rotation_y(π / 2)", 2);
	full_quarter = rotation_y(M_PI / 2);
	err = then("half_quarter * p = point(√2/2, 0, √2/2)",
			tup_eq(tup_mtrx(half_quarter, p),
				set_point(sqrtf(2) / 2, 0, sqrtf(2) / 2)), 0);
	err += then("full_quarter * p = point(1, 0, 0)",
			tup_eq(tup_mtrx(full_quarter, p), set_point(1, 0, 0)), 1);
	scenario_end(err);
	return (err);
}

t_unt	test_rotation_z(void)
{
	t_4mtrx	half_quarter;
	t_4mtrx	full_quarter;
	t_tuple	p;
	t_unt	err;

	scenario_start("Rotating a point around the z axis");
	given("p ← point(0, 1, 0)", 0);
	p = set_point(0, 1, 0);
	given("half_quarter ← rotation_z(π / 4)", 1);
	half_quarter = rotation_z(M_PI / 4);
	given("full_quarter ← rotation_z(π / 2)", 2);
	full_quarter = rotation_z(M_PI / 2);
	err = then("half_quarter * p = point(-√2/2, √2/2, 0)",
			tup_eq(tup_mtrx(half_quarter, p),
				set_point(-sqrtf(2) / 2, sqrtf(2) / 2, 0)), 0);
	err += then("full_quarter * p = point(-1, 0, 0)",
			tup_eq(tup_mtrx(full_quarter, p), set_point(-1, 0, 0)), 1);
	scenario_end(err);
	return (err);
}

t_unt	test_shearing(void)
{
	t_4mtrx	transform;
	t_tuple	p;
	t_unt	err;

	scenario_start("A shearing transformation moves x in proportion to y");
	given("transform ← shearing(1, 0, 0, 0, 0, 0)", 0);
	transform = shearing((t_shear){1, 0, 0, 0, 0, 0});
	given("p ← point(2, 3, 4)", 1);
	p = set_point(2, 3, 4);
	err = then("transform * p = point(5, 3, 4)",
			tup_eq(tup_mtrx(transform, p), set_point(5, 3, 4)), 0);
	scenario_end(err);

	scenario_start("A shearing transformation moves x in proportion to z");
	given("transform ← shearing(0, 1, 0, 0, 0, 0)", 0);
	transform = shearing((t_shear){0, 1, 0, 0, 0, 0});
	given("p ← point(2, 3, 4)", 1);
	p = set_point(2, 3, 4);
	err = then("transform * p = point(6, 3, 4)",
			tup_eq(tup_mtrx(transform, p), set_point(6, 3, 4)), 0);
	scenario_end(err);

	scenario_start("A shearing transformation moves y in proportion to x");
	given("transform ← shearing(0, 0, 1, 0, 0, 0)", 0);
	transform = shearing((t_shear){0, 0, 1, 0, 0, 0});
	given("p ← point(2, 3, 4)", 1);
	p = set_point(2, 3, 4);
	err = then("transform * p = point(2, 5, 4)",
			tup_eq(tup_mtrx(transform, p), set_point(2, 5, 4)), 0);
	scenario_end(err);

	scenario_start("A shearing transformation moves y in proportion to z");
	given("transform ← shearing(0, 0, 0, 1, 0, 0)", 0);
	transform = shearing((t_shear){0, 0, 0, 1, 0, 0});
	given("p ← point(2, 3, 4)", 1);
	p = set_point(2, 3, 4);
	err = then("transform * p = point(2, 7, 4)",
			tup_eq(tup_mtrx(transform, p), set_point(2, 7, 4)), 0);
	scenario_end(err);

	scenario_start("A shearing transformation moves z in proportion to x");
	given("transform ← shearing(0, 0, 0, 0, 1, 0)", 0);
	transform = shearing((t_shear){0, 0, 0, 0, 1, 0});
	given("p ← point(2, 3, 4)", 1);
	p = set_point(2, 3, 4);
	err = then("transform * p = point(2, 3, 6)",
			tup_eq(tup_mtrx(transform, p), set_point(2, 3, 6)), 0);
	scenario_end(err);

	scenario_start("A shearing transformation moves z in proportion to y");
	given("transform ← shearing(0, 0, 0, 0, 0, 1)", 0);
	transform = shearing((t_shear){0, 0, 0, 0, 0, 1});
	given("p ← point(2, 3, 4)", 1);
	p = set_point(2, 3, 4);
	err = then("transform * p = point(2, 3, 7)",
			tup_eq(tup_mtrx(transform, p), set_point(2, 3, 7)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_sequence_transformations(void)
{
	t_4mtrx	a;
	t_4mtrx	b;
	t_4mtrx	c;
	t_tuple	p[4];
	t_unt	err;

	scenario_start("Individual transformations are applied in sequence");
	given("p ← point(1, 0, 1)", 0);
	p[0] = set_point(1, 0, 1);
	given("A ← rotation_x(π / 2)", 1);
	a = rotation_x(M_PI / 2);
	given("B ← scaling(5, 5, 5)", 2);
	b = scale_mtrx(5, 5, 5);
	given("C ← translation(10, 5, 7)", 3);
	c = translation_mtrx(10, 5, 7);
	when("p2 ← A * p", 0);
	p[1] = tup_mtrx(a, p[0]);
	err = then("p2 = point(1, -1, 0)",
			tup_eq(p[1], set_point(1, -1, 0)), 0);
	when("p3 ← B * p2", 0);
	p[2] = tup_mtrx(b, p[1]);
	err += then("p3 = point(5, -5, 0)",
			tup_eq(p[2], set_point(5, -5, 0)), 0);
	when("p4 ← C * p3", 0);
	p[3] = tup_mtrx(c, p[2]);
	err += then("p4 = point(15, 0, 7)",
			tup_eq(p[3], set_point(15, 0, 7)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_rev_sequence_transformations(void)
{
	t_4mtrx	a;
	t_4mtrx	b;
	t_4mtrx	c;
	t_tuple	p;
	t_unt	err;

	scenario_start("Chained transformations must be applied in reverse order");
	given("p ← point(1, 0, 1)", 0);
	p = set_point(1, 0, 1);
	given("A ← rotation_x(π / 2)", 1);
	a = rotation_x(M_PI / 2);
	given("B ← scaling(5, 5, 5)", 2);
	b = scale_mtrx(5, 5, 5);
	given("C ← translation(10, 5, 7)", 3);
	c = translation_mtrx(10, 5, 7);
	when("T ← C * B * A", 0);
	a = c * b * a;
	err = then("T * p = point(15, 0, 7)",
			tup_eq(tup_mtrx(a, p), set_point(15, 0, 7)), 0);
	scenario_end(err);
	return (err);
}
