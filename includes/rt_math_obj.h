/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_obj.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:08:49 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/12 11:17:19 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_OBJ_H
# define RT_MATH_OBJ_H

typedef unsigned int		t_unt;
typedef unsigned char		t_uchar;
typedef float				t_tuple	__attribute__((ext_vector_type(4)));
typedef struct s_inter		t_inter;
typedef struct s_hit		t_hit;

typedef struct s_ray		t_ray;
typedef struct s_color		t_color;

/* RGB values in [0 ; 255] range */
/*struct s_color
{
	t_tuple	tuple;
	float	*r;
	float	*g;
	float	*b;
};*/
// TODO MAYBE USE PRIOR CODE IMPLEMENTATION ????????
struct s_color
{
	union {
		struct {
			float	red;
			float	green;
			float	blue;
		};
		t_tuple	tuple;
	};
};

struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
};

struct s_hit
{
	float	t[2];
	t_unt	count;
};

struct s_inter
{
	t_obj	*obj;
	float	t;
}

#endif
