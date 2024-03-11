/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:37:24 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/11 12:51:39 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	tests_start(char *tests_name, t_unt a)
{
	if (a)
		ft_printf(">");
	ft_printf("Starting %s \\/\n", tests_name);
}

t_unt	launch_tests(void)
{
	t_unt	err;

	tests_start("All tests", 0);
	err = launch_tuple_test();
	err += launch_vec_test();
	err += launch_col_test();
	err += launch_canvas_test();
	err += launch_matrix_test();
	err += launch_matrix_transform_test();
	ft_printf("===> All test finished");
	if (!err)
		ft_printf(" [OK]\n\nCongratulations\n");
	else
		ft_printf(": %d Errors "LAUNCH_TEST_KO, err);
	return (err);
}

t_unt	launch_matrix_transform_test(void)
{
	t_unt	err;

	tests_start("Matrix tests", 1);
	err = test_translation_multiplication();
	err += test_translation_inverse();
	err += test_translation_vector();
	err += test_scaling_matrix_point();
	err += test_scaling_matrix_vect();
	err += test_scaling_matrix_inv_vect();
	err += test_reflection_point();
	err += test_rotation_x();
	err += test_rotation_x_inv();
	err += test_rotation_y();
	err += test_rotation_z();
	err += test_shearing();
	// err += ();
	ft_printf("==> Finished Matrix Transform tests with %d Errors ", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}

t_unt	launch_matrix_test(void)
{
	t_unt	err;

	tests_start("Matrix tests", 1);
	err = test_matrix_4_init();
	err += test_matrix_2_3_init();
	err += test_matrix_equality();
	err += test_matrix_mult();
	err += test_matrix_by_tuple();
	err += test_matrix_identity();
	err += test_matrix_transpose();
	err += test_transpose_identity();
	err += test_2x2_matrix_det();
	err += test_submatrix();
	err += test_minor_3x3();
	err += test_cofactor_3x3();
	err += test_determinant_3x3();
	err += test_determinant_4x4();
	err += test_invertibility();
	err += test_matrix_inverse();
	err += test_matrix_inverse_another();
	err += test_matrix_inverse_third();
	err += test_matrix_multiply_inverse();
	err += test_inverse_identity_matrix();
	err += test_matrix_mult_inverse();
	ft_printf("==> Finished Matrix tests with %d Errors ", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}

t_unt	launch_canvas_test(void)
{
	t_unt	err;

	tests_start("Canvas tests", 1);
	err = test_create_canvas();
	err += test_write_pixel_to_canvas();
	ft_printf("==> Finished Canvas tests with %d Errors ", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}

t_unt	launch_col_test(void)
{
	t_unt	err;

	tests_start("Color tests", 1);
	err = test_color_tuple();
	err += test_color_operations();
	err += test_multiply_colors();
	ft_printf("==> Finished Color tests with %d Errors ", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}

t_unt	launch_vec_test(void)
{
	t_unt	err;

	tests_start("Vector tests", 1);
	err = test_magnitude_vector();
	err += test_vector_normalization();
	err += test_dot_product();
	err += test_cross_product();
	ft_printf("==> Finished Vector tests with %d Errors ", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}

t_unt	launch_tuple_test(void)
{
	t_unt	err;

	tests_start("Tuple tests", 1);
	err = test_tuple();
	err += test_point_vec();
	err += test_tuple_add();
	err += test_sub_pts();
	err += test_sub_pt_vec();
	err += test_sub_vects();
	err += test_sub_zero_vec();
	err += test_neg_tuple();
	err += test_multiply_tuple();
	err += test_divide_tuple();
	ft_printf("==> Finished Tuple tests with %d Errors ", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}
