/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:37:24 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/20 16:04:16 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	err += launch_rays_test();
	err += launch_normal_test();
	err += launch_world_test();
	err += launch_compute_test();
	ft_printf("===> All tests finished");
	if (!err)
		ft_printf(" [OK]\n\nCongratulations\n");
	else
	{
		if (err)
		{
			ft_printf(": %d Error", err);
			if (err > 1)
				ft_printf("s");
			ft_printf(" "LAUNCH_TEST_KO);
		}
	}
	return (err);
}

t_unt	launch_compute_test(void)
{
	t_unt	err;

	tests_start("Pre Computation Structure", 1);
	err = test_precomputation();
	err += test_hit_inoutside();
	err += test_shading_w_precomps();
	err += test_color_at();
	err += test_color_behind();
	tests_end("Pre Computation Structure", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}

t_unt	launch_world_test(void)
{
	t_unt	err;

	tests_start("World", 1);
	err = test_world();
	err += test_world_default();
	err += test_inter_world();
	tests_end("World", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}

t_unt	launch_normal_test(void)
{
	t_unt	err;

	tests_start("Normal", 1);
	err = test_sphere_normal();
	err += test_norm_normal_vec();
	err += test_normal_on_transformed();
	err += test_reflect_45();
	err += test_reflect_slanted();
	err += test_material();
	err += test_default_mater();
	err += test_light_eye_between();
	err += test_light_eye_between_ofst_45();
	err += test_light_eye_opposite_ofst_45();
	err += test_light_eye_in_path();
	err += test_light_behind_surface();
	tests_end("Normal", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}

t_unt	launch_rays_test(void)
{
	t_unt	err;

	tests_start("Rays", 1);
	err = test_creating_ray();
	err += test_position_ray();
	err += test_intersect_sphere();
	err += test_sphere_tangent();
	err += test_ray_miss_sphere();
	err += test_ray_inside_sphere();
	err += test_sphere_behind_ray();
	err += test_inter_struct();
	err += test_agregating_inter();
	err += test_intersect_obj();
	err += test_hits();
	err += test_translate_ray();
	err += test_sphere_transformation();
	err += test_ray_sphere_transform();
	tests_end("Rays", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}

t_unt	launch_matrix_transform_test(void)
{
	t_unt	err;

	tests_start("Matrix", 1);
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
	err += test_sequence_transformations();
	err += test_rev_sequence_transformations();
	tests_end("Matrix Transform", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}

t_unt	launch_matrix_test(void)
{
	t_unt	err;

	tests_start("Matrix", 1);
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
	tests_end("Matrix", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}

t_unt	launch_canvas_test(void)
{
	t_unt	err;

	tests_start("Canvas", 1);
	err = test_create_canvas();
	err += test_write_pixel_to_canvas();
	tests_end("Canvas", err);
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
	tests_end("Color tests", err);
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
	tests_end("Vector tests", err);
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
	tests_end("Tuple tests", err);
	if (!err)
		ft_printf(LAUNCH_TEST_OK);
	else
		ft_printf(LAUNCH_TEST_KO);
	return (err);
}
