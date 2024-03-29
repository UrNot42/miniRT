/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:25:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/29 17:46:20 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Wrapper function wich pipes to the correct local normal function
 *
 * @param object
 * @param point
 * @return the correct normal
 * - if the object is undefined returns a vector(0, 0, 0)
 */
t_tuple	normal_at(t_obj object, t_tuple point)
{
	t_tuple	normal;

	normal = set_vec(0, 0, 0);
	if (object.kind == OBJ_SPHERE)
		normal = sp_normal_at(object.sphere, point);
	else if (object.kind == OBJ_PLANE)
		normal = pl_normal_at(object.plane, point);
	else if (object.kind == OBJ_CYLINDER)
		normal = cy_normal_at(object.cylinder, point);
	else if (object.kind == OBJ_CUBE)
		normal = cube_normal_at(object.cube, point);
	else if (object.kind == OBJ_CONE)
		normal = cone_normal_at(object.cone, point);
	return (normal);
}

/**
 * @brief basic reflection equation
 *
 * @param in
 * @param normal
 * @return the actual reflected vector
 */
t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (in - normal * 2 * vec_dot(in, normal));
}
