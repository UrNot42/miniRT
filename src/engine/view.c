/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:16:11 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 13:32:24 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	o_camera(t_unt hsize, t_unt vsize, float field_of_view)
{
	t_obj	obj;

	obj = (t_obj){0};
	obj.camera = camera(hsize, vsize, field_of_view);
	obj.kind = OBJ_CAMERA;
	return (obj);
}

t_cam	camera(t_unt hsize, t_unt vsize, float field_of_view)
{
	t_cam	cam;
	float	half_view;
	float	aspect;

	cam.hz_size = hsize;
	cam.v_size = vsize;
	cam.fov = field_of_view;
	set_transform(&cam.mtx, get_id4mtrx());
	half_view = tanf(field_of_view / 2);
	cam.half_height = half_view;
	cam.half_width = half_view;
	aspect = (float)cam.hz_size / (float)cam.v_size;
	if (aspect >= 1)
		cam.half_height /= aspect;
	else
		cam.half_width *= aspect;
	cam.pxl_size = (cam.half_width * 2) / (float)cam.hz_size;
	return (cam);
}

t_4mtrx	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple	left;
	t_tuple	true_up;
	t_tuple	forward;
	t_tuple	upn;
	t_4mtrx	orientation;

	forward = vec_norm(to - from);
	upn = vec_norm(up);
	left = vec_cross(forward, upn);
	if (tup_eq(left, set_vec(0, 0, 0)))
	{
		left = vec_cross(forward, set_vec(0, 0, 1));
		if (tup_eq(left, set_vec(0, 0, 0)))
			left = vec_cross(forward, set_vec(1, 0, 0));
	}
	true_up = vec_cross(left, forward);
	orientation = set_4mtrx((t_i4mtr){left.x, left.y, left.z, 0,
			true_up.x, true_up.y, true_up.z, 0,
			-forward.x, -forward.y, -forward.z, 0,
			0, 0, 0, 1});
	return (orientation * translation_mtrx(-from.x, -from.y, -from.z));
}

t_ray	ray_for_pixel(t_cam view, t_unt	px, t_unt py)
{
	t_tuple	offset;
	t_tuple	world;
	t_tuple	pixel;
	t_tuple	r_origin;
	t_ray	r;

	offset.x = ((float)px + 0.5) * view.pxl_size;
	offset.y = ((float)py + 0.5) * view.pxl_size;
	world.x = view.half_width - offset.x;
	world.y = view.half_height - offset.y;
	pixel = tup_mtrx(inverse_4mtrx(view.mtx.transform),
			set_point(world.x, world.y, -1));
	r_origin = tup_mtrx(inverse_4mtrx(view.mtx.transform), origin());
	r = ray(r_origin, vec_norm(pixel - r_origin));
	return (r);
}
