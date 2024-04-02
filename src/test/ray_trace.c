/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:41:13 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/02 20:50:15 by ulevallo         ###   ########.fr       */
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
	close_canvas(&screen);
} */

/*
#define SIZE 1000
#define WALL 70
#define PIXEL_SZ WALL / SIZE
#define HALF SIZE / 2
#define WALL_POS 10

void	ray_trace(t_obj s)
{
	t_inter		hit;
	t_ray		r;
	t_tuple		point;
	t_tuple		position;
	t_tuple		world;
	t_canvas	screen = canvas(SIZE, SIZE);
	t_obj		light = o_light(set_point(-10, 10, -10), set_col(1, 1, 1));

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
	usleep(2000050);
	close_canvas(&screen);
} */

void	ray_trace(t_scene scene_to_render)
{
	t_wraper	data;

	data.state = CALCULATING;
	data.scene = scene_to_render;
	data.screen = canvas(1, 1);
	if (data.screen.defined)
		start_loop(&data);
}

bool	try_ray_trace(char a)
{
	t_scene	world;
	t_color	color;

	color = set_col(0.9, 0.8, 0.7);
	world.light = NULL;
	if (a == 'e' || a == '0')
		world = scene_example(color);
	else if (a == '0' || a == '1')
		world = scene_multi_light((t_dim){500, 500});
	else if (a == 't' || a == '2')
		world = scene_studio(color);
	else if (a == 'a' || a == '3')
		world = scene_aura((t_dim){500, 500});
	else if (a == 'c' || a == '4')
		world = scene_cube(color);
	else if (a == 'n' || a == '5')
		world = scene_cone(color);
	else if (a == 'l' || a == '6')
		world = scene_cooloon(color);
	else if (a == 'y' || a == '7')
		world = scene_cylinder(color);
	else if (a == 'h' || a == '8')
		world = scene_hex(color);
	else if (a == 's' || a == '9')
		world = scene_sphere(color);
	else if (a == 'i')
		world = scene_cig((t_dim){500, 500});
	if (world.light)
		return (print_scene(world), ray_trace(world), true);
	return (false);
}
