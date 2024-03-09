/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:02:07 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 20:51:11 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_matrix_init(void)
{
	t_4mtrx	m;
	t_unt	err;

	scenario_start("Constructing and inspecting a 4x4 matrix");
	given("the following 4x4 matrix M:", 0);
	m = set_4mtrx((t_i4mtr){1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9,
			10, 11, 12, 13.5, 14.5, 15.5, 16.5});
	err = test_print("M[0,0] = 1", f_eq(m[0][0], 1));
	err += test_print("M[0,3] = 4", f_eq(m[0][3], 4));
	err += test_print("M[1,0] = 5.5", f_eq(m[1][0], 5.5));
	err += test_print("M[1,2] = 7.5", f_eq(m[1][2], 7.5));
	err += test_print("M[2,2] = 11", f_eq(m[2][2], 11));
	err += test_print("M[3,0] = 13.5", f_eq(m[3][0], 13.5));
	err += test_print("M[3,2] = 15.5", f_eq(m[3][2], 15.5));
	scenario_end(err);
	return (err);
}
