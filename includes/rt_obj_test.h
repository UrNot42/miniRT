/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:02:24 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/26 13:16:43 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJ_TEST_H
# define RT_OBJ_TEST_H

// WIP

typedef enum e_o_kind	t_o_kind;

enum e_o_kind
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

typedef struct s_o_base
{
	t_tuple		pos;
	t_color		color;
}	t_o_base;

typedef struct s_object
{
	t_o_kind			kind;
	union {
		t_sphere		sphere;
		t_cube			cube;
		t_cylinder		cylinder;
		struct {
			t_tuple		pos;
			t_color		color;
		};
		t_o_base		base;
	};
}	t_object;

typedef struct s_sphere
{
	union {
		struct {
			t_tuple	pos;
			t_color	color;
		};
		t_o_base	base;
	};
	float	diameter;
};

typedef struct s_cube
{
	union {
		struct {
			t_tuple	pos;
			t_color	color;
		};
		t_o_base	base;
	};
	t_unt	o;
};

#endif
