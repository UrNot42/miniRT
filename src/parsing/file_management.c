/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:36:04 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 02:00:32 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO RM
void	print_scene(t_scene *scene);

bool	read_file(char *file, t_scene *scene)
{
	int	fd;
	int	len;

	len = ft_strlen(file);
	if (len < EXT_SIZE || ft_strncmp(&file[len - EXT_SIZE], EXTENSION,
			EXT_SIZE))
		return (p_error(ERR_FILEEXT), true);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (p_error(ERR_OPEN), true);
	if (scene_fill(scene, fd))
		return (true);
	if (close(fd))
		return (p_error(ERR_CLOSE), true);
	return (false);
}
