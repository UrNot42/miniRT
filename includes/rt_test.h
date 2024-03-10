/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:37:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/10 19:32:58 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TEST_H
# define RT_TEST_H

# define LAUNCH_TEST_OK "[OK]\n##################\n\n"
# define LAUNCH_TEST_KO "[KO]\nXXXXXXXXXXXXXXXXXX\n\n"

void	tests_start(char *tests_name, t_unt a);
void	scenario_start(char *scenario_name);
t_unt	scenario_end(t_unt errors);
void	given(char *state, t_unt a);
void	when(char *state, t_unt a);
bool	then(char *test_name, bool status, t_unt a);

// Cucumber tests
t_unt	launch_tests(void);

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

#endif
