/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:18:29 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 13:50:29 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	check_scene(t_scene *world)
{
	if (!world->ambient_light.defined)
		return (p_error(ERR_AMB_LIGHT), true);
	if (!world->camera.defined
		|| tup_eq(world->camera.camera.normal, set_vec(0, 0, 0)))
		return (p_error(ERR_CAMERA), true);
	if (world->camera.camera.fov < 0 || world->camera.camera.fov > 360)
		return (p_error(ERR_FOV), true);
	if (!world->li_size.use)
		return (p_error(ERR_LIGHT), true);
	return (false);
}

void	scene_translate(t_scene *world)
{
	translate_points(world);
	translate_set_camera(&world->camera.camera);
	translate_special_obj(world);
	translate_matrix(world->objects, world->obj_size);
}

bool	scene_fill(t_scene *scene, int fd)
{
	char	*line;
	t_unt	count;
	t_unt	tmp;

	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (p_error(ERR_EMPTY), true);
	while (line)
	{
		tmp = parse_line(line, scene);
		free(line);
		if (!tmp)
			count++;
		else if (tmp > 1)
			return (get_next_line(-1), true);
		line = get_next_line(fd);
	}
	if (!count)
		return (p_error(ERR_EMPTY), true);
	scene_translate(scene);
	if (check_scene(scene))
		return (true);
	return (false);
}
