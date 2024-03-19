/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:34:03 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/19 18:15:39 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	lighting(t_mater m, t_obj light, t_tuple p, t_ray v)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_tuple	lightv;
	float	dot_normal;

	ambient.tuple = m.color.tuple * light.col.tuple;
	lightv = vec_norm(light.pos - p);
	dot_normal = vec_dot(lightv, v.direction);
	diffuse = set_col(0, 0, 0);
	specular = set_col(0, 0, 0);
	if (dot_normal >= 0)
	{
		diffuse.tuple = ambient.tuple * m.diffuse * dot_normal;
		dot_normal = vec_dot(reflect(-lightv, v.direction), v.origin);
		if (dot_normal > 0)
			specular.tuple = light.col.tuple * m.specular
				* powf(dot_normal, m.shininess);
	}
	ambient.tuple = m.color.tuple * light.col.tuple * m.ambient;
	return (tup_col(ambient.tuple + diffuse.tuple + specular.tuple));
}
