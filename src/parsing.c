/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:54:53 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 14:56:37 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_for_identifier(char *possible_id, unsigned int *pos)
{
	if (ft_strncmp(possible_id, ID_AMB_LIGHT, 1))
		return ((*pos)++, OBJ_AMB_LIGHT);
	else if (ft_strncmp(possible_id, ID_CAMERA, 1))
		return ((*pos)++, OBJ_CAMERA);
	else if (ft_strncmp(possible_id, ID_LIGHT, 1))
		return ((*pos)++, OBJ_LIGHT);
	else if (ft_strncmp(possible_id, ID_CYLINDER, 2))
		return ((*pos)++, (*pos)++, OBJ_CYLINDER);
	else if (ft_strncmp(possible_id, ID_PLANE, 2))
		return ((*pos)++, (*pos)++, OBJ_PLANE);
	else if (ft_strncmp(possible_id, ID_SPHERE, 2))
		return ((*pos)++, (*pos)++, OBJ_SPHERE);
	return (0);
}

/*
C	Pos{-5,0,0} 		Norm[1,0,0]						FOV 70
A									Ratio[0.2]					Col(255,255,255)
L	Pos{-2,0,-7}					Ratio[0.7]					Col(255,255,255)
sp	Pos{0,-0.9,-2}								Diam(0.2)		Col( 87, 42,  5)
pl	Pos{0,-1,0}			Norm[0,0,1]								Col(110, 37,152)
cy	Pos{0,1.25,-1.1}	Norm[0,1,0.4]			W(1.75) H(0.2)	Col(142, 36, 45)
*/

bool	parse_identifier(t_scene *scene, unsigned int id, char *line,
	unsigned int *pos)
{
	ft_skip_spaces(line, pos);
	if (!line[*pos])
		return (true);
	if (id != OBJ_CAMERA && id != OBJ_AMB_LIGHT && add_scene_obj(scene, id))
		return (true);
	if (id != OBJ_AMB_LIGHT && set_pos(get_pos(scene, id), line, pos))
		return (true);
	if (id != OBJ_AMB_LIGHT && id != OBJ_LIGHT && id != OBJ_SPHERE
		&& set_pos(get_norm(scene, id), line, pos))
		return (true);
	if (id == OBJ_AMB_LIGHT || id == OBJ_LIGHT)
		set_ratio(NULL, line, pos); // TODO
	if (id == OBJ_CYLINDER)
		set_cylinder(NULL, line, pos); // TODO
	if (id == OBJ_SPHERE)
		set_sphere(NULL, line, pos); // TODO
	if (id == OBJ_CAMERA)
		set_fov(NULL, line, pos); // TODO
	if (id != OBJ_CAMERA)
		set_color(get_color(scene, id), line, pos); // TODO
	return (false);
}

unsigned int	parse_line(char *line, t_scene *scene)
{
	unsigned int	pos;
	unsigned int	identifier;

	pos = 0;
	ft_skip_spaces(line, &pos);
	if (!line[pos])
		return (1);
	identifier = check_for_identifier(&line[pos], &pos);
	if (!identifier)
		return (p_error(ERR_IDENTIFIER), 2);
	else if (parse_identifier(scene, identifier, line, &pos))
		return (3);
	return (false);
}
