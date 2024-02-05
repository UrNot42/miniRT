/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:03:09 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 15:13:32 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_result(char *str, unsigned int *pos)
{
	double	result;
	double	scale;
	int		decimal;

	decimal = 0;
	result = 0;
	scale = 1;
	while (ft_isdigit(str[*pos]) || str[*pos] == '.')
	{
		if (!decimal)
			result = result * 10 + (str[(*pos)++] - '0');
		else
		{
			if (str[*pos] == '.')
				decimal = decimal + 1 + 0 * ((*pos)++);
			else
			{
				scale /= 10;
				result += (str[(*pos)++] - '0') * scale;
			}
		}
		(*pos)++;
	}
	return (result);
}

double	ft_atof_c(char *nptr, unsigned int *pos)
{
	int		sign;
	double	result;

	ft_skip_spaces(nptr, pos);
	sign = 1;
	if (nptr[*pos] == '-' || nptr[*pos] == '+')
		sign += (nptr[(*pos)++] == '-') * -2;
	result = get_result(nptr, pos);
	return (result * sign);
}

double	ft_atof(char *nptr)
{
	long double		result;
	int				sign;
	unsigned int	i;

	i = 0;
	ft_skip_spaces(nptr, &i);
	result = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign += (nptr[i++] == '-') * -2;
	result = get_result(nptr, &i);
	return (sign * result);
}
