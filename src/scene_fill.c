/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:18:29 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 08:03:32 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_for_identifier(char *possible_id)
{
	if (ft_strncmp(possible_id, ID_AMB_LIGHT, 1))
		return (OBJ_AMB_LIGHT);
	else if (ft_strncmp(possible_id, ID_CAMERA, 1))
		return (OBJ_CAMERA);
	else if (ft_strncmp(possible_id, ID_CYLINDER, 2))
		return (OBJ_CYLINDER);
	else if (ft_strncmp(possible_id, ID_LIGHT, 1))
		return (OBJ_LIGHT);
	else if (ft_strncmp(possible_id, ID_PLANE, 2))
		return (OBJ_PLANE);
	else if (ft_strncmp(possible_id, ID_SPHERE, 2))
		return (OBJ_SPHERE);
	return (0);
}

bool	check_line(char *line, t_scene *scene)
{
	usigned int	idx;
	usigned int	identifier;

	idx = 0;
	while (line && line[idx] && ft_isispace(line[idx]))
		idx++;
	if (!line[idx])
		return (false);
	if (check_for_identifier(&line[idx]))
		return (false);
	return (true);
}

bool	scene_fill(t_scene *scene, int fd)
{
	char			*line;
	unsigned int	count;

	scene_init(scene);
	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (p_error(ERR_EMPTY), false);
	while (line)
	{
		count += (unsigned int)check_line(line, scene);
		line = get_next_line(fd);
	}
	return (true);
}
	// return (get_next_line(-1), false);
