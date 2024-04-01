/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:19:51 by marvin            #+#    #+#             */
/*   Updated: 2024/04/01 18:19:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Wraps the precomputations and the shade hit function
 *
 * @param world
 * @param ray given ray wich will set pre computations
 * @return t_color
 */
t_color	color_at(t_scene world, t_ray ray)
{
	t_comps	computes;
	t_inter	hit_point;

	hit_point = find_hit(intersect_world(world, ray));
	if (!hit_point.def)
		return (set_col(0, 0, 0));
	computes = prepare_computations(hit_point, ray);
	return (shade_hit(world, computes));
}

/**
 * @brief Work in progress, rather a take on anti-aliasing,
 * very basic and naive approach, give out a blured scene
 *
 * @brief replaces color_at and takes care of the ray
 * @brief /!\ takes 9 times longer to render
 *
 * @param world
 * @param x
 * @param y
 * @param camera
 * @return t_color
 */
t_color	anti_alias(t_scene world, t_unt	x, t_unt y, t_cam camera)
{
	t_color	average[9];
	t_ray	r;
	t_unt	i;
	t_unt	j;
	float	d;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			r = ray_for_pixel(camera, x - 1 + i, y - 1 + j);
			average[i * 3 + j] = color_at(world, r);
			j++;
		}
		i++;
	}
	d = (1 - AA_RATIO) / 8;
	return (tup_col(average[0].tuple * d + average[1].tuple * d
			+ average[2].tuple * d + average[3].tuple * d
			+ average[4].tuple * d + average[5].tuple * AA_RATIO
			+ average[6].tuple * d + average[7].tuple * d
			+ average[8].tuple * d));
}
