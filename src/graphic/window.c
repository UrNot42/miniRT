/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:08:33 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/01 19:56:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	open_window(t_canvas *screen)
{
	screen->win = mlx_new_window(screen->ptr,
			screen->width, screen->height, screen->name);
	if (!screen->win)
	{
		mlx_destroy_display(screen->ptr);
		free(screen->picture);
		return (true);
	}
	return (false);
}

bool	close_window(t_canvas screen)
{
	if (!screen.ptr || !screen.win)
		return (true);
	mlx_clear_window(screen.ptr, screen.win);
	mlx_destroy_window(screen.ptr, screen.win);
	return (false);
}

/* TODO ADD
void	start_canvas_loop_hooks(t_params *param)
{
	start_canvas_win_hooks(param);
	mlx_loop_hook(param->mlx.ptr, game, param);
	mlx_loop(param->mlx.ptr);
}
*/

/* Templates for mouse integration

	mlx_hook(param->mlx.win, ButtonPress, ButtonPressMask, mousse_press, param);
	mlx_hook(param->mlx.win, ButtonRelease, ButtonReleaseMask, mouse_enter, param);
	mlx_hook(param->mlx.win, MotionNotify, ButtonMotionMask, mouse_move, param);
	mlx_hook(param->mlx.win, KeyRelease, KeyReleaseMask, key_pause_pressed, param);
*/

/* TODO MOD PARAM
void	start_canvas_win_hooks(t_canvas screen, int param)
{
	mlx_hook(screen.win, KeyPress, KeyPressMask, key_press, param);
	mlx_hook(screen.win, DestroyNotify, 0, close_game, param);
}*/
