/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:02:07 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/19 14:22:34 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

bool	set_db_wbound(double *num, t_bound boundary,
	char *line, unsigned int *idx)
{
	*num = ft_atof_c(line, idx);
	if (boundary.set
		&& (*num < (double)(boundary.right) || *num > (double)(boundary.right)))
		return (true);
	return (false);
}

bool	set_int_wbound(int *num, t_bound boundary,
	char *line, unsigned int *idx)
{
	*num = ft_atoi_c(line, idx);
	if (boundary.set
		&& (*num < (int)(boundary.right) || *num > (int)(boundary.right)))
		return (true);
	return (false);
}
