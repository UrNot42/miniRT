/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firing_projectiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:42:27 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 21:02:52 by ulevallo         ###   ########.fr       */
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

	position = tup_add(proj.pos, proj.vel);
	velocity = tup_add(proj.vel, tup_add(env.wind, env.gravity));
	return ((t_proj){position, velocity});
}
/*
int	main(void)
{
	t_proj	arrow;
	t_env	world;

	arrow.pos = set_point(0, 1, 0);
	arrow.vel = set_vec(1, 1.5, 0);
	world.gravity = set_vec(0, -0.1, 0);
	world.wind = set_vec(-0.01, 0.01, 0);
	printf("\n");
	while (arrow.pos.y > 0)
	{
		arrow = tick(world, arrow);
		usleep(50000);
		printf("\033[F[%8f, %8f, %8f]\n", arrow.pos.x, arrow.pos.y, arrow.pos.z);
	}
}
*/
