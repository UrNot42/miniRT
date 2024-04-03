/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:34:03 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 12:01:39 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	light_specular(t_lgting l, t_tuple lightv)
{
	t_color	specular;
	t_tuple	reflectv;
	float	reflect_dot_eye;

	reflectv = reflect(-lightv, l.normalv);
		reflect_dot_eye = vec_dot(reflectv, l.eyev);
	if (reflect_dot_eye > 0)
	{
		specular.tuple = l.light.color.tuple
			* l.mater.specular
			* powf(reflect_dot_eye, l.mater.shininess);
	}
	else
		specular = set_col(0, 0, 0);
	return (specular);
}

static t_color	light_diffuse(t_lgting l, t_color effective_color)
{
	t_color	total;
	t_color	diffuse;
	t_tuple	lightv;
	float	light_dot_normal;

	lightv = vec_norm(l.light.pos - l.point);
	light_dot_normal = vec_dot(lightv, l.normalv);
	if (light_dot_normal >= 0)
	{
		diffuse.tuple = effective_color.tuple
			* l.mater.diffuse
			* light_dot_normal;
	}
	else
	{
		diffuse = set_col(0, 0, 0);
	}
	total = light_specular(l, lightv);
	total.tuple += diffuse.tuple;
	return (total);
}

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
	t_color	total;
	t_color	ambient;
	t_color	effective_color;

	effective_color.tuple = l.mater.col.tuple
		* l.light.color.tuple * l.light.light.ratio;
	ambient.tuple = effective_color.tuple * l.ambient;
	if (l.in_shadow)
		return (ambient);
	total = light_diffuse(l, effective_color);
	total.tuple += ambient.tuple;
	return (total);
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
				world.ambient_light.color.tuple
				* world.ambient_light.alght.ratio,
				computes.point, computes.eyev,
				computes.normalv,
				is_shadowed(world, computes.over_point, world.light[i])});
		color.tuple += tmp.tuple;
		i++;
	}
	return (color);
}
