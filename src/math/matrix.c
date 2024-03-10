/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:01:49 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/10 15:51:26 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_4mtrx	get_id4mtrx(void)
{
	t_4mtrx	identity;

	identity = set_4mtrx((t_i4mtr){
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1});
	return (identity);
}

t_4mtrx	transpose(t_4mtrx a)
{
	t_4mtrx	transposed;

	transposed = set_4mtrx((t_i4mtr){
			a[0][0], a[1][0], a[2][0], a[3][0],
			a[0][1], a[1][1], a[2][1], a[3][1],
			a[0][2], a[1][2], a[2][2], a[3][2],
			a[0][3], a[1][3], a[2][3], a[3][3]});
	return (transposed);
}

t_2mtrx	sub_3mtrx(t_3mtrx a, t_unt y_line2skip, t_unt x_line2skip)
{
	t_2mtrx	submatrix;
	t_i2mtr	content;
	t_unt	i;
	t_unt	x;
	t_unt	y;

	i = 0;
	x = 0;
	y = 0;
	while (y < 3)
	{
		y += y_line2skip == y;
		x = 0;
		while (x < 3 && y < 3)
		{
			x += x_line2skip == x;
			if (x < 3)
				content[i++] = a[y][x++];
		}
		y++;
	}
	submatrix = set_2mtrx(content);
	return (submatrix);
}

t_3mtrx	sub_4mtrx(t_4mtrx a, t_unt y_line2skip, t_unt x_line2skip)
{
	t_3mtrx	submatrix;
	t_i3mtr	content;
	t_unt	i;
	t_unt	x;
	t_unt	y;

	i = 0;
	y = 0;
	while (y < 4)
	{
		y += y_line2skip == y;
		x = 0;
		while (x < 4 && y < 4)
		{
			x += x_line2skip == x;
			if (x < 4)
				content[i++] = a[y][x++];
		}
		y++;
	}
	submatrix = set_3mtrx(content);
	return (submatrix);
}

t_4mtrx	inverse_4mtrx(t_4mtrx a)
{
	t_4mtrx	inverse;
	t_unt	row;
	t_unt	col;
	float	determinant;

	determinant = det_4mtrx(a);
	if (f_eq(determinant, 0))
		return (set_4mtrx((t_i4mtr){0}));
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			inverse[col][row] = cofactor_4mtrx(a, row, col) / determinant;
			col++;
		}
		row++;
	}
	return (inverse);
}
