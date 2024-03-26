/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:11:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/26 19:57:18 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Reads a pixel on a screen
 *
 * @param screen
 * @param x
 * @param y
 * @return t_color
 */
t_color	pixel_at(t_canvas screen, t_unt x, t_unt y)
{
	t_color	pixel;
	char	*img;
	t_unt	offset;

	offset = (y * screen.width * 4) + (x * 4);
	img = screen.picture->addr;
	pixel.red = uchar_to_float(img[offset + 2]);
	pixel.green = uchar_to_float(img[offset + 1]);
	pixel.blue = uchar_to_float(img[offset]);
	pixel.tuple.w = 0;
	return (pixel);
}

/**
 * @brief Puts a pixel on a screen
 * checking prior if it fits inside the screen rage
 *
 * @param pic
 * @param x pos
 * @param y pos
 * @param color
 * @return true
 * @return false
 */
bool	safe_pixel(t_data *pic, int x, int y, t_color color)
{
	if (ft_inr(x, 0, pic->width) && ft_inr(y, 0, pic->height))
		return (write_pixel(pic, x, y, color), false);
	return (false);
}

/**
 * @brief puts a pixel on a screen taking a t_color
 * can fail if x r y are out of bounds
 * actually handles the translates the color to hex `pixel_put`
 *
 * @param pic
 * @param x
 * @param y
 * @param color
 */
void	write_pixel(t_data *pic, int x, int y, t_color color)
{
	t_hxcol	pixel_col;

	pixel_col = t_color_to_hex(color);
	pixel_put(pic, x, y, pixel_col);
}

/**
 * @brief puts a pixel on a screen taking a t_hex
 * can fail if x r y are out of bounds
 * basically the same as `write_pixel` but this one directly writes on *pic
 *
 * @param pic
 * @param x
 * @param y
 * @param color
 */
void	pixel_put(t_data *pic, int x, int y, t_hxcol color)
{
	char	*pixel;

	pixel = pic->addr
		+ (y * pic->line_length
			+ x * (pic->bits_per_pixel / 8));
	*(t_unt *)pixel = color;
}
