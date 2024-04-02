/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 07:03:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/02 22:08:51 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
