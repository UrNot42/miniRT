/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:34:03 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/29 18:37:37 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief ### Main light algorithm
 * @brief #### Calculates the sum of color based on the Phong reflection model
 *
 * @brief
 * The use of this structure to encapsulate elements is strictly
 * to respect 42's Norm.
 *
 * @brief
 * Normally use the function prototype should be
 * lighting(t_matter material, t_obj light, t_tuple point,
 *  t_tuple eye_vector, t_tuple normal_vector)`.
 *
 * Common use expects a constant litteral for sending elements
 *
 * @param matter is the matter which details reflections and such
 * @param light the light to take in consideration
 * @param p the point which we are evaluating
 * @param eye_vector expressing where the eye gets the light from
 * @param normal_vector relative to the shape where does the norm expresses
 * @return the color of the pixel
 */
t_color	lighting(t_lgting l)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_tuple	lightv;
	float	dot_normal;

	if (l.in_shadow)
		return (tup_col(l.mater.col.tuple * 0.1));
	ambient.tuple = l.mater.col.tuple * l.light.m.col.tuple;
	lightv = vec_norm(l.light.pos - l.point);
	dot_normal = vec_dot(lightv, l.normalv);
	if (dot_normal < 0)
		return (tup_col(ambient.tuple * l.mater.ambient));
	diffuse.tuple = ambient.tuple * l.mater.diffuse * dot_normal;
	dot_normal = vec_dot(reflect(-lightv, l.normalv), l.eyev);
	if (dot_normal > 0)
		specular.tuple = l.light.m.col.tuple * l.mater.specular
			* powf(dot_normal, l.mater.shininess);
	else
		specular = set_col(0, 0, 0);
	ambient.tuple *= l.mater.ambient;
	return (tup_col(ambient.tuple + diffuse.tuple + specular.tuple));
}

/**
 * @brief ### Gives out the sum of lighting on a point with evey light source
 *
 * @param world scene which has light components and objects
 * for shadow intersections
 * @param computes components needed by the lighting calculation function
 * @return t_color Sum of light effects
 */
t_color	shade_hit(t_scene world, t_comps computes)
{
	t_unt	i;
	t_color	color;
	t_color	tmp;

	color = set_col(0, 0, 0);
	if (!world.li_size.use)
		return (color);
	i = 0;
	while (i < world.li_size.use)
	{
		tmp = lighting((t_lgting){computes.obj->m, world.light[i],
				computes.point, computes.eyev, computes.normalv,
				is_shadowed(world, computes.over_point, world.light[i])});
		color.tuple += tmp.tuple;
		i++;
	}
	return (color);
}

/**
 * @brief Wraps the precomputations and the shade hit function
 *
 * @param world
 * @param ray given ray wich will set pre computations
 * @return t_color
 */
t_color	color_at(t_scene world, t_ray ray)
{
	t_comps	computes;
	t_inter	hit_point;

	hit_point = find_hit(intersect_world(world, ray));
	if (!hit_point.def)
		return (set_col(0, 0, 0));
	computes = prepare_computations(hit_point, ray);
	return (shade_hit(world, computes));
}

/**
 * @brief Work in progress, rather a take on anti-aliasing,
 * very basic and naive approach, give out a blured scene
 *
 * @brief replaces color_at and takes care of the ray
 * @brief /!\ takes 9 times longer to render
 *
 * @param world
 * @param x
 * @param y
 * @param camera
 * @return t_color
 */
t_color	anti_alias(t_scene world, t_unt	x, t_unt y, t_cam camera)
{
	t_color	average[9];
	t_ray	r;
	t_unt	i;
	t_unt	j;
	float	d;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			r = ray_for_pixel(camera, x - 1 + i, y - 1 + j);
			average[i * 3 + j] = color_at(world, r);
			j++;
		}
		i++;
	}
	d = (1 - AA_RATIO) / 8;
	return (tup_col(average[0].tuple * d + average[1].tuple * d
			+ average[2].tuple * d + average[3].tuple * d
			+ average[4].tuple * d + average[5].tuple * AA_RATIO
			+ average[6].tuple * d + average[7].tuple * d
			+ average[8].tuple * d));
}
