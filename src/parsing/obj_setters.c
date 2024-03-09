/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:02:07 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 14:24:07 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_color(t_color *color, char *line, t_unt *idx)
{
	ft_skip_spaces(line, idx);
	if (!color)
		return (p_error(ERR_UNSET), true);
	color->red = ft_atof_c(line, idx);
	if (line[*idx] && line[*idx] == ',')
		(*idx)++;
	else
		return (true);
	color->green = ft_atof_c(line, idx);
	if (line[*idx] && line[*idx] == ',')
		(*idx)++;
	else
		return (true);
	color->blue = ft_atof_c(line, idx);
	if (!ft_isispace(line[*idx]))
		return (true);
	return (false);
}

bool	parse_pos(t_pos *pos, char *line, t_unt *idx)
{
	ft_skip_spaces(line, idx);
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

t_obj	**get_flex_array(t_scene *scene, int id)
{
	if (id == OBJ_CYLINDER)
		return (&scene->cylinder);
	else if (id == OBJ_SPHERE)
		return (&scene->sphere);
	else if (id == OBJ_PLANE)
		return (&scene->plane);
	else if (id == OBJ_SRC_LIGHT)
		return (&scene->light);
	return (NULL);
}

bool	parse_obj(t_scene *scene, int id)
{
	t_obj	**obj_tmp;
	t_size	*size_tmp;

	if (id == OBJ_CAMERA || id == OBJ_AMB_LIGHT)
		return (false);
	obj_tmp = get_flex_array(scene, id);
	if (!obj_tmp)
		return (true);
	if (id == OBJ_CYLINDER)
		size_tmp = &scene->cy_size;
	if (id == OBJ_PLANE)
		size_tmp = &scene->pl_size;
	if (id == OBJ_SPHERE)
		size_tmp = &scene->sp_size;
	if (id == OBJ_SRC_LIGHT)
		size_tmp = &scene->l_size;
	if (sz_new_elemmt(obj_tmp, size_tmp))
		return (true);
	return (false);
}
