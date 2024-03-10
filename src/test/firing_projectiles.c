/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firing_projectiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:42:27 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 22:56:24 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <sys/time.h>

#define COL_OFS 0.01
#define SLOWING 0.07
#define WIND_X -0.00012
#define PERSPECTIVE 0.25
#define TIME_RESOL 8000

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
	if (rainbow.red > 1 - COL_OFS || rainbow.green > 1 - COL_OFS || rainbow.blue > 1 - COL_OFS)
		a = (a + 1) % 3;
	return (rainbow);
}

t_proj	tick(t_env env, t_proj proj)
{
	t_tuple	position;
	t_tuple	velocity;

	position = proj.pos + proj.vel;
	velocity = proj.vel + env.wind + env.gravity;
	if (position.y <= (position.x * PERSPECTIVE) && velocity.y < 0)
	{
		velocity.y = (-velocity.y);
		velocity = velocity * (1 - SLOWING);
	}
	return ((t_proj){position, velocity});
}

long	convert_time(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	set_time_goal(int time_to_wait)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (convert_time(now) + time_to_wait);
}

void	safe_wait(long time_goal)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	while (convert_time(now) <= time_goal)
	{
		usleep(TIME_RESOL);
		gettimeofday(&now, NULL);
	}
}
/*
int	main(int ac, char **av)
{
	t_canvas	screen;
	t_proj		ball;
	t_env		world;
	t_color		rainbow;
	int			x;
	int			y;
	float		val;
	// long		goal;

	ball.pos = set_point(0, 1, 0);
	if (ac >= 3)
		ball.vel = set_vec(ft_atof(av[1]), ft_atof(av[2]), 0);
	else
		ball.vel = set_vec(1.1, 15, 0);
	rainbow = set_col(0, 0, 1);
	world.gravity = set_vec(0, -0.03, 0);
	world.wind = set_vec(WIND_X, 0, 0);
	screen = canvas(1000, 600);
	printf("\n");
	usleep(100000);
	while (ball.pos.y >= (ball.pos.x * PERSPECTIVE) + 5
			|| fabs(ball.vel.y) > (SLOWING + fabs(world.wind.y) * 10)
			|| fabs(ball.vel.x) > (SLOWING + fabs(world.wind.x) * 10))
	{
		ball = tick(world, ball);
		print_screen(screen);
		// goal = set_time_goal(TIME_RESOL / 10000);
		x = (int)ball.pos.x;
		y = (t_unt)(screen.height - ball.pos.y);
		val = ball.pos.y / screen.height;
		// rainbow = color_update(rainbow);
		rainbow = set_col(val, 1 - val, 0);
		rainbow.tuple = vec_norm(rainbow.tuple);
		if (ft_inr(x, 0, screen.width) && ft_inr(y, 0, screen.height))
			write_pixel(screen.picture, x, y, rainbow);
		printf("\033[FV={%f, %f} X: | %d Y:%d (R:%f, G:%f, B:%f)   \n",
			ball.vel.x, ball.vel.y, x, y,
			rainbow.red, rainbow.green, rainbow.blue);
		usleep(10000);
		// safe_wait(goal);
	}
	close_canvas(screen);
}
*/