/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:18:06 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 09:04:48 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	vec_magn(t_tuple vec)
{
	float	magnitude;

	if (!is_vec(vec))
		return (-1);
	magnitude = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (magnitude);
}

t_tuple	vec_norm(t_tuple vec)
{
	float	magnitude;

	magnitude = vec_magn(vec);
	if (magnitude)
		return (vec / magnitude);
	return (set_vec(0, 0, 0));
}

float	vec_dot(t_tuple a, t_tuple b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

t_tuple	vec_cross(t_tuple a, t_tuple b)
{
	return (set_vec(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}
