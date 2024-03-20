/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:10:05 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/20 11:33:56 by ulevallo         ###   ########.fr       */
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
	return (computations);
}
