/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:47:19 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 14:53:08 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	my_fabs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

bool	f_eq(float a, float b)
{
	if (my_fabs(a - b) < EPSILON)
		return (true);
	return (false);
}
