/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 07:03:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/30 07:19:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_translate_matrix(t_scene	world)
{
	t_unt	i;
	t_4mtrx	edit_matrix;
	t_obj	*obj;
	t_tuple	normal;

	i = 0;
	while (i < world.obj_size.use)
	{
		obj = &world.objects[i];
		if (obj->kind == OBJ_PLANE
			|| obj->kind == OBJ_CYLINDER || obj->kind == OBJ_CUBE
			|| obj->kind == OBJ_CONE)
			normal = obj->plane.normal;
		else
			normal = set_vec(0, 0, 0);
		if (obj->kind == OBJ_SPHERE || obj->kind == OBJ_PLANE
			|| obj->kind == OBJ_CYLINDER || obj->kind == OBJ_CUBE
			|| obj->kind == OBJ_CONE)
		{
			edit_matrix = view_transform(obj->pos, obj->pos + normal, set_vec(0, 1, 1));
			set_transform(&obj->sphere.mtx, edit_matrix);
			print_m(obj->sphere.mtx.transform, 'T');
		}
		i++;
	}
}

bool	scene_free(t_scene *scene)
{
	if (scene->obj_size.use)
		free(scene->objects);
	if (scene->li_size.use)
		free(scene->light);
	return (true);
}

t_scene	scene_init(void)
{
	return ((t_scene){0});
}
