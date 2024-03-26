/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:00:03 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/26 14:02:03 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief creates a ray
 * default way to initiate a ray
 *
 * @param origin starting point of the rays
 * @param direction which the ray points to
 * @return t_ray
 */
t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	new_beam;

	new_beam.origin = origin;
	new_beam.direction = direction;
	return (new_beam);
}

/**
 * @brief casts the ray in its direction by 'time' factor
 *
 * @param beam
 * @param time scale factor
 * @return new point
 */
t_tuple	ray_pos(t_ray beam, float time)
{
	return (beam.origin + beam.direction * time);
}

/**
 * @brief Transform a ray with a given matrix
 *
 * @param r
 * @param m transformation matrix
 * @return t_ray
 */
t_ray	ray_transform(t_ray beam, t_4mtrx m)
{
	return ((t_ray){tup_mtrx(m, beam.origin), tup_mtrx(m, beam.direction)});
}
