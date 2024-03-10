/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_minor_and_cofactor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:55:09 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/10 15:12:52 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	minor_3mtrx(t_3mtrx a, t_unt i, t_unt j)
{
	return (det_2mtrx(sub_3mtrx(a, i, j)));
}

float	minor_4mtrx(t_4mtrx a, t_unt i, t_unt j)
{
	return (det_3mtrx(sub_4mtrx(a, i, j)));
}

float	cofactor_3mtrx(t_3mtrx a, t_unt i, t_unt j)
{
	int	sign;

	sign = 1 - 2 * ((i + j) % 2);
	return (minor_3mtrx(a, i, j) * sign);
}

float	cofactor_4mtrx(t_4mtrx a, t_unt i, t_unt j)
{
	int	sign;

	sign = 1 - 2 * ((i + j) % 2);
	return (minor_4mtrx(a, i, j) * sign);
}
