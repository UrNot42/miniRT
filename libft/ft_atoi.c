/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:25:52 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 15:02:55 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	unsigned int	res;
	int				sign;
	int				i;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
		sign += (nptr[i++] == '-') * -2;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += nptr[i++] - '0';
	}
	return (sign * res);
}

int	ft_atoi_c(const char *nptr, unsigned int *i)
{
	unsigned int	res;
	int				sign;

	res = 0;
	sign = 1;
	while (nptr[*i] == 32 || (nptr[*i] >= 9 && nptr[*i] <= 13))
	{
		(*i)++;
	}
	if (nptr[*i] == '-' || nptr[*i] == '+')
		sign += (nptr[(*i)++] == '-') * -2;
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		res *= 10;
		res += nptr[(*i)++] - '0';
	}
	return (sign * res);
}
