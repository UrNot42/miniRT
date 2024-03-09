/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:11:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 14:11:13 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	*init_canvas(t_canvas *mlx, t_dim size)
{
	mlx->name = WINDOW_NAME;
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (NULL);
	return (NULL);
}

void	start_canvas_loop_hooks(t_params *param)
{
	start_canvas_win_hooks(param);
	mlx_loop_hook(param->mlx.ptr, game, param);
	mlx_loop(param->mlx.ptr);
}

/**
 * @brief personnalized function that puts
 * inside the data element the indicated color pixel
 *
 * @param data the image we are putting the pixel inside of
 * @param x coordinate of where on a certain like to put the pixel
 * @param y coordinate of which line to put the pixel to
 * @param color
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
