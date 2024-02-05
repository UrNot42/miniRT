/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:02:07 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 15:12:30 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pos	*get_pos(t_scene *scene, unsigned int id)
{
	if (id == OBJ_CAMERA)
		return (&scene->camera.posistion);
	if (id == OBJ_CYLINDER && scene->cy_size.use)
		return (&scene->cylinder[scene->cy_size.use - 1].position);
	if (id == OBJ_SPHERE && scene->sp_size.use)
		return (&scene->sphere[scene->sp_size.use - 1].position);
	if (id == OBJ_PLANE && scene->pl_size.use)
		return (&scene->plane[scene->pl_size.use - 1].point);
	if (id == OBJ_LIGHT && scene->l_size.use)
		return (&scene->light[scene->l_size.use - 1].position);
	return (NULL);
}

t_pos	*get_norm(t_scene *scene, unsigned int id)
{
	if (id == OBJ_CAMERA)
		return (&scene->camera.orientation);
	if (id == OBJ_CYLINDER && scene->cy_size.use)
		return (&scene->cylinder[scene->cy_size.use - 1].orientation);
	if (id == OBJ_PLANE && scene->pl_size.use)
		return (&scene->plane[scene->pl_size.use - 1].orientation);
	return (NULL);
}

t_color	*get_color(t_scene *scene, unsigned int id)
{
	if (id == OBJ_AMB_LIGHT)
		return (&scene->ambient_light.color);
	if (id == OBJ_CYLINDER && scene->cy_size.use)
		return (&scene->cylinder[scene->cy_size.use - 1].color);
	if (id == OBJ_PLANE && scene->pl_size.use)
		return (&scene->plane[scene->pl_size.use - 1].color);
	if (id == OBJ_SPHERE && scene->sp_size.use)
		return (&scene->sphere[scene->sp_size.use - 1].color);
	if (id == OBJ_LIGHT && scene->l_size.use)
		return (&scene->light[scene->l_size.use - 1].color);
	return (NULL);
}

bool	set_color(t_color *color, char *line, unsigned int *idx)
{
	if (!color)
		return (p_error(ERR_UNSET), true);
	color->red = ft_atof_c(line, idx);
	if (line[*idx] && line[*idx] == ',')
		(*idx)++;
	else
		return (p_error(ERR_COLOR), true);
	color->grn = ft_atof_c(line, idx);
	if (line[*idx] && line[*idx] == ',')
		(*idx)++;
	else
		return (p_error(ERR_COLOR), true);
	color->blu = ft_atof_c(line, idx);
	if (!ft_isispace(line[*idx]))
		return (p_error(ERR_COLOR), true);
	return (false);
}

bool	set_pos(t_pos *pos, char *line, unsigned int *idx)
{
	if (!pos)
		return (p_error(ERR_UNSET), true);
	pos->x = ft_atof_c(line, idx);
	if (line[*idx] && line[*idx] == ',')
		(*idx)++;
	else
		return (p_error(ERR_NUMBER), true);
	pos->y = ft_atof_c(line, idx);
	if (line[*idx] && line[*idx] == ',')
		(*idx)++;
	else
		return (p_error(ERR_NUMBER), true);
	pos->z = ft_atof_c(line, idx);
	if (!ft_isispace(line[*idx]))
		return (p_error(ERR_NUMBER), true);
	return (false);
}
