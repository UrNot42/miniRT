/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:37:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 18:34:45 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TEST_H
# define RT_TEST_H

void	scenario_start(char *scenario_name);
t_unt	scenario_end(t_unt errors);
void	given(char *state, t_unt a);
bool	test_print(char *test_name, bool status);

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

#endif
