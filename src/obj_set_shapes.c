/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_set_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:11:41 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/12 10:34:46 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	set_ratio(t_light *light, char *line, unsigned int *idx)
{
	light->ratio = ft_atof_c(line, idx);
	if (light -> ratio < 0 || light -> ratio > 1)
		return (true);
	return (false);
}

bool	set_cylinder(t_cylinder *cy, char *line, unsigned int *idx)
{
	cy->diameter = ft_atof_c(line, idx);
	cy->height = ft_atof_c(line, idx);
	return (false);
}

bool	set_sphere(t_sphere *sp, char *line, unsigned int *idx)
{
	sp->diameter = ft_atof_c(line, idx);
	return (false);
}

bool	set_fov(t_camera *cam, char *line, unsigned int *idx)
{
	cam->fov = ft_atoi_c(line, idx);
	if (cam->fov < 0 || cam->fov > 180)
		return (true);
	return (false);
}
