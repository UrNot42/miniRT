/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:18:29 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/07 12:18:10 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	scene_fill(t_scene *scene, int fd)
{
	char			*line;
	t_unt	count;
	t_unt	tmp;

	if (!scene_init(scene))
		return (true);
	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (p_error(ERR_EMPTY), true);
	while (line)
	{
		tmp = parse_line(line, scene);
		free(line);
		if (!tmp)
			count++;
		else if (tmp > 1)
			return (get_next_line(-1), true);
		line = get_next_line(fd);
	}
	if (!count)
		return (p_error(ERR_EMPTY), true);
	return (false);
}
