/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:11:10 by marvin            #+#    #+#             */
/*   Updated: 2024/04/01 12:11:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	hook_canvas_controls(t_wraper *data)
{
	mlx_hook(data->screen->win, KeyPress, KeyPressMask, key_handler, data);
	mlx_hook(data->screen->win, DestroyNotify, 0, free_loop, data);
}

void	start_loop(t_wraper *data)
{
	hook_canvas_controls(data);
	mlx_loop_hook(data->screen->ptr, render_scene, data);
	mlx_loop(data->screen->ptr);
}

// TODO DOC
int	free_loop(t_wraper *data)
{
	close_canvas((*data->screen));
	scene_free((data->scene));
	return (1);
}
