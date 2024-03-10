/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:37:39 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/10 15:14:03 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	det_2mtrx(t_2mtrx a)
{
	float	result;

	result = a[0][0] * a[1][1] - a[0][1] * a[1][0];
	return (result);
}

float	det_3mtrx(t_3mtrx a)
{
	float	result;

	result = a[0][0] * cofactor_3mtrx(a, 0, 0)
		+ a[0][1] * cofactor_3mtrx(a, 0, 1)
		+ a[0][2] * cofactor_3mtrx(a, 0, 2);
	return (result);
}

float	det_4mtrx(t_4mtrx a)
{
	float	result;

	result = a[0][0] * cofactor_4mtrx(a, 0, 0)
		+ a[0][1] * cofactor_4mtrx(a, 0, 1)
		+ a[0][2] * cofactor_4mtrx(a, 0, 2)
		+ a[0][3] * cofactor_4mtrx(a, 0, 3);
	return (result);
}
