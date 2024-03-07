/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:45:13 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/07 12:18:10 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	set_float(float *num, char *line, t_unt *index)
{
	ft_skip_spaces(line, index);
	*num = ft_atof_c(line, index);
	return (false);
}

bool	set_int(int *num, char *line, t_unt *index)
{
	ft_skip_spaces(line, index);
	*num = ft_atoi_c(line, index);
	return (false);
}

bool	set_f_wbound(float *num, t_bound boundary,
	char *line, t_unt *index)
{
	set_float(num, line, index);
	if (boundary.set
		&& (*num < (float)(boundary.left) || *num > (float)(boundary.right)))
		return (true);
	return (false);
}

bool	set_int_wbound(int *num, t_bound boundary,
	char *line, t_unt *index)
{
	set_int(num, line, index);
	if (boundary.set
		&& (*num < (int)(boundary.left) || *num > (int)(boundary.right)))
		return (true);
	return (false);
}
