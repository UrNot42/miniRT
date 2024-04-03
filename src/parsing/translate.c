/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:20:29 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 13:48:50 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_tuple	get_scale(t_obj *obj)
{
	t_tuple	scale;

	scale = set_vec(1, 1, 1);
	if (obj->kind == OBJ_SPHERE)
	{
		scale = set_vec(obj->sphere.diameter,
				obj->sphere.diameter, obj->sphere.diameter);
	}
	if (obj->kind == OBJ_CYLINDER || obj->kind == OBJ_CONE)
	{
		scale = set_vec(obj->cylinder.width,
				1, obj->cylinder.width);
	}
	if (obj->kind == OBJ_CUBE)
	{
		scale = obj->cube.size;
	}
	return (scale);
}

void	translate_matrix(t_obj *obj, t_size size)
{
	t_unt	i;
	t_4mtrx	orientation;
	t_tuple	scale;

	i = 0;
	while (i < size.use)
	{
		if (obj[i].kind == OBJ_PLANE
			|| obj[i].kind == OBJ_CYLINDER || obj[i].kind == OBJ_CUBE
			|| obj[i].kind == OBJ_CONE)
			orientation = orientation_matrix(obj[i].plane.normal);
		else
			orientation = get_id4mtrx();
		scale = get_scale(&obj[i]);
		if (obj[i].kind == OBJ_SPHERE || obj[i].kind == OBJ_PLANE
			|| obj[i].kind == OBJ_CYLINDER || obj[i].kind == OBJ_CUBE
			|| obj[i].kind == OBJ_CONE)
		{
			set_transform(&obj[i].sphere.mtx,
				tup_translate_m(obj[i].pos) * orientation * tup_scale_m(scale));
		}
		i++;
	}
}

void	translate_set_camera(t_cam *cam)
{
	t_cam	cam_tmp;
	t_tuple	to;
	t_tuple	from;
	t_tuple	up;

	(*cam).fov = ((*cam).fov / 180) * M_PI;
	cam_tmp = camera(BASE_X, BASE_Y, cam->fov);
	(*cam).hz_size = cam_tmp.hz_size;
	(*cam).v_size = cam_tmp.v_size;
	(*cam).half_height = cam_tmp.half_height;
	(*cam).half_width = cam_tmp.half_width;
	(*cam).pxl_size = cam_tmp.pxl_size;
	(*cam).mtx = cam_tmp.mtx;
	from = cam->pos;
	to = cam->pos + cam->normal;
	up = set_vec(0, 1, 0);
	set_transform(&cam->mtx, view_transform(from, to, up));
}

void	translate_points(t_scene *world)
{
	t_unt	i;
	t_tuple	pos;

	i = 0;
	while (i < world->obj_size.use)
	{
		pos = world->objects[i].pos;
		world->objects[i].pos = set_point(pos.x, pos.y, pos.z);
		i++;
	}
	i = 0;
	while (i < world->li_size.use)
	{
		pos = world->light[i].pos;
		world->light[i].pos = set_point(pos.x, pos.y, pos.z);
		i++;
	}
	pos = world->camera.pos;
	world->camera.pos = set_point(pos.x, pos.y, pos.z);
	pos = world->ambient_light.pos;
	world->ambient_light.pos = set_point(pos.x, pos.y, pos.z);
}

void	translate_special_obj(t_scene *world)
{
	t_unt		i;
	t_cylinder	*cy;

	i = 0;
	while (i < world->obj_size.use)
	{
		if (world->objects[i].kind == OBJ_CYLINDER
			|| world->objects[i].kind == OBJ_CONE)
		{
			cy = &world->objects[i].cylinder;
			cy->minimum = -cy->height / 2;
			cy->maximum = cy->height / 2;
			cy->min_caped = true;
			cy->max_caped = true;
		}
		i++;
	}
}
