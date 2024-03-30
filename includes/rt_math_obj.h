/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_obj.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:08:49 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/30 07:00:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_OBJ_H
# define RT_MATH_OBJ_H

# define INTER_MAX 50

typedef unsigned int		t_unt;
typedef unsigned char		t_uchar;
typedef float				t_tuple	__attribute__((ext_vector_type(4)));
typedef struct s_inter		t_inter;
typedef struct s_intrs		t_intrs;
typedef struct s_mater		t_mater;
typedef struct s_lgting		t_lgting;
typedef struct s_comps		t_comps;
typedef struct s_size		t_size;
typedef struct s_bound		t_bound;

typedef struct s_ray		t_ray;
typedef struct s_color		t_color;
typedef struct s_obj		t_obj;
typedef struct s_scene		t_scene;

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

struct s_mater
{
	t_color	col;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
};

struct s_comps
{
	float	t;
	t_obj	*obj;
	t_tuple	point;
	t_tuple	over_point;
	t_tuple	eyev;
	t_tuple	normalv;
	bool	inside;
};

/* Used for dynamic filling of elements */
struct s_size
{
	t_unt	max;
	t_unt	use;
};

struct s_bound
{
	bool	set;
	float	left;
	float	right;
};

#endif
