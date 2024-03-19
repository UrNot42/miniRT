/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:00:03 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/19 10:06:40 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	new_beam;

	new_beam.origin = origin;
	new_beam.direction = direction;
	return (new_beam);
}

t_tuple	ray_pos(t_ray beam, float time)
{
	return (beam.origin + beam.direction * time);
}

t_ray	ray_transform(t_ray r, t_4mtrx m)
{
	return ((t_ray){tup_mtrx(m, r.origin), tup_mtrx(m, r.direction)});
}
