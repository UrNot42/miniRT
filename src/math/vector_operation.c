/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:18:06 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 18:21:52 by ulevallo         ###   ########.fr       */
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
	return (tup_div(vec, vec_magn(vec)));
}
