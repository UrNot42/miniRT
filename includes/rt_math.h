/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:49:41 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/20 19:18:42 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

# define EPSILON 0.0001
# define M_PI 3.14159265358979323846

typedef float			t_i2mtr[4];
typedef float			t_i3mtr[9];
typedef float			t_i4mtr[16];
typedef float			t_shear[6];

typedef unsigned int	t_unt;
typedef unsigned char	t_uchar;
typedef uint32_t		t_hxcol;

typedef float			t_tuple	__attribute__((ext_vector_type(4)));
typedef float			t_2mtrx	__attribute__((matrix_type(2, 2)));
typedef float			t_3mtrx	__attribute__((matrix_type(3, 3)));
typedef float			t_4mtrx	__attribute__((matrix_type(4, 4)));
typedef float			t_tpmtx	__attribute__((matrix_type(4, 1)));

/* ================= Basic Objet =================*/

/* float */
float	my_fabs(float a);
bool	f_eq(float a, float b);

/* Tuples */
t_tuple	set_tuple(float x, float y, float z, float w);
t_tuple	set_point(float x, float y, float z);
t_tuple	set_vec(float x, float y, float z);
t_color	set_col(float r, float g, float b);
bool	is_point(t_tuple a);
bool	is_vec(t_tuple a);
bool	is_same_tuple(t_tuple a, t_tuple b);
bool	is_same_col(t_color a, t_color b);
bool	is_same_mat(t_mater a, t_mater b);
t_tuple	origin(void);

/* Vectors */
float	vec_magn(t_tuple vec);
t_tuple	vec_norm(t_tuple vec);
float	vec_dot(t_tuple a, t_tuple b);
t_tuple	vec_cross(t_tuple a, t_tuple b);

/* Colors */
t_color	hadamard_product(t_color c1, t_color c2);
float	uchar_to_float(t_uchar color);
t_uchar	float_to_uchar(float color);
t_hxcol	t_color_to_hex(t_color color);
t_color	tup_col(t_tuple a);

/*============== Matrix ==============*/
// Initialisation
t_4mtrx	set_4mtrx(t_i4mtr a);
t_3mtrx	set_3mtrx(t_i3mtr a);
t_2mtrx	set_2mtrx(t_i2mtr a);

// Comparison
bool	matr_2_eq(t_2mtrx a, t_2mtrx b);
bool	matr_3_eq(t_3mtrx *a, t_3mtrx *b);
bool	matr_4_eq(t_4mtrx a, t_4mtrx b);

// Conversion
t_tpmtx	vec2mtrx(t_tuple a);
t_tuple	mtrx2vec(t_tpmtx a);
t_tuple	tup_mtrx(t_4mtrx a, t_tuple b);
t_4mtrx	get_id4mtrx(void);
t_4mtrx	transpose(t_4mtrx a);
t_2mtrx	sub_3mtrx(t_3mtrx a, t_unt x, t_unt y);
t_3mtrx	sub_4mtrx(t_4mtrx a, t_unt x, t_unt y);
t_4mtrx	inverse_4mtrx(t_4mtrx a);

// Operations
float	det_2mtrx(t_2mtrx a);
float	det_3mtrx(t_3mtrx a);
float	det_4mtrx(t_4mtrx a);
float	minor_3mtrx(t_3mtrx a, t_unt i, t_unt j);
float	minor_4mtrx(t_4mtrx a, t_unt i, t_unt j);
float	cofactor_3mtrx(t_3mtrx a, t_unt i, t_unt j);
float	cofactor_4mtrx(t_4mtrx a, t_unt i, t_unt j);

// Transform
t_4mtrx	translation_mtrx(float x, float y, float z);
t_4mtrx	scale_mtrx(float x, float y, float z);
t_4mtrx	shearing(t_shear rel);
t_4mtrx	rotation_x(float r);
t_4mtrx	rotation_y(float r);
t_4mtrx	rotation_z(float r);
t_4mtrx	view_transform(t_tuple from, t_tuple to, t_tuple up);

/* ================ Objects ================*/
bool	add_light(t_scene	*world, t_obj light);
bool	add_obj(t_scene	*world, t_obj obj);
t_scene	default_world(void);
t_obj	sphere(void);
t_obj	point_light(t_tuple pos, t_color intensity);
t_mater	material(void);

/* ============== Rays ================*/
// Initialising
t_ray	ray(t_tuple origin, t_tuple direction);
t_tuple	ray_pos(t_ray beam, float time);
t_ray	ray_transform(t_ray r, t_4mtrx m);
void	set_transform(t_obj *o, t_4mtrx m);
t_color	lighting(t_mater m, t_obj o, t_tuple p, t_ray v);
t_color	shade_hit(t_scene world, t_comps computes);
t_color	color_at(t_scene world, t_ray ray);

// Intersections
t_intrs	intersect(t_obj *sphere, t_ray ray);
t_inter	get_inter(float time, t_obj *obj);
t_intrs	intersections(t_unt count, t_inter inters[INTER_MAX]);
t_inter	find_hit(t_intrs inters);
bool	is_same_inter(t_inter a, t_inter b);
t_tuple	normal_at(t_obj o, t_tuple point);
t_tuple	reflect(t_tuple v, t_tuple reflex);
t_intrs	intersect_world(t_scene	world, t_ray r);
void	quicksort(t_intrs *array, int low, int high);
t_comps	prepare_computations(t_inter i, t_ray ray);

#endif
