/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:14:50 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/27 09:09:45 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Create a image object allocating and setting its specific contents
 *
 * @param picture
 * @param size
 * @param data_ptr
 * @return true if malloc error
 * @return false
 */
bool	create_image(t_image **picture, t_dim size, void *data_ptr)
{
	(*picture) = malloc(sizeof(t_image));
	if (!(*picture))
		return (true);
	(*picture)->width = size.x;
	(*picture)->height = size.y;
	(*picture)->img = mlx_new_image(data_ptr,
			(*picture)->width, (*picture)->height);
	if (!(*picture)->img)
		return (true);
	(*picture)->addr = mlx_get_data_addr((*picture)->img,
			&(*picture)->bits_per_pixel, &(*picture)->line_length,
			&(*picture)->endian);
	return (false);
}

/**
 * @brief Set the image object to basically all 0
 *
 * @param screen
 */
void	set_image(t_canvas screen)
{
	t_unt	x;
	t_unt	y;

	x = 0;
	y = 0;
	while (y < screen.height)
	{
		while (x < screen.width)
			pixel_put(screen.picture, x++, y, 0);
		y++;
	}
}
