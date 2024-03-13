/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cast_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:41:13 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/13 10:19:49 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
#define SCALE 1.5

int	main(void)
{
	t_canvas	screen;
	t_ray		r;
	t_inter		hit;
	t_obj		*s;
	float		x;
	float		y;

	screen = canvas(SIZE, SIZE);
	s = sphere();
	for (int i = 0; i < SIZE; i++)
	{
		y = (i - (SIZE / 2)) * 2 * SCALE;
		for (int j = 0; j < SIZE; j++)
		{
			x = (j - (SIZE / 2)) * 2 * SCALE;
			r = ray(set_point(x / SIZE, y / SIZE, -5), set_vec(0, 0, 1));
			hit = find_hit(intersect(s, r));
			// Elle est BISQUE
			if (hit.def)
				pixel_put(screen.picture, i, j, 0xffe4c4);
			else
				pixel_put(screen.picture, i, j, 0);
		}
	}
	printf("Done!\n");
	print_canvas(screen);
	usleep(50000000);
	close_canvas(screen);
} */

#define SIZE 1000
#define WALL 70
#define PIXEL_SZ WALL / SIZE
#define HALF SIZE / 2
#define WALL_POS 10

int	main(void)
{
	t_inter		hit;
	t_ray		r;
	t_tuple		position;
	t_tuple		world;
	t_obj		*s = sphere();
	t_canvas	screen = canvas(SIZE, SIZE);
	t_color		pixel_col = set_col(1, 0, 0);

	// s->transform = scale_mtrx(0.4, 0.5, 1.1);
	// s->transform = scale_mtrx(0.5, 1, 1);
	// s->transform = rotation_y(M_PI / 4) * rotation_z(M_PI / 4) * scale_mtrx(0.5, 1, 1);
	// s->transform = rotation_y(M_PI / 4) * shearing((t_shear){0, 0, 1, 0, 0.5, 0}) * scale_mtrx(0.5, 1, 1);
	world.z = WALL_POS;
	for (int y = 0; y < SIZE ; y++)
	{
		world.y = ((float)y - HALF) / WALL;
		for (int x = 0; x < SIZE ; x++)
		{
			world.x = ((float)x - HALF) / WALL;
			position = set_point(world.x, world.y, world.z);
			r.origin = set_point(0, 0, -2);
			r = ray(r.origin, vec_norm(position - r.origin));
			hit = find_hit(intersect(s, r));
			if (hit.def)
				write_pixel(screen.picture, x, y, pixel_col);
		}
	}
	printf("Done!\n");
	print_canvas(screen);
	usleep(20000000);
	close_canvas(screen);
}
