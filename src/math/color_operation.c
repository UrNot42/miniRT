/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:57:43 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/13 19:08:19 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	hadamard_product(t_color c1, t_color c2)
{
	float	r;
	float	g;
	float	b;

	r = c1.red * c2.red;
	g = c1.green * c2.green;
	b = c1.blue * c2.blue;
	return (set_col(r, g, b));
}

t_hxcol	t_color_to_hex(t_color color)
{
	t_hxcol	hex_color;

	if (color.red > 1)
		color.red = 1;
	if (color.green > 1)
		color.green = 1;
	if (color.blue > 1)
		color.blue = 1;
	if (color.red < 0)
		color.red = 0;
	if (color.green < 0)
		color.green = 0;
	if (color.blue < 0)
		color.blue = 0;
	hex_color = float_to_uchar(color.red) << HEX_RED_OFFS
		| float_to_uchar(color.green) << HEX_GREEN_OFFS
		| float_to_uchar(color.blue) << HEX_BLUE_OFFS;
	return (hex_color);
}

float	uchar_to_float(t_uchar color)
{
	float	new_color;

	new_color = (float)(color / COL_SCALE);
	return (new_color);
}

t_uchar	float_to_uchar(float color)
{
	t_uchar	new_color;

	new_color = (t_uchar)(color * COL_SCALE);
	return (new_color);
}

t_color	tup_col(t_tuple a)
{
	return (set_col(a.x, a.y, a.z));
}
