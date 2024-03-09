/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firing_projectiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:42:27 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 17:22:02 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_proj	tick(t_env env, t_proj proj)
{
	t_tuple	position;
	t_tuple	velocity;

	position = proj.pos + proj.vel;
	velocity = proj.vel + env.wind + env.gravity;
	return ((t_proj){position, velocity});
}

int	main(int ac, char **av)
{
	t_canvas	screen;
	t_proj		ball;
	t_env		world;
	int			x;
	int			y;

	ball.pos = set_point(0, 500, 0);
	if (ac >= 3)
		ball.vel = set_vec(ft_atof(av[1]), ft_atof(av[2]), 0);
	else
		ball.vel = vec_norm(set_vec(8, 9.2, 0)) * 14;
	world.gravity = set_vec(0, -0.1, 0);
	world.wind = set_vec(-0.01, 0, 0);
	screen = canvas(2000, 1200);
	printf("\n");
	usleep(100000);
	while (ball.pos.y > 0)
	{
		ball = tick(world, ball);
		print_screen(screen);
		x = (int)ball.pos.x;
		y = (t_unt)(screen.height - ball.pos.y);
		if (ft_inr(x, 0, screen.width) && ft_inr(y, 0, screen.height))
			pixel_put(screen.picture, x, y, 0xFFFFFF);
		printf("\033[F[%8f, %8f, %8f] (%d, %d)\n",
			ball.pos.x, ball.pos.y, ball.pos.z, x, y);
		usleep(10000);
	}
	close_canvas(screen);
}
