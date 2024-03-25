/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:47:11 by marvin            #+#    #+#             */
/*   Updated: 2024/03/24 15:47:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	cube(void)
{
	t_obj	cube;

	cube.type = OBJ_CUBE;
	cube.defined = true;
	cube.pos = origin();
	cube.m = material();
	set_transform(&cube, get_id4mtrx());
	return (cube);
}

void	check_axis(float origin, float direction, float min_max[][2])
{
	float	tmp;

	if (fabs(direction) >= EPSILON)
	{
		(*min_max)[0] = (-1 - origin) / direction;
		(*min_max)[1] = (1 - origin) / direction;
	}
	else
	{
		(*min_max)[0] = (-1 - origin) * INFINITY;
		(*min_max)[1] = (1 - origin) * INFINITY;
	}
	if ((*min_max)[0] > (*min_max)[1])
	{
		tmp = (*min_max)[0];
		(*min_max)[0] = (*min_max)[1];
		(*min_max)[1] = tmp;
	}
}

/**
 * In the scope of this function the element
 * - [0] indicates minimum
 * - [1] indicates maximum
*/
t_intrs cube_intersect(t_obj *cube, t_ray r)
{
	float	xt[2];
	float	yt[2];
	float	zt[2];
	float	t[2];
	t_intrs	x;

	x.count = 0;
	r = ray_transform(r, cube->inverse);
	check_axis(r.origin.x, r.direction.x, &xt);
	check_axis(r.origin.y, r.direction.y, &yt);
	check_axis(r.origin.z, r.direction.z, &zt);
	t[0] = fmaxf(fmaxf(xt[0], yt[0]), zt[0]);
	t[1] = fminf(fminf(xt[1], yt[1]), zt[1]);
	if (t[0] > t[1])
		return (x);
	x.i[0] = get_inter(t[0], cube);
	x.i[1] = get_inter(t[1], cube);
	x.count = 2;
	return (x);
}


t_tuple	cube_normal_at(t_obj cube, t_tuple point)
{
	t_tuple	direction;
	t_tuple	vector;
	float	maxc;

	(void)cube;
	maxc = fmaxf(fmaxf(point.x, point.y), point.z);
	vector = set_vec(point.x, 0, 0);
	if (maxc == fabs(point.y))
		vector = set_vec(0, point.y, 0);
	else if (maxc == fabs(point.z))
		vector = set_vec(0, 0, point.z);
	direction = tup_mtrx(cube.inverse, vector);
	direction.w = 0;
	return (vec_norm(direction));
}
