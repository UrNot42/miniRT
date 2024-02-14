/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:32:28 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/12 10:36:39 by ulevallo         ###   ########.fr       */
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

# define O_SIZE_SET 10
# define O_SIZE_MAX 10000

enum e_objects
{
	OBJ_AMB_LIGHT = 1,
	OBJ_CAMERA,
	OBJ_LIGHT,
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
};

typedef struct s_pos		t_pos;
typedef struct s_size		t_size;
typedef struct s_color		t_color;
typedef struct s_light		t_light;
typedef struct s_src_light	t_src_light;
typedef struct s_amb_light	t_amb_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_camera		t_camera;
typedef struct s_scene		t_scene;

/* x, y, z coordinates */
struct s_pos
{
	double	x;
	double	y;
	double	z;
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

/* Ratio in [0.0 ; 1.0] range */
struct s_light
{
	double	ratio;
};

/* Object Light Source */
struct s_src_light
{
	t_pos	position;
	t_light	brgt;
	t_color	color;
};

struct s_sphere
{
	t_pos	position;
	double	diameter;
	t_color	color;
};

struct s_plane
{
	t_pos	point;
	t_pos	orientation;
	t_color	color;
};

struct s_cylinder
{
	t_pos	position;
	t_pos	orientation;
	double	diameter;
	double	height;
	t_color	color;
};

struct s_amb_light
{
	t_light	ratio;
	t_color	color;
	bool	defined;
};

struct s_camera
{
	t_pos			position;
	t_pos			orientation;
	unsigned char	fov;
	bool			defined;
};

struct s_scene
{
	t_camera	camera;
	t_amb_light	ambient_light;
	t_cylinder	*cylinder;
	t_size		cy_size;
	t_sphere	*sphere;
	t_size		sp_size;
	t_plane		*plane;
	t_size		pl_size;
	t_src_light	*light;
	t_size		l_size;
};

#endif
