/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:57:43 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/26 19:31:32 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Hadamard product allows colors to be multiplied together
 *
 * @param c1
 * @param c2
 * @return t_color
 */
t_color	hadamard_product(t_color c1, t_color c2)
{
	t_color	color;

	color.tuple = c1.tuple * c2.tuple;
	return (color);
}

/**
 * @brief gets hex color ready for printing to screen
 *
 * @param color
 * @return t_hxcol
 */
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

/**
 * @brief coverts value to be able to ready to be read
 *
 * @param color
 * @return float
 */
float	uchar_to_float(t_uchar color)
{
	float	new_color;

	new_color = (float)((float)(color) / COL_SCALE);
	return (new_color);
}

/**
 * @brief translates a single float to a 8 bits variable (0-255)
 *
 * @param color
 * @return t_uchar
 */
t_uchar	float_to_uchar(float color)
{
	t_uchar	new_color;

	new_color = (t_uchar)(color * COL_SCALE);
	return (new_color);
}

/**
 * @brief basic conversion from t_tuple to t_color
 *
 * @param a
 * @return t_color
 */
t_color	tup_col(t_tuple a)
{
	return (set_col(a.x, a.y, a.z));
}
