/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:10:05 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/26 13:58:38 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief handles all ray operations so it can be handed off without
 * to later functions
 *
 * @param i the hit point of the ray
 * @param ray
 * @return t_comps
 */
t_comps	prepare_computations(t_inter hit, t_ray ray)
{
	t_comps	computations;

	computations.t = hit.t;
	computations.obj = hit.obj;
	computations.point = ray_pos(ray, computations.t);
	computations.eyev = -ray.direction;
	computations.normalv = normal_at((*computations.obj), computations.point);
	computations.inside = false;
	if (vec_dot(computations.normalv, computations.eyev) < 0)
	{
		computations.inside = true;
		computations.normalv = -computations.normalv;
	}
	computations.over_point = computations.point
		+ computations.normalv * EPSILON;
	return (computations);
}
