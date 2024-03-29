/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:33:19 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/29 18:49:31 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_cap(t_ray r, float t, float radius)
{
	float	x;
	float	z;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;
	return (((x * x) + (z * z)) <= (radius * radius));
}

void	cone_intersect_caps(t_obj *obj, t_ray r, t_intrs *xs)
{
	float		t;
	t_cone		co;

	if (f_eq(r.direction.y, 0))
		return ;
	co = obj->cone;
	if (co.min_caped)
	{
		t = (co.minimum - r.origin.y) / r.direction.y;
		if (check_cap(r, t, fabs(co.minimum)))
			xs->i[xs->count++] = get_inter(t, obj);
	}
	if (co.max_caped)
	{
		t = (co.maximum - r.origin.y) / r.direction.y;
		if (check_cap(r, t, fabs(co.maximum)))
			xs->i[xs->count++] = get_inter(t, obj);
	}
}

static t_intrs	cone_get_inters(float t1, float t2, t_obj *obj, t_ray r)
{
	t_intrs	x;
	float	y[2];

	x.count = 0;
	if (t1 > t2)
		fswap(&t1, &t2);
	y[0] = r.origin.y + t1 * r.direction.y;
	if (obj->cone.minimum < y[0] && y[0] < obj->cone.maximum)
		x.i[x.count++] = get_inter(t1, obj);
	y[1] = r.origin.y + t2 * r.direction.y;
	if (obj->cone.minimum < y[1] && y[1] < obj->cone.maximum)
		x.i[x.count++] = get_inter(t2, obj);
	return (x);
}

t_intrs	cone_intersect(t_obj *obj, t_ray r)
{
	float	a;
	float	b;
	float	c;
	float	disc;
	t_intrs	x;

	r = ray_transform(r, obj->cone.inverse);
	x.count = 0;
	a = (r.direction.x * r.direction.x) - (r.direction.y * r.direction.y)
		+ (r.direction.z * r.direction.z);
	b = (2 * r.origin.x * r.direction.x) - (2 * r.origin.y * r.direction.y)
		+ 2 * (r.origin.z * r.direction.z);
	c = (r.origin.x * r.origin.x) - (r.origin.y * r.origin.y)
		+ (r.origin.z * r.origin.z);
	if (f_eq(a, 0) && !f_eq(b, 0))
		x.i[x.count++] = get_inter((-c / (2 * b)), obj);
	disc = b * b - 4 * a * c;
	if (disc < 0 || (f_eq(a, 0) && f_eq(b, 0)))
		return (x);
	if (!f_eq(a, 0))
		x = cone_get_inters((-b - sqrtf(disc)) / (2 * a),
				(-b + sqrtf(disc)) / (2 * a), obj, r);
	cone_intersect_caps(obj, r, &x);
	return (x);
}
