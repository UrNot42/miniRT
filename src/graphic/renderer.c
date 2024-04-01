/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:30:30 by marvin            #+#    #+#             */
/*   Updated: 2024/04/01 01:30:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	render_scene(t_wraper *data)
{
	if (data->state == DISPLAYING)
		return (1);
	close_canvas(data->screen);
	data->screen = render(data->scene.camera.camera, data->scene);
	open_canvas(&data->screen);
	hook_canvas_controls(data);
	print_canvas(data->screen);
	data->state = DISPLAYING;
	return (0);
}
