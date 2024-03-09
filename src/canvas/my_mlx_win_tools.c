/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_win_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:08:33 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 14:11:13 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_window(t_canvas *mlx, t_dim size)
{
	if (!make_window_image(mlx, size))
		return (mlx_destroy_display(mlx->ptr), NULL);
	if (mlx->win)
		free(mlx->win);
	mlx->win = mlx_new_window(mlx->ptr, mlx->data->width, mlx->data->height,
			mlx->name);
	if (!mlx->win)
		return (mlx_destroy_display(mlx->ptr), free(mlx->data), NULL);
	return (mlx->win);
}

// TODO MOD PARAM
void	start_canvas_win_hooks(t_canvas mlx, int param)
{
	mlx_hook(mlx.win, KeyPress, KeyPressMask, key_press, param);
	mlx_hook(mlx.win, DestroyNotify, 0, close_game, param);
}

/* Templates for mouse integration

	mlx_hook(param->mlx.win, ButtonPress, ButtonPressMask, mousse_press, param);
	mlx_hook(param->mlx.win, ButtonRelease, ButtonReleaseMask, mouse_enter, param);
	mlx_hook(param->mlx.win, MotionNotify, ButtonMotionMask, mouse_move, param);
	mlx_hook(param->mlx.win, KeyRelease, KeyReleaseMask, key_pause_pressed, param);
*/
int	ft_close_win(t_canvas mlx)
{
	if (mlx.ptr && mlx.data && mlx.data->img)
		mlx_destroy_image(mlx.ptr, mlx.data->img);
	if (mlx.data)
		free(mlx.data);
	if (!mlx.ptr || !mlx.win)
		return (EXIT_FAILURE);
	mlx_clear_window(mlx.ptr, mlx.win);
	mlx_destroy_window(mlx.ptr, mlx.win);
	return (EXIT_SUCCESS);
}

bool	make_window_image(t_canvas *mlx, t_dim size)
{
	mlx->data = malloc(sizeof(t_data));
	if (!mlx->data)
		return (false);
	mlx->data->width = size.x;
	mlx->data->height = size.y;
	mlx->data->img = mlx_new_image(mlx->ptr,
			mlx->data->width, mlx->data->height);
	if (!mlx->data->img)
		return (false);
	mlx->data->addr = mlx_get_data_addr(mlx->data->img,
			&mlx->data->bits_per_pixel, &mlx->data->line_length,
			&mlx->data->endian);
	return (true);
}
