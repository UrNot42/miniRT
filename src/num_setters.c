/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:45:13 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/01 14:40:11 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	set_db(double *num, char *line, unsigned int *index)
{
	ft_skip_spaces(line, index);
	*num = ft_atof_c(line, index);
	return (false);
}

bool	set_int(int *num, char *line, unsigned int *index)
{
	ft_skip_spaces(line, index);
	*num = ft_atoi_c(line, index);
	return (false);
}

bool	set_db_wbound(double *num, t_bound boundary,
	char *line, unsigned int *index)
{
	set_db(num, line, index);
	if (boundary.set
		&& (*num < (double)(boundary.left) || *num > (double)(boundary.right)))
		return (true);
	return (false);
}

bool	set_int_wbound(int *num, t_bound boundary,
	char *line, unsigned int *index)
{
	set_int(num, line, index);
	if (boundary.set
		&& (*num < (int)(boundary.left) || *num > (int)(boundary.right)))
		return (true);
	return (false);
}
