/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:42:08 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/02 20:27:02 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	light(t_tuple pos, t_color intensity)
{
	t_light	light;

	light = (t_light){0};
	light.pos = pos;
	light.def = true;
	light.color = intensity;
	light.ratio = 1;
	return (light);
}

t_obj	o_light(t_tuple pos, t_color intensity)
{
	t_obj	obj;

	obj = (t_obj){0};
	obj.light = light(pos, intensity);
	obj.kind = OBJ_SRC_LIGHT;
	return (obj);
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

t_obj	o_get(t_obj_kind type)
{
	if (type == OBJ_AMB_LIGHT || type == OBJ_SRC_LIGHT)
		return (o_light(origin(), set_col(0, 0, 0)));
	if (type == OBJ_CAMERA)
		return (o_camera(0, 0, 0));
	if (type == OBJ_SPHERE)
		return (o_sphere());
	if (type == OBJ_PLANE)
		return (o_plane());
	if (type == OBJ_CYLINDER)
		return (o_cylinder());
	if (type == OBJ_CONE)
		return (o_cone());
	if (type == OBJ_CUBE)
		return (o_cube());
	return ((t_obj){0});
}
