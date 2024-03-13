/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:25:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/13 16:24:24 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	normal_at(t_obj o, t_tuple point)
{
	t_ray	object;
	t_ray	world;

	world.origin = point;
	object.origin = tup_mtrx(inverse_4mtrx(o.transform), world.origin);
	object.direction = object.origin - origin();
	world.direction = tup_mtrx(transpose(inverse_4mtrx(o.transform)),
			object.direction);
	world.direction.w = 0;
	return (vec_norm(world.direction));
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (in - normal * 2 * vec_dot(in, normal));
}
