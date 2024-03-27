/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:32:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/27 10:22:27 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJ_STRUCT_H
# define RT_OBJ_STRUCT_H

# define ID_AMB_LIGHT "A"
# define ID_CAMERA "C"
# define ID_LIGHT "L"
# define ID_SPHERE "sp"
# define ID_PLANE "pl"
# define ID_CYLINDER "cy"
# define ID_CUBE "cb"

# define O_SIZE_SET 2
# define O_SIZE_MAX 8096

typedef enum e_obj_kind		t_obj_kind;
typedef struct s_o_base		t_o_base;
typedef struct s_o_mtrx		t_o_mtrx;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_cube		t_cube;
typedef struct s_cam		t_cam;
typedef struct s_light		t_light;
typedef struct s_alght		t_alght;

enum e_obj_kind
{
	OBJ_UNDEF = 0,
	OBJ_AMB_LIGHT = 1,
	OBJ_CAMERA,
	OBJ_SRC_LIGHT,
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_CUBE
};

struct s_o_base
{
	t_mater		m;
	t_tuple		pos;
	bool		defined;
};

struct s_o_mtrx
{
	t_4mtrx		transform;
	t_4mtrx		inverse;
	t_4mtrx		trans_inv;
};

struct s_sphere
{
	union {
		t_color		color;
		struct {
			t_mater	m;
			t_tuple	pos;
			bool	def;
		};
		t_o_base	base;
	};
	union {
		struct {
			t_4mtrx		transform;
			t_4mtrx		inverse;
			t_4mtrx		trans_inv;
		};
		t_o_mtrx	mtx;
	};
	float		diameter;
};

struct s_plane
{
	union {
		t_color		color;
		struct {
			t_mater	m;
			t_tuple	pos;
			bool	def;
		};
		t_o_base	base;
	};
	union {
		struct {
			t_4mtrx		transform;
			t_4mtrx		inverse;
			t_4mtrx		trans_inv;
		};
		t_o_mtrx	mtx;
	};
	t_tuple		normal;
};

struct s_cylinder
{
	union {
		t_color		color;
		struct {
			t_mater	m;
			t_tuple	pos;
			bool	def;
		};
		t_o_base	base;
	};
	union {
		struct {
			t_4mtrx		transform;
			t_4mtrx		inverse;
			t_4mtrx		trans_inv;
		};
		t_o_mtrx	mtx;
	};
	t_tuple			normal;
	float			width;
	float			height;
	float			minimum;
	float			maximum;
	bool			min_caped;
	bool			max_caped;
};

struct s_cube
{
	union {
		t_color		color;
		struct {
			t_mater	m;
			t_tuple	pos;
			bool	def;
		};
		t_o_base	base;
	};
	union {
		struct {
			t_4mtrx		transform;
			t_4mtrx		inverse;
			t_4mtrx		trans_inv;
		};
		t_o_mtrx	mtx;
	};
	t_tuple			normal;
};

struct s_light
{
	union {
		t_color		color;
		struct {
			t_mater	m;
			t_tuple	pos;
			bool	def;
		};
		t_o_base	base;
	};
	float	ratio;
};

struct s_alght
{
	union {
		t_color		color;
		struct {
			t_mater	m;
			t_tuple	pos;
			bool	def;
		};
		t_o_base	base;
	};
	float	ratio;
};

struct s_cam
{
	union {
		t_color		color;
		struct {
			t_mater	m;
			t_tuple	pos;
			bool	def;
		};
		t_o_base	base;
	};
	union {
		struct {
			t_4mtrx		transform;
			t_4mtrx		inverse;
			t_4mtrx		trans_inv;
		};
		t_o_mtrx	mtx;
	};
	t_tuple		normal;
	t_unt		hz_size;
	t_unt		v_size;
	float		pxl_size;
	float		half_width;
	float		half_height;
	float		fov;
};

struct s_obj
{
	t_obj_kind			kind;
	union {
		t_sphere		sphere;
		t_plane			plane;
		t_cylinder		cylinder;
		t_cube			cube;
		t_light			light;
		t_alght			alght;
		t_cam			camera;
		struct {
			t_mater		m;
			t_tuple		pos;
			bool		defined;
		};
		t_o_base		base;
		t_color			color;
	};
};

struct s_scene
{
	t_obj	camera;
	t_obj	ambient_light;
	t_obj	*objects;
	t_size	obj_size;
	t_obj	*light;
	t_size	li_size;
};

#endif
