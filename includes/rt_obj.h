/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:32:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/07 12:08:38 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJ_H
# define RT_OBJ_H

# include "rt_math.h"

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

typedef struct s_pos		t_pos;
typedef struct s_size		t_size;
typedef struct s_color		t_color;
typedef struct s_bound		t_bound;
typedef struct s_obj		t_obj;
typedef struct s_scene		t_scene;

/* x, y, z coordinates */
struct s_pos
{
	float	x;
	float	y;
	float	z;
};

/* use for dynamic filling of elements */
struct s_size
{
	unsigned int	max;
	unsigned int	use;
};

/* RGB values in [0 ; 255] range */
struct s_color
{
	unsigned char	red;
	unsigned char	grn;
	unsigned char	blu;
};

struct s_bound
{
	bool	set;
	float	left;
	float	right;
};

struct s_obj
{
	unsigned int	type;
	t_pos			pos;
	t_pos			norm;
	float			ratio;
	float			diameter;
	float			height;
	unsigned char	fov;
	t_color			col;
	t_size			*size;
	bool			defined;
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

#endif
