/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj_method.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:38:04 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/27 11:12:56 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJ_METHOD_H
# define RT_OBJ_METHOD_H

/* ================ Objects ================*/
// General
t_intrs		intersect(t_obj *object, t_ray ray);
t_tuple		normal_at(t_obj object, t_tuple point);

// Sphere
t_sphere	sphere(void);
t_obj		o_sphere(void);
t_intrs		sp_intersect(t_obj *sphere, t_ray ray);
t_tuple		sp_normal_at(t_sphere sphere, t_tuple point);

// Plane
t_plane		plane(void);
t_obj		o_plane(void);
t_intrs		pl_intersect(t_obj *plane, t_ray r);
t_tuple		pl_normal_at(t_plane plane, t_tuple point);

// Cylinder
t_cylinder	cylinder(void);
t_obj		o_cylinder(void);
t_intrs		cy_intersect(t_obj *cylinder, t_ray r);
t_tuple		cy_normal_at(t_cylinder cy, t_tuple point);

// Cube
t_cube		cube(void);
t_obj		o_cube(void);
t_intrs		cube_intersect(t_obj *cube, t_ray r);
t_tuple		cube_normal_at(t_cube cube, t_tuple point);

// Camera
t_cam		camera(t_unt hsize, t_unt vsize, float field_of_view);
t_obj		o_camera(t_unt hsize, t_unt vsize, float field_of_view);
t_4mtrx		view_transform(t_tuple from, t_tuple to, t_tuple up);

// Light
t_light		light(t_tuple pos, t_color intensity);
t_obj		o_light(t_tuple pos, t_color intensity);
void		regularize_light(t_scene *world);

#endif
