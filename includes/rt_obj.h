/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:32:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/11 18:56:57 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJ_H
# define RT_OBJ_H

# define ID_AMB_LIGHT "A"
# define ID_CAMERA "C"
# define ID_LIGHT "L"
# define ID_SPHERE "sp"
# define ID_PLANE "pl"
# define ID_CYLINDER "cy"

# define O_SIZE_SET 2
# define O_SIZE_MAX 8096

enum e_objects
{
	OBJ_UNDEF = 0,
	OBJ_AMB_LIGHT = 1,
	OBJ_CAMERA,
	OBJ_SRC_LIGHT,
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
};

typedef unsigned int		t_unt;
typedef unsigned char		t_uchar;
typedef float				t_tuple	__attribute__((ext_vector_type(4)));

typedef struct s_size		t_size;
typedef struct s_color		t_color;
typedef struct s_bound		t_bound;
typedef struct s_obj		t_obj;
typedef struct s_scene		t_scene;

/* use for dynamic filling of elements */
struct s_size
{
	t_unt	max;
	t_unt	use;
};

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

struct s_bound
{
	bool	set;
	float	left;
	float	right;
};

struct s_obj
{
	t_unt		type;
	t_tuple		pos;
	t_tuple		norm;
	float		ratio;
	float		diameter;
	float		height;
	t_uchar		fov;
	t_color		col;
	t_size		*size;
	bool		defined;
};

struct s_scene
{
	t_obj		camera;
	t_obj		ambient_light;
	t_obj		*cylinder;
	t_size		cy_size;
	t_obj		*sphere;
	t_size		sp_size;
	t_obj		*plane;
	t_size		pl_size;
	t_obj		*light;
	t_size		l_size;
};

t_obj	*sphere(void);

#endif
