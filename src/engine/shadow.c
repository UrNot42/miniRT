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

/**
 * @brief Boolean test checking if a 3d point is hit by 'light' or not
 *
 * @param world
 * @param point
 * @param light
 * @return true
 * @return false
 */
bool	is_shadowed(t_scene world, t_tuple point, t_obj light)
{
	float	distance;
	t_tuple	vec;
	t_tuple	direction;
	t_ray	r;
	t_intrs	inters;

	vec = light.pos - point;
	distance = vec_magn(vec);
	direction = vec_norm(vec);
	r = ray(point, direction);
	inters = intersect_world(world, r);
	inters.i[0] = find_hit(inters);
	if (inters.i[0].def && inters.i[0].t < distance)
		return (true);
	return (false);
}
