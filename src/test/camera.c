/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:47:50 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/20 19:47:10 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_view_default(void)
{
	t_4mtrx	t;
	t_tuple	from;
	t_tuple	to;
	t_tuple	up;
	t_unt	err;

	scenario_start("The transformation matrix for the default orientation");
	given("from ← point(0, 0, 0)", 0);
	given("to ← point(0, 0, -1)", 1);
	given("up ← vector(0, 1, 0)", 2);
	from = set_point(0, 0, 0);
	to = set_point(0, 0, -1);
	up = set_vec(0, 1, 0);
	when("t ← view_transform(from, to, up)", 0);
	t = view_transform(from, to, up);
	err = then("t = identity_matrix", matr_4_eq(t, get_id4mtrx()), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_view_z_positive(void)
{
	t_4mtrx	t;
	t_tuple	from;
	t_tuple	to;
	t_tuple	up;
	t_unt	err;

	scenario_start("A view transformation matrix looking in positive z direction");
	given("from ← point(0, 0, 0)", 0);
	given("to ← point(0, 0, 1)", 1);
	given("up ← vector(0, 1, 0)", 2);
	from = set_point(0, 0, 0);
	to = set_point(0, 0, 1);
	up = set_vec(0, 1, 0);
	when("t ← view_transform(from, to, up)", 0);
	t = view_transform(from, to, up);
	err = then("t = scaling(-1, 1, -1)",
			matr_4_eq(t, scale_mtrx(-1, 1, -1)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_view_moves_world(void)
{
	t_4mtrx	t;
	t_tuple	from;
	t_tuple	to;
	t_tuple	up;
	t_unt	err;

	scenario_start("The view transformation moves the world");
	given("from ← point(0, 0, 8)", 0);
	given("to ← point(0, 0, 0)", 1);
	given("up ← vector(0, 1, 0)", 2);
	from = set_point(0, 0, 8);
	to = set_point(0, 0, 0);
	up = set_vec(0, 1, 0);
	when("t ← view_transform(from, to, up)", 0);
	t = view_transform(from, to, up);
	err = then("t = translation(0, 0, -8)",
			matr_4_eq(t, translation_mtrx(0, 0, -8)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_view_transfrom(void)
{
	t_4mtrx	t;
	t_tuple	from;
	t_tuple	to;
	t_tuple	up;
	t_unt	err;

	scenario_start("An arbitrary view transformation");
	given("from ← point(1, 3, 2)", 0);
	given("to ← point(4, -2, 8)", 1);
	given("up ← vector(1, 1, 0)", 2);
	from = set_point(1, 3, 2);
	to = set_point(4, -2, 8);
	up = set_vec(1, 1, 0);
	when("t ← view_transform(from, to, up)", 0);
	t = view_transform(from, to, up);
	err = then("t is the following 4x4 matrix:\n| -0.50709 |  0.50709 |  0.67612\
 | -2.36643 |\n|  0.76772 |  0.60609 |  0.12122 | -2.82843 |\n| -0.35857 |  0.59\
761 | -0.71714 |  0.00000 |\n|  0.00000 |  0.00000 |  0.00000 |  1.00000 |",
			matr_4_eq(t, set_4mtrx((t_i4mtr){-0.50709, 0.50709, 0.67612,
					-2.36643, 0.76772, 0.60609, 0.12122, -2.82843, -0.35857,
					0.59761, -0.71714, 0.00000, 0.00000, 0.00000, 0.00000,
					1.00000})), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_cam_constructing(void)
{
	t_unt	err;
	t_cam	c;
	t_unt	hsize;
	t_unt	vsize;
	float	field_of_view;

	scenario_start("Constructing a camera");
	given("hsize ← 160", 0);
	given("vsize ← 120", 1);
	hsize = 160;
	vsize = 120;
	given("field_of_view ← π/2", 2);
	field_of_view = M_PI / 2;
	when("c ← camera(hsize, vsize, field_of_view)", 0);
	c = camera(hsize, vsize, field_of_view);
	err = then("c.hsize = 160", c.hz_size == 160, 0);
	err += then("c.vsize = 120", c.v_size == 120, 1);
	err += then("c.field_of_view = π/2", f_eq(c.o.fov, field_of_view), 2);
	err += then("c.transform = identity_matrix", 0, 3);
	scenario_end(err);
	return (err);
}

t_unt	test_cam_pix_size(void)
{
	t_unt	err[2];
	t_cam	c;

	scenario_start("The pixel size for a horizontal canvas");
	given("c ← camera(200, 125, π/2)", 0);
	c = camera(200, 125, M_PI / 2);
	err[0] = then("c.pixel_size = 0.01", f_eq(c.pxl_size, 0.01), 0);
	scenario_end(err[0]);
	scenario_start("The pixel size for a vertical canvas");
	given("c ← camera(125, 200, π/2)", 0);
	c = camera(125, 200, M_PI / 2);
	err[1] = then("c.pixel_size = 0.01", f_eq(c.pxl_size, 0.01), 0);
	scenario_end(err[1]);
	return (err[0] + err[1]);
}

t_unt	test_cam_ray_construction(void)
{
	t_unt	err[3];

	scenario_start("Constructing a ray through the center of the canvas");
	given("c ← camera(201, 101, π/2)", 0);
	when("r ← ray_for_pixel(c, 100, 50)", 0);
	err[0] = then("r.origin = point(0, 0, 0)", 0, 0);
	err[0] += then("r.direction = vector(0, 0, -1)", 0, 1);
	scenario_end(err[0]);
	scenario_start("Constructing a ray through a corner of the canvas");
	given("c ← camera(201, 101, π/2)", 0);
	when("r ← ray_for_pixel(c, 0, 0)", 0);
	err[1] = then("r.origin = point(0, 0, 0)", 0, 0);
	err[1] += then("r.direction = vector(0.66519, 0.33259, -0.66851)", 0, 1);
	scenario_end(err[1]);
	scenario_start("Constructing a ray when the camera is transformed");
	given("c ← camera(201, 101, π/2)", 0);
	when("c.transform ← rotation_y(π/4) * translation(0, -2, 5)", 0);
	when("r ← ray_for_pixel(c, 100, 50)", 1);
	err[2] = then("r.origin = point(0, 2, -5)", 0, 0);
	err[2] += then("r.direction = vector(√2/2, 0, -√2/2)", 0, 1);
	scenario_end(err[2]);
	return (err[0] + err[1] + err[2]);
}

t_unt	test_cam_rendering(void)
{
	t_unt	err;

	scenario_start("Rendering a world with a camera");
	given("w ← default_world()", 0);
	given("c ← camera(11, 11, π/2)", 1);
	given("from ← point(0, 0, -5)", 2);
	given("to ← point(0, 0, 0)", 3);
	given("up ← vector(0, 1, 0)", 4);
	given("c.transform ← view_transform(from, to, up)", 5);
	when("image ← render(c, w)", 0);
	err = then("pixel_at(image, 5, 5) = color(0.38066, 0.47583, 0.2855)", 0, 0);
	scenario_end(err);
	return (err);
}
