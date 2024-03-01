/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:18:29 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/01 13:21:42 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	scene_fill(t_scene *scene, int fd)
{
	char			*line;
	unsigned int	count;
	unsigned int	tmp;

	if (!scene_init(scene))
		return (false);
	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (p_error(ERR_EMPTY), false);
	while (line)
	{
		tmp = parse_line(line, scene);
		free(line);
		if (!tmp)
			count++;
		else if (tmp > 1)
			return (get_next_line(-1), false);
		line = get_next_line(fd);
	}
	if (!count)
		return (p_error(ERR_EMPTY), false);
	return (true);
}
