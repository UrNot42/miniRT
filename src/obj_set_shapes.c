/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_set_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:11:41 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 15:16:05 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	set_ratio(t_light *light, char *line, unsigned int *idx)
{
	(void)light;
	(void)line;
	(void)idx;
	return (false);
}

bool	set_cylinder(t_cylinder *cy, char *line, unsigned int *idx)
{
	(void)cy;
	(void)line;
	(void)idx;
	return (false);
}

bool	set_sphere(t_sphere *sp, char *line, unsigned int *idx)
{
	(void)sp;
	(void)line;
	(void)idx;
	return (false);
}

bool	set_fov(t_camera *cam, char *line, unsigned int *idx)
{
	(void)cam;
	(void)line;
	(void)idx;
	return (false);
}
