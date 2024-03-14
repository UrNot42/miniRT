/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:54:53 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:32 by ulevallo         ###   ########.fr       */
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
	return (p_error(ERR_IDENTIFIER), OBJ_UNDEF);
}

t_obj	*get_obj(t_scene *scene, char id)
{
	if ((id == OBJ_CYLINDER || id == OBJ_SPHERE || id == OBJ_PLANE
			|| id == OBJ_SRC_LIGHT) && scene->obj_size.use)
		return (&scene->objects[scene->obj_size.use - 1]);
	else if (id == OBJ_CAMERA)
		return (&scene->camera);
	else if (id == OBJ_AMB_LIGHT)
		return (&scene->ambient_light);
	else if (id == OBJ_UNDEF)
		return (NULL);
	return (NULL);
}

/*
Object use of elements and formats:
C	Pos{-5,0,0}			Norm[1,0,0]									FOV 70
A									Ratio[0.2]					Col(255,255,255)
L	Pos{-2,0,-7}					Ratio[0.7]					Col(255,255,255)
sp	Pos{0,-0.9,-2}								Diam(0.2)		Col( 87, 42,  5)
pl	Pos{0,-1,0}			Norm[0,0,1]								Col(110, 37,152)
cy	Pos{0,1.25,-1.1}	Norm[0,1,0.4]			W(1.75) H(0.2)	Col(142, 36, 45)
*/
bool	parse_object(t_obj *object, t_unt id, char *line,
	t_unt *pos)
{
	if (!line[*pos])
		return (p_error(ERR_LINE), true);
	if (id != OBJ_AMB_LIGHT && parse_pos(&object->pos, line, pos))
		return (p_error(ERR_POS), true);
	if (id != OBJ_AMB_LIGHT && id != OBJ_SRC_LIGHT && id != OBJ_SPHERE
		&& parse_pos(&object->norm, line, pos))
		return (p_error(ERR_NORM), true);
	if ((id == OBJ_AMB_LIGHT || id == OBJ_SRC_LIGHT)
		&& set_f_wbound(&object->ratio, (t_bound){true, 0, 1}, line, pos))
		return (p_error(ERR_RATIO), true);
	if ((id == OBJ_SPHERE || id == OBJ_CYLINDER)
		&& set_float(&object->diameter, line, pos))
		return (p_error(ERR_DIAMETER), true);
	if (id == OBJ_CYLINDER
		&& set_float(&object->height, line, pos))
		return (p_error(ERR_HEIGHT), true);
	if (id == OBJ_CAMERA
		&& set_int((int *)&object->fov, line, pos))
		return (p_error(ERR_FOV), true);
	if (id != OBJ_CAMERA && parse_color(&object->col, line, pos))
		return (p_error(ERR_COLOR), true);
	object->type = id;
	return (false);
}

t_unt	parse_line(char *line, t_scene *scene)
{
	t_unt	pos;
	t_unt	identifier;

	pos = 0;
	ft_skip_spaces(line, &pos);
	if (!line[pos])
		return (1);
	identifier = check_for_identifier(&line[pos], &pos);
	if (!identifier)
		return (p_error(ERR_IDENTIFIER), 2);
	if (parse_obj(scene, identifier))
		return (4);
	if (parse_object(get_obj(scene, identifier), identifier, line, &pos))
		return (3);
	return (false);
}
