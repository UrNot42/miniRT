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

void	draw_image(t_cam camera, t_image *picture, t_scene world)
{
	t_unt		x;
	t_unt		y;
	t_ray		r;

	y = 0;
	while (y < camera.v_size - 1)
	{
		x = 0;
		while (x < camera.hz_size - 1)
		{
			r = ray_for_pixel(camera, x, y);
			write_pixel(picture, x, y, color_at(world, r));
			x++;
		}
		y++;
	}
}

/**
 * @brief Creates a new canvas to render images to
 * and draws the given scene
 * @param camera
 * @param world
 * @return a pointer to the newly allocated canvas
 */
t_canvas	render(t_cam camera, t_scene world)
{
	t_canvas	image;

	image = canvas(camera.hz_size, camera.v_size);
	draw_image(camera, image.picture, world);
	return (image);
}

int	render_scene(t_wraper *data)
{
	if (data->state == DISPLAYING)
		return (1);
	close_window(&data->screen);
	if (set_default_canvas(&data->screen,
			data->scene.camera.camera.hz_size,
			data->scene.camera.camera.v_size))
		return (free_loop(data), 1);
	draw_image(data->scene.camera.camera, data->screen.picture, data->scene);
	open_window(&data->screen);
	hook_canvas_controls(data);
	print_canvas(data->screen);
	data->state = DISPLAYING;
	return (0);
}
