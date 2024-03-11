/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:22:30 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/11 16:54:29 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define CENTER_X 50
#define CENTER_Y 50

/* int	main(void)
{
	t_canvas	screen;
	t_4mtrx		transform;
	t_tuple		p;
	t_unt		x;
	t_unt		y;

	screen = canvas(100, 100);
	transform = scale_mtrx(sqrtf(1500), 1, 1);
	for (t_unt i = 0; i < 12; i++)
	{
		transform = rotation_z(M_PI / 6) * transform;
		p = tup_mtrx(transform, set_point(1, 0, 0));
		x = CENTER_X + p.x;
		y = CENTER_Y + p.y;
		pixel_put(screen.picture, x, y, 0xFFFFFF);
	}
	print_screen(screen);
	usleep(10000000);
	sleep(3);
} */
