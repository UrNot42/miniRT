/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:56:06 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/12 18:08:55 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_canvas(t_canvas screen)
{
	mlx_put_image_to_window(screen.ptr, screen.win, screen.picture->img, 0, 0);
}
