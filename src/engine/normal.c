/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:25:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/24 19:24:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	normal_at(t_obj object, t_tuple point)
{
	t_tuple	normal;

	normal = origin();
	if (object.type == OBJ_SPHERE)
		normal = sp_normal_at(object, point);
	else if (object.type == OBJ_PLANE)
		normal = pl_normal_at(object, point);
	else if (object.type == OBJ_CYLINDER)
		normal = cy_normal_at(object, point);
	else if (object.type == OBJ_CUBE)
		normal = cube_normal_at(object, point);
	return (normal);
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (in - normal * 2 * vec_dot(in, normal));
}
