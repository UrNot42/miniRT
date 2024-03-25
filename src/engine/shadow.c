/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:59:36 by marvin            #+#    #+#             */
/*   Updated: 2024/03/23 18:59:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_shadowed(t_scene world, t_tuple point)
{
	float	distance;
	t_tuple	vec;
	t_tuple	direction;
	t_ray	r;
	t_intrs	inters;

	vec = world.light[0].pos - point;
	distance = vec_magn(vec);
	direction = vec_norm(vec);

	r = ray(point, direction);
	inters = intersect_world(world, r);
	inters.i[0] = find_hit(inters);
	if (inters.i[0].def && inters.i[0].t < distance)
		return (true);
	return (false);
}

/* The multiple shadow version
bool	is_shadowed(t_scene world, t_tuple point)
{
	float	distance;
	t_tuple	vec[2];
	t_ray	r;
	t_intrs	inters;
	t_unt	i[2];

	i[0] = 0;
	i[1] = 0;
	while (i[0] < world.li_size.use)
	{
		vec[0] = world.light[i[0]].pos - point;
		distance = vec_magn(vec[0]);
		vec[1] = vec_norm(vec[0]);

		r = ray(point, vec[1]);
		inters = intersect_world(world, r);
		inters.i[0] = find_hit(inters);
		if (inters.i[0].def && inters.i[0].t < distance)
			i[1]++;
		i[0]++;
	}
	return (i[1]);
}*/
