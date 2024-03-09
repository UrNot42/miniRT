/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:39:43 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 16:39:54 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	canvas(t_unt width, t_unt height)
{
	t_canvas	screen;

	screen.defined = false;
	screen.width = width;
	screen.height = height;
	if (init_canvas(&screen))
		return (screen);
	if (open_window(&screen))
		return (screen);
	if (create_image(&screen.picture, (t_dim){width, height}, screen.ptr))
		return (screen);
	set_image(screen);
	screen.defined = true;
	return (screen);
}

bool	init_canvas(t_canvas *screen)
{
	screen->name = WINDOW_NAME;
	screen->ptr = mlx_init();
	if (!screen->ptr)
		return (true);
	return (false);
}

void	close_canvas(t_canvas screen)
{
	close_window(screen);
	if (screen.ptr && screen.win)
		mlx_destroy_display(screen.ptr);
	free(screen.ptr);
}
