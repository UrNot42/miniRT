/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:49:41 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/25 20:05:03 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

# define EPSILON 0.0035
# define AA_RATIO 0.2
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
void	fswap(float *a, float *b);

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

#endif
