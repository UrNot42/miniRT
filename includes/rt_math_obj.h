/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_obj.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:08:49 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/12 17:49:33 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_OBJ_H
# define RT_MATH_OBJ_H

# define INTER_MAX 10

typedef unsigned int		t_unt;
typedef unsigned char		t_uchar;
typedef float				t_tuple	__attribute__((ext_vector_type(4)));
typedef struct s_inter		t_inter;
typedef struct s_intrs		t_intrs;

typedef struct s_ray		t_ray;
typedef struct s_color		t_color;
typedef struct s_size		t_size;
typedef struct s_bound		t_bound;
typedef struct s_obj		t_obj;
typedef struct s_scene		t_scene;

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

struct s_inter
{
	float	t;
	t_obj	*obj;
	bool	def;
};

struct s_intrs
{
	t_inter	i[INTER_MAX];
	t_unt	count;
};

#endif
