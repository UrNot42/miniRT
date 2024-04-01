/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:34:03 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/01 18:56:50 by marvin           ###   ########.fr       */
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
t_color	a_lighting(t_lgting l)
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

// l.material, light, point, eyev, normalv
t_color	lighting(t_lgting l)
{
	t_color	effective_color;
	t_tuple	lightv;
	t_tuple	reflectv;
	float	reflect_dot_eye;
	float	light_dot_normal;
	float	factor;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;

		// combine the surface color with the light's color/intensity
	effective_color.tuple = l.mater.col.tuple * l.light.color.tuple;
		// find the direction to the light source
		// compute the ambient contribution
	ambient.tuple = effective_color.tuple * l.mater.ambient;
	if (l.in_shadow)
		return (tup_col(ambient.tuple));
	lightv = vec_norm(l.light.pos - l.point);
		// light_dot_normal represents the cosine of the angle between the
		// light vector and the normal vector. A negative number means the
		// light is on the other side of the surface.
	light_dot_normal = vec_dot(lightv, l.normalv);
	if (light_dot_normal >= 0)
	{

			// compute the diffuse contribution
		diffuse.tuple = effective_color.tuple * l.mater.diffuse * light_dot_normal;
			// reflect_dot_eye represents the cosine of the angle between the
			// reflection vector and the eye vector. A negative number means the
			// light reflects away from the eye.
		reflectv = reflect(-lightv, l.normalv);
		reflect_dot_eye = vec_dot(reflectv, l.eyev);
		if (reflect_dot_eye > 0)
		{
				// compute the specular contribution
			factor = pow(reflect_dot_eye, l.mater.shininess);
			specular.tuple = l.light.color.tuple * l.mater.specular * factor;
 		}
		else
			specular = set_col(0, 0, 0);
	}
	else
	{
		diffuse = set_col(0, 0, 0);
 		specular = set_col(0, 0, 0);
	}
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

	color = world.ambient_light.alght.color;
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
	return (tup_col(color.tuple + world.ambient_light.color.tuple));
}

