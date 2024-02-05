/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 07:03:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 07:23:24 by ulevallo         ###   ########.fr       */
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
	sz_set(&scene->sp_size);
	sz_set(&scene->l_size);
	sz_set(&scene->cy_size);
	sz_set(&scene->pl_size);
	scene->camera.defined = false;
	scene->ambient_light.defined = false;
	return (true);
}
