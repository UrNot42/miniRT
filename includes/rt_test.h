/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:37:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 15:59:32 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TEST_H
# define RT_TEST_H

void	scenario_start(char *scenario_name);
t_unt	scenario_end(t_unt errors);
void	given(char *state, t_unt a);
bool	test_print(char *test_name, bool status);

// Cucumber tests
t_unt	launch_tup_pts_vec_test(void);
bool	test_tuple(void);
bool	test_point_vec(void);
bool	test_tuple_add(void);
bool	test_sub_pts(void);
bool	test_sub_pt_vec(void);
bool	test_sub_vects(void);

#endif
