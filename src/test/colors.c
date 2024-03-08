/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:14:50 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 21:16:11 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_color_tuple(void)
{
	t_tuple	c;
	t_unt	err;

	scenario_start("Colors are (red, green, blue) tuples");

	given("c ← color(-0.5, 0.4, 1.7)", 0);
	c = set_col(-0.5, 0.4, 1.7);

	err = test_print("c.red = -0.5", f_eq(c.red, -0.5));
	err += test_print("c.green = 0.4", f_eq(c.green, 0.4));
	err += test_print("c.blue = 1.7", f_eq(c.blue, 1.7));

	scenario_end(err);

	return (err);
}
