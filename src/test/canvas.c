/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:34:23 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 13:29:01 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_create_canvas(void)
{
	t_canvas	c;
	t_color		pixel;
	t_unt		err[2];

	scenario_start("Creating a canvas");
	given("c ← canvas(10, 20)", 0);
	c = canvas(10, 20);
	err[0] = then("c.width = 10", c.width == 10, 0);
	err[0] += then("c.height = 20", c.height == 20, 1);
	err[1] = 0;
	for (t_unt y = 0; y < c.height; y++) {
		for (t_unt x = 0; x < c.width; x++) {
			pixel = pixel_at(c, x, y);
			if (pixel.red != 0 || pixel.green != 0 || pixel.blue != 0)
			{
				err[1]++;
				break ;
			}
		}
	}
	err[0] += then("every pixel of c is color(0, 0, 0)", err[1] == 0, 2);
	close_canvas(&c);
	scenario_end(err[0]);
	return (err[0]);
}

t_unt	test_write_pixel_to_canvas(void)
{
	t_canvas	c;
	t_color		red;
	t_color		pixel;
	t_unt		err;

	scenario_start("Writing pixels to a canvas");
	given("c ← canvas(10, 20)", 0);
	given("red ← color(1, 0, 0)", 0);
	c = canvas(10, 20);
	red = set_col(1, 0, 0);
	write_pixel(c.picture, 2, 3, red);
	pixel = pixel_at(c, 2, 3);
	err = then("pixel_at(c, 2, 3) = red",
			tup_eq(pixel.tuple, red.tuple), 0);
	close_canvas(&c);
	scenario_end(err);

	return (err);
}
