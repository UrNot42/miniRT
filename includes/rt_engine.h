/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:21:57 by marvin            #+#    #+#             */
/*   Updated: 2024/03/23 11:21:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ENGINE_H
# define RT_ENGINE_H

struct s_lgting
{
	t_mater	mater;
	t_obj	light;
	t_tuple	point;
	t_tuple	eyev;
	t_tuple	normalv;
	bool	in_shadow;
};

/* ================ Objects ================*/
// World
t_scene	default_world(void);
bool	add_light(t_scene	*world, t_obj light);
bool	add_obj(t_scene	*world, t_obj obj);
t_mater	material(void);

t_tuple	normal_at(t_obj object, t_tuple point);
t_intrs	intersect(t_obj *sphere, t_ray ray);

// Sphere
t_obj	sphere(void);
t_tuple	sp_normal_at(t_obj o, t_tuple point);
t_intrs	sp_intersect(t_obj *sphere, t_ray ray);

// Plane
t_obj	plane(void);
t_intrs pl_intersect(t_obj *plane, t_ray r);
t_tuple	pl_normal_at(t_obj plane, t_tuple point);

// Cylinder
t_obj	cylinder(void);
t_tuple	cy_normal_at(t_obj cy, t_tuple point);
t_intrs cy_intersect(t_obj *cylinder, t_ray r);

// Light
t_obj	point_light(t_tuple pos, t_color intensity);

// Cube
t_obj	cube(void);
t_tuple	cube_normal_at(t_obj cy, t_tuple point);
t_intrs cube_intersect(t_obj *cube, t_ray r);

/* ============== Rays ================*/
// Initialising
t_color	lighting(t_lgting l);
bool	is_shadowed(t_scene world, t_tuple point);
t_ray	ray(t_tuple origin, t_tuple direction);
t_tuple	ray_pos(t_ray beam, float time);
t_ray	ray_transform(t_ray r, t_4mtrx m);
void	set_transform(t_obj *o, t_4mtrx m);
t_color	shade_hit(t_scene world, t_comps computes);
t_color	color_at(t_scene world, t_ray ray);
t_color	anti_alias(t_scene world, t_unt	x, t_unt y, t_cam camera);

// Intersections
t_inter	get_inter(float time, t_obj *obj);
t_intrs	intersections(t_unt count, t_inter inters[INTER_MAX]);
t_inter	find_hit(t_intrs inters);
bool	is_same_inter(t_inter a, t_inter b);
t_tuple	reflect(t_tuple v, t_tuple reflex);
t_intrs	intersect_world(t_scene	world, t_ray r);
void	quicksort(t_intrs *array, int low, int high);
t_comps	prepare_computations(t_inter i, t_ray ray);

#endif
