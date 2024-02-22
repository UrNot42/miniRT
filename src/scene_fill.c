/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:18:29 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/19 14:34:17 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
bool	add_scene_obj(t_scene *scene, unsigned int id)
{
	t_obj	*object;
	t_size	*size;

	if (id == OBJ_CYLINDER
		&& sz_new_elemmt(&scene->cylinder[scene->cy_size.use], &scene->cy_size))
		return (true);
	else if (id == OBJ_SPHERE
		&& sz_new_elemmt(&scene->sphere[scene->sp_size.use], &scene->sp_size))
		return (true);
	else if (id == OBJ_PLANE
		&& sz_new_elemmt(&scene->plane[scene->pl_size.use], &scene->pl_size))
		return (true);
	else if (id == OBJ_SRC_LIGHT
		&& sz_new_elemmt(&scene->light[scene->l_size.use], &scene->l_size))
		return (true);
	return (false);
}

(t_light *)((int)(&scene->ambient_light.ratio) * (id == OBJ_AMB_LIGHT)
				+ (int)(&scene->light[scene->l_size.use].brgt.ratio) * (id == OBJ_SRC_LIGHT))

	set_cylinder(&scene->cylinder[scene->cy_size.use], line, pos);
	set_sphere(&scene->sphere[scene->sp_size.use], line, pos);
	set_fov(&scene->camera, line, pos);

*/

bool	add_scene_obj(unsigned int id, t_obj *object, t_size *size)
{
	if ((id == OBJ_CYLINDER
		|| id == OBJ_SPHERE
		|| id == OBJ_PLANE
		|| id == OBJ_SRC_LIGHT)
		&& sz_new_elemmt(object, size))
		return (true);
	return (false);
}

bool	scene_fill(t_scene *scene, int fd)
{
	char			*line;
	unsigned int	count;
	unsigned int	tmp;

	if (!scene_init(scene))
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
