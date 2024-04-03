/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:54:53 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 13:50:56 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	check_for_identifier(char *possible_id, t_unt *pos)
{
	if (!ft_strncmp(possible_id, ID_AMB_LIGHT, 1))
		return ((*pos)++, OBJ_AMB_LIGHT);
	else if (!ft_strncmp(possible_id, ID_CAMERA, 1))
		return ((*pos)++, OBJ_CAMERA);
	else if (!ft_strncmp(possible_id, ID_LIGHT, 1))
		return ((*pos)++, OBJ_SRC_LIGHT);
	else if (!ft_strncmp(possible_id, ID_CYLINDER, 2))
		return ((*pos)++, (*pos)++, OBJ_CYLINDER);
	else if (!ft_strncmp(possible_id, ID_PLANE, 2))
		return ((*pos)++, (*pos)++, OBJ_PLANE);
	else if (!ft_strncmp(possible_id, ID_SPHERE, 2))
		return ((*pos)++, (*pos)++, OBJ_SPHERE);
	else if (!ft_strncmp(possible_id, ID_CONE, 2))
		return ((*pos)++, (*pos)++, OBJ_CONE);
	else if (!ft_strncmp(possible_id, ID_CUBE, 2))
		return ((*pos)++, (*pos)++, OBJ_CUBE);
	return (p_error(ERR_IDENTIFIER), OBJ_UNDEF);
}

t_obj	*get_obj(t_scene *scene, char id)
{
	if ((id == OBJ_CYLINDER || id == OBJ_SPHERE || id == OBJ_PLANE
			|| id == OBJ_CUBE || id == OBJ_CONE))
	{
		add_obj(scene, o_get(id));
		return (&scene->objects[scene->obj_size.use - 1]);
	}
	else if (id == OBJ_CAMERA)
		return (scene->camera.defined = true, &scene->camera);
	else if (id == OBJ_SRC_LIGHT)
	{
		add_light(scene, o_light(origin(), set_col(0, 0, 0)));
		return (&scene->light[scene->li_size.use - 1]);
	}
	else if (id == OBJ_AMB_LIGHT)
		return (scene->ambient_light.defined = true, &scene->ambient_light);
	return (NULL);
}

/*
Object use of elements and formats:
C	Pos{-5,0,0}			Norm[1,0,0]					FOV 70
A									Ratio[0.2]					Col(255,255,255)
L	Pos{-2,0,-7}					Ratio[0.7]					Col(255,255,255)
sp	Pos{0,-0.9,-2}									Diam(0.2)	Col( 87, 42,  5)
pl	Pos{0,-1,0}			Norm[0,0,1]								Col(110, 37,152)
cy	Pos{0,1.25,-1.1}	Norm[0,1,0.4]			W(1.75) H(0.2)	Col(142, 36, 45)
co	Pos{0,1.25,-1.1}	Norm[0,1,0.4]			W(1.75) H(0.2)	Col(142, 36, 45)
	D---				D---					ND+++			D---
cb	Pos{0,1.25,-1.1}	Norm[0,1,0.4]			size {x y z}	Col(142, 36, 45) // TODO ??
	D---				D---					ND+++			D---
*/

bool	parse_obj_details(t_obj *obj, char *line, t_unt *pos)
{
	if ((obj->kind == OBJ_AMB_LIGHT || obj->kind == OBJ_SRC_LIGHT)
		&& set_f_wbound(&obj->light.ratio, (t_bound){true, 0, 1}, line, pos))
		return (p_error(ERR_RATIO), true);
	if (obj->kind == OBJ_SPHERE && (set_float(&obj->sphere.diameter, line, pos)
			|| obj->sphere.diameter <= 0))
		return (p_error(ERR_DIAMETER), true);
	if ((obj->kind == OBJ_CYLINDER || obj->kind == OBJ_CONE)
		&& (set_float(&obj->cylinder.width, line, pos)
			|| set_float(&obj->cylinder.height, line, pos)))
		return (p_error(ERR_HEIGHT), true);
	if (obj->kind == OBJ_CAMERA && set_float(&obj->camera.fov, line, pos))
		return (p_error(ERR_FOV), true);
	if (obj->kind == OBJ_CUBE && parse_pos(&obj->cube.size, line, pos))
		return (p_error(ERR_SIZE), true);
	return (false);
}

bool	parse_object(t_obj *obj, char *line, t_unt *pos)
{
	if (!line[*pos])
		return (p_error(ERR_LINE), true);
	if (obj->kind != OBJ_AMB_LIGHT && parse_pos(&obj->pos, line, pos))
		return (p_error(ERR_POS), true);
	if (obj->kind != OBJ_AMB_LIGHT && obj->kind != OBJ_SRC_LIGHT
		&& obj->kind != OBJ_SPHERE && parse_pos(&obj->plane.normal, line, pos))
		return (p_error(ERR_NORM), true);
	if (parse_obj_details(obj, line, pos))
		return (true);
	if (obj->kind != OBJ_CAMERA && parse_color(&obj->color, line, pos))
		return (p_error(ERR_COLOR), true);
	if (line[*pos] != '\n' && line[*pos] != '\0')
		return (p_error(ERR_LINE), true);
	return (false);
}

t_unt	parse_line(char *line, t_scene *scene)
{
	t_unt		pos;
	t_obj_kind	identifier;
	t_obj		*tmp;

	pos = 0;
	ft_skip_spaces(line, &pos);
	if (!line[pos])
		return (1);
	identifier = check_for_identifier(&line[pos], &pos);
	if (!identifier)
		return (2);
	tmp = get_obj(scene, identifier);
	tmp->kind = identifier;
	if (parse_object(tmp, line, &pos))
		return (3);
	return (false);
}
