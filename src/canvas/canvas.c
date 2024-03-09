/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:39:43 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 14:19:35 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	canvas(t_unt width, t_unt height)
{
	t_canvas	screen;

	screen.width = width;
	screen.height = height;
	if (!init_mlx(&screen))
		return (NULL);
	if (init_window(&screen, (t_dim){screen.width, screen.height}))
		return (screen);
	return (screen);
}
