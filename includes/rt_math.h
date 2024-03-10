/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:49:41 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 20:56:43 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

# define EPSILON 0.0001

typedef float			t_i2mtr[4];
typedef float			t_i3mtr[9];
typedef float			t_i4mtr[16];

typedef unsigned int	t_unt;
typedef unsigned char	t_uchar;
typedef struct s_pos	t_pos;
typedef uint32_t		t_hxcol;

typedef float			t_tuple	__attribute__((ext_vector_type(4)));
typedef float			t_2mtrx	__attribute__((matrix_type(2, 2)));
typedef float			t_3mtrx	__attribute__((matrix_type(3, 3)));
typedef float			t_4mtrx	__attribute__((matrix_type(4, 4)));

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

/* Matrix */
t_4mtrx	set_4mtrx(t_i4mtr a);
t_3mtrx	set_3mtrx(t_i3mtr a);
t_2mtrx	set_2mtrx(t_i2mtr a);
bool    matr_4_eq(t_4mtrx a, t_4mtrx b);

#endif
