/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:11:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/12 16:54:18 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	safe_pixel(t_data *pic, int x, int y, t_color color)
{
	if (ft_inr(x, 0, pic->width) && ft_inr(y, 0, pic->height))
		write_pixel(pic, x, y, color);
}

void	write_pixel(t_data *pic, int x, int y, t_color color)
{
	t_hxcol	pixel_col;

	pixel_col = t_color_to_hex(color);
	pixel_put(pic, x, y, pixel_col);
}

void	pixel_put(t_data *pic, int x, int y, t_hxcol color)
{
	char	*pixel;

	pixel = pic->addr
		+ (y * pic->line_length
			+ x * (pic->bits_per_pixel / 8));
	*(t_unt *)pixel = color;
}
