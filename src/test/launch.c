/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:37:24 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 13:01:46 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	launch_tests(void)
{
	t_unt	err;

	err = launch_tuple_test();
	err += launch_vec_test();
	err += launch_col_test();
	ft_printf("===> All test finished");
	if (!err)
		ft_printf(" [OK]\n\nCongratulations\n");
	else
		ft_printf(": %d Errors [KO]\n", err);
	return (err);
}

t_unt	launch_col_test(void)
{
	t_unt	err;

	err = test_color_tuple();
	err += test_color_operations();
	err += test_multiply_colors();
	ft_printf("==> Finished Color tests with %d Errors ", err);
	if (!err)
		ft_printf("[OK]\n#########\n");
	else
		ft_printf("[KO]\nXXXXXXXXX\n");
	return (err);
}

t_unt	launch_vec_test(void)
{
	t_unt	err;

	err = test_magnitude_vector();
	err += test_vector_normalization();
	err += test_dot_product();
	err += test_cross_product();
	ft_printf("==> Finished Vector tests with %d Errors ", err);
	if (!err)
		ft_printf("[OK]\n#########\n");
	else
		ft_printf("[KO]\nXXXXXXXXX\n");
	return (err);
}

t_unt	launch_tuple_test(void)
{
	t_unt	err;

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
		ft_printf("[OK]\n#########\n");
	else
		ft_printf("[KO]\nXXXXXXXXX\n");
	return (err);
}
