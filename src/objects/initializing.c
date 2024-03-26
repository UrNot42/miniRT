/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:42:08 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/26 09:56:56 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	point_light(t_tuple pos, t_color intensity)
{
	t_obj	light;

	light = (t_obj){0};
	light.type = OBJ_SRC_LIGHT;
	light.defined = true;
	light.pos = pos;
	light.m.col = intensity;
	return (light);
}

t_mater	material(void)
{
	t_mater	m;

	m.col = set_col(1, 1, 1);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}

// Sets a single intersection
t_inter	get_inter(float time, t_obj *obj)
{
	return ((t_inter){time, obj, obj != NULL});
}
