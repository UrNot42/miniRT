/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 07:03:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/01 12:41:30 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	scene_free(t_scene *scene)
{
	if (scene->sp_size.use)
		free(scene->sphere);
	if (scene->l_size.use)
		free(scene->light);
	if (scene->cy_size.use)
		free(scene->cylinder);
	if (scene->pl_size.use)
		free(scene->plane);
	return (true);
}

bool	scene_init(t_scene *scene)
{
	scene->camera.defined = false;
	scene->ambient_light.defined = false;
	scene->sphere = malloc(sizeof(t_obj) * O_SIZE_SET);
	if (!scene->sphere)
		return (p_error(ERR_MEM), false);
	scene->light = malloc(sizeof(t_obj) * O_SIZE_SET);
	if (!scene->light)
		return (p_error(ERR_MEM), false);
	scene->cylinder = malloc(sizeof(t_obj) * O_SIZE_SET);
	if (!scene->cylinder)
		return (p_error(ERR_MEM), false);
	scene->plane = malloc(sizeof(t_obj) * O_SIZE_SET);
	if (!scene->plane)
		return (p_error(ERR_MEM), false);
	return (true);
}
