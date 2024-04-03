/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:36:14 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 09:20:32 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_4mtrx	rotation_x(float r)
{
	t_4mtrx	translate;

	translate = get_id4mtrx();
	translate[1][1] = cos(r);
	translate[1][2] = -sin(r);
	translate[2][1] = sin(r);
	translate[2][2] = cos(r);
	return (translate);
}

t_4mtrx	rotation_y(float r)
{
	t_4mtrx	translate;

	translate = get_id4mtrx();
	translate[0][0] = cos(r);
	translate[0][2] = sin(r);
	translate[2][0] = -sin(r);
	translate[2][2] = cos(r);
	return (translate);
}

t_4mtrx	rotation_z(float r)
{
	t_4mtrx	translate;

	translate = get_id4mtrx();
	translate[0][0] = cos(r);
	translate[0][1] = -sin(r);
	translate[1][0] = sin(r);
	translate[1][1] = cos(r);
	return (translate);
}

t_4mtrx	orientation_matrix(t_tuple normalv)
{
	t_4mtrx	orientation;
	t_tuple	q;
	t_tuple	a;
	float	t;

	t = acosf(vec_dot(set_vec(0, 1, 0), normalv));
	a = vec_cross(set_vec(0, 1, 0), normalv);
	a = vec_norm(a);
	q.x = cosf(t);
	q.y = sinf(t);
	q.z = 1.0 - q.x;
	orientation = set_4mtrx((t_i4mtr){
			q.z * a.x * a.x + q.x, q.z * a.x * a.y - q.y * a.z,
			q.z * a.x * a.z + q.y * a.y, 0,
			q.z * a.x * a.y + q.y * a.z, q.z * a.y * a.y + q.x,
			q.z * a.y * a.z - q.y * a.x, 0,
			q.z * a.x * a.z - q.y * a.y, q.z * a.y * a.z + q.y * a.x,
			q.z * a.z * a.z + q.x, 0,
			0, 0, 0, 1});
	return (orientation);
}

t_4mtrx	shearing(t_shear rel)
{
	t_4mtrx	translate;

	translate = get_id4mtrx();
	translate[0][1] = rel[0];
	translate[0][2] = rel[1];
	translate[1][0] = rel[2];
	translate[1][2] = rel[3];
	translate[2][0] = rel[4];
	translate[2][1] = rel[5];
	return (translate);
}
