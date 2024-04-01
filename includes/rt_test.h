/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:37:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/31 20:39:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TEST_H
# define RT_TEST_H

# define LAUNCH_TEST_OK "[OK]\n##################\n\n"
# define LAUNCH_TEST_KO "[KO]\nXXXXXXXXXXXXXXXXXX\n\n"

void	tests_start(char *tests_name, t_unt count);
void	scenario_start(char *scenario_name);
t_unt	scenario_end(t_unt errors);
void	given(char *state, t_unt count);
void	when(char *state, t_unt count);
bool	then(char *test_name, bool status, t_unt count);
void	tests_start(char *tests_name, t_unt a);
void	tests_end(char *name, t_unt err);
bool	ex(char *state, bool test);

// prints
void	print_m(t_4mtrx a, char name);
void	print_tup(t_tuple a, bool tab);
void	print_obj(t_obj *obj);

// Cucumber tests
t_unt	launch_tests(void);

// Scenes
t_scene	scene_hex(t_color backdrop);
t_scene	scene_studio(t_color backdrop);
t_scene	scene_cube(t_color backdrop);
t_scene	scene_cooloon(t_color backdrop);
t_scene	scene_cylinder(t_color backdrop);
t_scene	scene_cone(t_color backdrop);
t_scene	scene_sphere(t_color backdrop);
t_scene	scene_multi_light(t_color backdrop);
t_scene	scene_example(t_color backdrop);

// Tuples
t_unt	launch_tuple_test(void);
t_unt	test_tuple(void);
t_unt	test_point_vec(void);
t_unt	test_tuple_add(void);
t_unt	test_sub_pts(void);
t_unt	test_sub_pt_vec(void);
t_unt	test_sub_vects(void);
t_unt	test_sub_zero_vec(void);
t_unt	test_neg_tuple(void);
t_unt	test_multiply_tuple(void);
t_unt	test_divide_tuple(void);

// Vectors
t_unt	launch_vec_test(void);
t_unt	test_magnitude_vector(void);
t_unt	test_vector_normalization(void);
t_unt	test_dot_product(void);
t_unt	test_cross_product(void);

//color
t_unt	launch_col_test(void);
t_unt	test_color_tuple(void);
t_unt	test_color_operations(void);
t_unt	test_multiply_colors(void);

// Graphic
t_unt	launch_canvas_test(void);
t_unt	test_create_canvas(void);
t_unt	test_write_pixel_to_canvas(void);

// Matrix
t_unt	launch_matrix_test(void);
t_unt	test_matrix_4_init(void);
t_unt	test_matrix_2_3_init(void);
t_unt	test_matrix_equality(void);
t_unt	test_matrix_mult(void);
t_unt	test_matrix_by_tuple(void);
t_unt	test_matrix_identity(void);
t_unt	test_matrix_transpose(void);
t_unt	test_transpose_identity(void);
t_unt	test_2x2_matrix_det(void);
t_unt	test_submatrix(void);
t_unt	test_minor_3x3(void);
t_unt	test_cofactor_3x3(void);
t_unt	test_determinant_3x3(void);
t_unt	test_determinant_4x4(void);
t_unt	test_invertibility(void);
t_unt	test_matrix_inverse(void);
t_unt	test_matrix_inverse_another(void);
t_unt	test_matrix_inverse_third(void);
t_unt	test_matrix_multiply_inverse(void);
t_unt	test_inverse_identity_matrix(void);
t_unt	test_matrix_mult_inverse(void);

// Transform
t_unt	launch_matrix_transform_test(void);
t_unt	test_translation_multiplication(void);
t_unt	test_translation_inverse(void);
t_unt	test_translation_vector(void);
t_unt	test_scaling_matrix_point(void);
t_unt	test_scaling_matrix_vect(void);
t_unt	test_scaling_matrix_inv_vect(void);
t_unt	test_reflection_point(void);
t_unt	test_rotation_x(void);
t_unt	test_rotation_x_inv(void);
t_unt	test_rotation_y(void);
t_unt	test_rotation_z(void);
t_unt	test_shearing(void);
t_unt	test_sequence_transformations(void);
t_unt	test_rev_sequence_transformations(void);

// Rays
t_unt	launch_rays_test(void);
t_unt	test_creating_ray(void);
t_unt	test_position_ray(void);
t_unt	test_intersect_sphere(void);
t_unt	test_sphere_tangent(void);
t_unt	test_ray_miss_sphere(void);
t_unt	test_ray_inside_sphere(void);
t_unt	test_sphere_behind_ray(void);

t_unt	test_inter_struct(void);
t_unt	test_agregating_inter(void);
t_unt	test_intersect_obj(void);
t_unt	test_hits(void);

t_unt	test_translate_ray(void);
t_unt	test_sphere_transformation(void);
t_unt	test_ray_sphere_transform(void);

// Normal
t_unt	launch_normal_test(void);
t_unt	test_sphere_normal(void);
t_unt	test_norm_normal_vec(void);
t_unt	test_normal_on_transformed(void);
t_unt	test_reflect_45(void);
t_unt	test_reflect_slanted(void);
t_unt	test_point_init(void);
t_unt	test_material(void);
t_unt	test_default_mater(void);

// Light
t_unt	launch_light_test(void);
t_unt	test_light_eye_between(void);
t_unt	test_light_eye_between_ofst_45(void);
t_unt	test_light_eye_opposite_ofst_45(void);
t_unt	test_light_eye_in_path(void);
t_unt	test_light_behind_surface(void);

// Shadow
t_unt	launch_shadow_test(void);
t_unt	test_shadow_light_surface(void);
t_unt	test_shadow_point_between(void);
t_unt	test_shade_hit_inter_shadowed(void);
t_unt	test_hit_offset_point(void);

// World
t_unt	launch_world_test(void);
t_unt	test_world(void);
t_unt	test_world_default(void);
t_unt	test_inter_world(void);

// Precompute
t_unt	launch_compute_test(void);
t_unt	test_precomputation(void);
t_unt	test_hit_inoutside(void);
t_unt	test_shading_w_precomps(void);
t_unt	test_color_at(void);
t_unt	test_color_behind(void);

//view
t_unt	launch_view_test(void);
t_unt	test_view_default(void);
t_unt	test_view_z_positive(void);
t_unt	test_view_moves_world(void);
t_unt	test_view_transfrom(void);
t_unt	test_cam_constructing(void);
t_unt	test_cam_pix_size(void);
t_unt	test_cam_ray_construction(void);
t_unt	test_cam_rendering(void);

// Shapes
t_unt	launch_shape_test(void);
t_unt	test_cube_inters(void);
t_unt	test_cube_normal(void);

#endif

/* t_unt	test_(void)
{
	t_unt	err;

	scenario_start("");
	given("", 0);
	given("", 1);
	when("", 0);
	err = then("", 0, 0);
	err += then("", 0, 1);
	scenario_end(err);
	return (err);
} */

/* t_unt	test_(void)
{
	t_unt	err[2];

	scenario_start("");
	given("", 0);
	given("", 1);
	when("", 0);
	err[0] = then("", 0, 0);
	err[0] += then("", 0, 1);
	scenario_end(err[0]);
	scenario_start("");
	given("", 0);
	given("", 1);
	when("", 0);
	err[1] = then("", 0, 0);
	err[1] += then("", 0, 1);
	scenario_end(err[1]);
	return (err[0] + err[1]);
} */
