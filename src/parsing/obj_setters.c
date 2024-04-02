/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:02:07 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/02 22:08:54 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_color(t_color *color, char *line, t_unt *idx)
{
	ft_skip_spaces(line, idx);
	if (!color)
		return (p_error(ERR_UNSET), true);
	color->red = ft_atof_c(line, idx) / COL_SCALE;
	if (line[*idx] && line[*idx] == ',')
		(*idx)++;
	else
		return (true);
	color->green = ft_atof_c(line, idx) / COL_SCALE;
	if (line[*idx] && line[*idx] == ',')
		(*idx)++;
	else
		return (true);
	color->blue = ft_atof_c(line, idx) / COL_SCALE;
	if (!ft_isispace(line[*idx]))
		return (true);
	return (false);
}

bool	parse_pos(t_tuple *pos, char *line, t_unt *idx)
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
