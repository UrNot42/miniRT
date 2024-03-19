/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:41:13 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/19 18:22:41 by ulevallo         ###   ########.fr       */
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
	t_tuple		point;
	t_tuple		position;
	t_tuple		world;
	t_obj		s = sphere();
	t_canvas	screen = canvas(SIZE, SIZE);
	t_obj		light = point_light(set_point(-10, 10, -10), set_col(1, 1, 1));

	// set_transform(&s, scale_mtrx(0.4, 0.5, 1.1));
	// set_transform(&s, scale_mtrx(0.5, 1, 1));
	// set_transform(&s, rotation_x(M_PI / 4) * scale_mtrx(1, 0.3, 1));
	set_transform(&s, shearing((t_shear){1, 0, 0, 0, 0, 0}) * scale_mtrx(0.5, 1, 1));
	s.m.color = set_col(0.1, 0.2, 0.5);
	world.z = WALL_POS;
	for (int y = 0; y < SIZE ; y++)
	{
		world.y = (((float)y - HALF) / WALL) * -1;
		for (int x = 0; x < SIZE ; x++)
		{
			world.x = ((float)x - HALF) / WALL;
			position = set_point(world.x, world.y, world.z);
			r.origin = set_point(0, 0, -2);
			r = ray(r.origin, vec_norm(position - r.origin));
			point = ray_pos(r, hit.t);
			hit = find_hit(intersect(&s, r));
			if (hit.def)
				write_pixel(screen.picture, x, y,
					lighting(hit.obj->m, light, point, (t_ray)
					{-r.direction, normal_at(*(hit.obj), point)}));
		}
	}
	printf("Done!\n");
	print_canvas(screen);
	usleep(200005000);
	close_canvas(screen);
}

