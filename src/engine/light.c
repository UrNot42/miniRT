/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:34:03 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/20 16:20:39 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief ### Main function to light the scene
 * @brief #### Calculates the sum of color to get phong reflection model
 *
 * @brief The use of this structure to encapsulate two elements is strictly
 *  for 42s Norm
 * @brief Normally use the function prototype should be
 * `lighting(t_matter material, t_obj light, t_tuple point,
 *  t_tuple eye_vector, t_tuple normal_vector)`
 *
 * @param m is the matter which details reflections and such
 * @param light the light to take in consideration
 * @param p the point which we are evaluating
 * @param v basically encapsulates two vectors {eye_vector, normal_vector}
 * Common use expects a constant litteral for both vectors
 * @return the color of the pixel
 */
t_color	lighting(t_mater m, t_obj light, t_tuple p, t_ray v)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_tuple	lightv;
	float	dot_normal;

	ambient.tuple = m.color.tuple * light.col.tuple;
	lightv = vec_norm(light.pos - p);
	dot_normal = vec_dot(lightv, v.direction);
	diffuse = set_col(0, 0, 0);
	specular = set_col(0, 0, 0);
	if (dot_normal >= 0)
	{
		diffuse.tuple = ambient.tuple * m.diffuse * dot_normal;
		dot_normal = vec_dot(reflect(-lightv, v.direction), v.origin);
		if (dot_normal > 0)
			specular.tuple = light.col.tuple * m.specular
				* powf(dot_normal, m.shininess);
	}
	ambient.tuple = m.color.tuple * light.col.tuple * m.ambient;
	return (tup_col(ambient.tuple + diffuse.tuple + specular.tuple));
}

t_color	shade_hit(t_scene world, t_comps computes)
{
	t_unt	i;
	t_color	color;
	t_color	tmp;

	if (!world.li_size.use)
		return (set_col(0, 0, 0));
	color = lighting(computes.obj->m, world.light[0], computes.point,
			(t_ray){computes.eyev, computes.normalv});
	if (world.li_size.use == 1)
		return (color);
	i = 1;
	while (i < world.li_size.use)
	{
		tmp = lighting(computes.obj->m, world.light[i], computes.point,
				(t_ray){computes.eyev, computes.normalv});
		color.tuple = color.tuple * tmp.tuple;
		i++;
	}
	return (color);
}

t_color	color_at(t_scene world, t_ray ray)
{
	t_color	color;
	t_comps	computes;
	t_inter	hit_point;

	hit_point = find_hit(intersect_world(world, ray));
	if (!hit_point.def)
		return (set_col(0, 0, 0));
	printf("hit: %f\n", hit_point.t);
	computes = prepare_computations(hit_point, ray);
	color = shade_hit(world, computes);
	return (color);
}
