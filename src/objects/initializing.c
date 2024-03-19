/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:42:08 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/19 18:10:26 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	sphere(void)
{
	t_obj	sphere;

	sphere.defined = true;
	sphere.diameter = 1;
	sphere.pos = origin();
	set_transform(&sphere, get_id4mtrx());
	sphere.m = material();
	return (sphere);
}

t_obj	point_light(t_tuple pos, t_color intensity)
{
	t_obj	light;

	light.defined = true;
	light.pos = pos;
	light.col = intensity;
	return (light);
}

t_mater	material(void)
{
	t_mater	m;

	m.color = set_col(1, 1, 1);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}

void	set_transform(t_obj *o, t_4mtrx m)
{
	o->transform = m;
	o->inverse = inverse_4mtrx(m);
	o->trans_inv = transpose(o->inverse);
}
