/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:18:29 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 14:27:02 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	add_scene_obj(t_scene *scene, unsigned int id)
{
	if (id == OBJ_CYLINDER
		&& sz_new_elemmt((void **)&scene->cylinder, &scene->cy_size, sizeof(t_cylinder)))
		return (true);
	if (id == OBJ_SPHERE
		&& sz_new_elemmt((void **)&scene->sphere, &scene->sp_size, sizeof(t_sphere)))
		return (true);
	if (id == OBJ_PLANE
		&& sz_new_elemmt((void **)&scene->plane, &scene->pl_size, sizeof(t_plane)))
		return (true);
	if (id == OBJ_LIGHT
		&& sz_new_elemmt((void **)&scene->light, &scene->l_size, sizeof(t_light)))
		return (true);
	return (false);
}

bool	scene_fill(t_scene *scene, int fd)
{
	char			*line;
	unsigned int	count;
	unsigned int	tmp;

	if (scene_init(scene))
		return (false);
	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (p_error(ERR_EMPTY), false);
	while (line)
	{
		tmp = parse_line(line, scene);
		free(line);
		if (!tmp)
			count++;
		else if (tmp > 1)
			return (get_next_line(-1), false);
		line = get_next_line(fd);
	}
	if (!count)
		return (p_error(ERR_EMPTY), false);
	return (true);
}
