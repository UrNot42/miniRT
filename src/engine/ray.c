/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:00:03 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/11 17:31:36 by ulevallo         ###   ########.fr       */
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

t_tuple	position(t_ray beam, float time)
{
	return (beam.origin + beam.direction * time);
}
