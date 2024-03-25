/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:10:05 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/23 19:43:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_comps	prepare_computations(t_inter i, t_ray ray)
{
	t_comps	computations;

	computations.t = i.t;
	computations.obj = i.obj;
	computations.point = ray_pos(ray, computations.t);
	computations.eyev = -ray.direction;
	computations.normalv = normal_at((*computations.obj), computations.point);
	computations.inside = false;
	if (vec_dot(computations.normalv, computations.eyev) < 0)
	{
		computations.inside = true;
		computations.normalv = -computations.normalv;
	}
	computations.over_point = computations.point + computations.normalv * EPSILON;
	return (computations);
}
