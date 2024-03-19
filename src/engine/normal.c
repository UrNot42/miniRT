/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:25:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/19 18:10:43 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	normal_at(t_obj o, t_tuple point)
{
	t_ray	object;
	t_ray	world;

	world.origin = point;
	object.origin = tup_mtrx(o.inverse, world.origin);
	object.direction = object.origin - origin();
	world.direction = tup_mtrx(o.trans_inv, object.direction);
	world.direction.w = 0;
	return (vec_norm(world.direction));
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (in - normal * 2 * vec_dot(in, normal));
}
