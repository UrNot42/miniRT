/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firing_projectiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:42:27 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/02 15:37:52 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <sys/time.h>

#define COL_OFS 0.01
#define SLOWING 0.2
#define WIND_X 0
#define PERSPECTIVE 0.3
#define TIME_RESOL 8000
#define SCREEN_X 1200
#define SCREEN_Y 800


typedef struct s_proj	t_proj;
typedef struct s_env	t_env;

struct	s_proj
{
	t_tuple	pos;
	t_tuple	vel;
};

struct	s_env
{
	t_tuple	gravity;
	t_tuple	wind;
};

t_color	color_update(t_color rainbow)
{
	static int	a = 0;

	if (a == 0)
	{
		if (rainbow.blue > 0)
			rainbow.blue -= COL_OFS;
		rainbow.red += COL_OFS;
	}
	else if (a == 1)
	{
		if (rainbow.red > 0)
			rainbow.red -= COL_OFS;
		rainbow.green += COL_OFS;
	}
	else if (a == 2)
	{
		if (rainbow.green > 0)
			rainbow.green -= COL_OFS;
		rainbow.blue += COL_OFS;
	}
	if (rainbow.red >= 1 - COL_OFS
		|| rainbow.green >= 1 - COL_OFS
		|| rainbow.blue >= 1 - COL_OFS)
		a = (a + 1) % 3;
	return (rainbow);
}

t_proj	tick(t_env env, t_proj proj)
{
	t_tuple	position;
	t_tuple	velocity;

	position = proj.pos + proj.vel;
	velocity = proj.vel + env.wind + env.gravity;
	if (position.y <= (position.x * -PERSPECTIVE + PERSPECTIVE * SCREEN_X)
		&& velocity.y < 0)
	{
		velocity.y = (-velocity.y);
		velocity = velocity * (1 - SLOWING);
	}
	return ((t_proj){position, velocity});
}

int	main(int ac, char **av)
{
	t_canvas	screen;
	t_proj		ball;
	t_env		world;
	int			x;
	int			y;
	t_color		pixel;

	ball.pos = set_point(0, SCREEN_X * PERSPECTIVE, 0);
	if (ac >= 3)
		ball.vel = set_vec(ft_atof(av[1]), ft_atof(av[2]), 0);
	else
		ball.vel = set_vec(1.4, 6.5, 0);
	world.gravity = set_vec(0, -0.1, 0);
	world.wind = set_vec(WIND_X, 0, 0);
	screen = canvas(SCREEN_X, SCREEN_Y);
	pixel = set_col(0, 0.9, 0);
	printf("\n");
	while (ball.pos.y >= (ball.pos.x * PERSPECTIVE) + 5
		|| fabs(ball.vel.y) > (SLOWING + fabs(world.wind.y) + fabs(world.gravity.y))
		|| fabs(ball.vel.x) > (SLOWING + fabs(world.wind.x)))
	{
		ball = tick(world, ball);
		print_canvas(screen);
		x = (int)ball.pos.x;
		y = (t_unt)(screen.height - ball.pos.y);
		pixel = color_update(pixel);
		for (t_unt i = 0; i < 10; i++)
		{
			for (t_unt j = 0; j < 10; j++)
			{
				safe_pixel(screen.picture, x+ i, y + j, pixel);
			}
		}
		usleep(10000);
	}
	close_canvas(&screen);
}
