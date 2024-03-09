/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:52:20 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 20:55:36 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_2mtrx	set_2mtrx(t_i2mtr a)
{
	t_2mtrx	m;

	m = *(t_2mtrx *)(t_i2mtr){a[0], a[2],
		a[1], a[3]};
	return (m);
}

t_3mtrx	set_3mtrx(t_i3mtr a)
{
	t_3mtrx	m;

	m = *(t_3mtrx *)(t_i3mtr){a[0], a[3], a[6],
		a[1], a[4], a[7],
		a[2], a[5], a[8]};
	return (m);
}

t_4mtrx	set_4mtrx(t_i4mtr a)
{
	t_4mtrx	m;

	m = *(t_4mtrx *)(t_i4mtr){a[0], a[4], a[8], a[12],
		a[1], a[5], a[9], a[13],
		a[2], a[6], a[10], a[14],
		a[3], a[7], a[11], a[15]};
	return (m);
}
