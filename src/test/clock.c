/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:22:30 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/11 18:56:06 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define SIZE 1050
#define CENTER SIZE / 2
#define POINT ((SIZE * 3) / 8) * M_PI / 2

int	main(void)
{
	t_canvas	screen;
	t_4mtrx		transform;
	t_tuple		p;
	t_unt		x;
	t_unt		y;

	screen = canvas(SIZE, SIZE - 100);
	transform = scale_mtrx((SIZE * 3) / 8, 1, 1);
	for (t_unt i = 0; i < POINT; i++)
	{
		transform = rotation_z(M_PI / (POINT / 2)) * transform;
		p = tup_mtrx(transform, set_point(1, 0, 0));
		x = CENTER + p.x;
		y = CENTER + p.y;
		pixel_put(screen.picture, x, y, 0xFFFFFF);
	}
	print_screen(screen);
	usleep(1000000);
	close_canvas(screen);
}
