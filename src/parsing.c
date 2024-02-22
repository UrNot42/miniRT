/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:54:53 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/19 14:46:33 by ulevallo         ###   ########.fr       */
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
		return ((*pos)++, OBJ_SRC_LIGHT);
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

t_obj	*get_obj(t_scene *scene, char id)
{
	if (id == OBJ_CYLINDER && scene->cy_size.use)
		return (&scene->cylinder[scene->cy_size.use]);
	else if (id == OBJ_SPHERE && scene->sp_size.use)
		return (&scene->sphere[scene->sp_size.use]);
	else if (id == OBJ_PLANE && scene->pl_size.use)
		return (&scene->plane[scene->pl_size.use]);
	else if (id == OBJ_SRC_LIGHT
		&& sz_new_elemmt(&scene->light[scene->l_size.use], &scene->l_size))
		return (true);
	return (false);

(t_light *)((int)(&scene->ambient_light.ratio) * (id == OBJ_AMB_LIGHT)
				+ (int)(&scene->light[scene->l_size.use].brgt.ratio) * (id == OBJ_SRC_LIGHT))

	set_cylinder(&scene->cylinder[scene->cy_size.use], line, pos);
	set_sphere(&scene->sphere[scene->sp_size.use], line, pos);
	set_fov(&scene->camera, line, pos);
}

bool	parse_object(t_obj *object, unsigned int id, char *line,
	unsigned int *pos)
{
	ft_skip_spaces(line, pos);
	if (!line[*pos])
		return (true);
	if (id != OBJ_CAMERA && id != OBJ_AMB_LIGHT
		&& add_scene_obj(id, object, object->size))
		return (true);
	if (id != OBJ_AMB_LIGHT && set_pos(&object->pos, line, pos))
		return (true);
	if (id != OBJ_AMB_LIGHT && id != OBJ_SRC_LIGHT && id != OBJ_SPHERE
		&& set_pos(&object->norm, line, pos))
		return (true);
	if ((id == OBJ_AMB_LIGHT || id == OBJ_SRC_LIGHT)
		&& set_db_wbound(&object->ratio, (t_bound){true, 0, 1}, line, pos))
		return (true);
	if (id == OBJ_CYLINDER
		&& set_db_wbound(&object->diameter, (t_bound){false, 0, 0}, line, pos)
		&& set_db_wbound(&object->height, (t_bound){false, 0, 0}, line, pos))
		return (true);
	if (id == OBJ_SPHERE
		&& set_db_wbound(&object->diameter, (t_bound){false, 0, 0}, line, pos))
		return (true);
	if (id == OBJ_CAMERA
		&& set_int_wbound((int *)&object->fov,
			(t_bound){0, 0, false}, line, pos))
		return (true);
	if (id != OBJ_CAMERA)
		set_color(&object->col, line, pos);
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
	printf("%c\n", identifier);
	if (!identifier)
		return (p_error(ERR_IDENTIFIER), 2);
	else if (parse_object(get_obj(scene, identifier),
			identifier, line, &pos))
		return (3);
	return (false);
}
