/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:34:03 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/13 19:19:34 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	lighting(t_mater m, t_obj light, t_tuple p, t_ray v)
{
	t_color	effective;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_tuple	lightv;
	float	reflect_dot_eye;
	float	light_dot_normal;

	effective.tuple = m.color.tuple * light.col.tuple;
	lightv = vec_norm(light.pos - p);
	ambient.tuple = effective.tuple * m.ambient;
	light_dot_normal = vec_dot(lightv, v.direction);
	if (light_dot_normal < 0)
	{
		diffuse = set_col(0, 0, 0);
		specular = set_col(0, 0, 0);
	}
	else
	{
		diffuse.tuple = effective.tuple * m.diffuse * light_dot_normal;
		reflect_dot_eye = vec_dot(reflect(-lightv, v.direction), v.origin);
		if (reflect_dot_eye > 0)
			specular.tuple = light.col.tuple * m.specular
				* powf(reflect_dot_eye, m.shininess);
		else
			specular = set_col(0, 0, 0);
	}
	return (tup_col(ambient.tuple + diffuse.tuple + specular.tuple));
}
