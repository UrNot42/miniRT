/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:39:43 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/01 20:59:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Creates a default canvas with default needs
 *
 * @param width
 * @param height
 * @return t_canvas in case of errors the canvas defined element will be false
 */
t_canvas	canvas(t_unt width, t_unt height)
{
	t_canvas	screen;

	screen.defined = false;
	screen.width = width;
	screen.height = height;
	if (init_canvas(&screen))
		return (screen);
	if (create_image(&screen.picture, (t_dim){width, height}, screen.ptr))
		return (screen);
	set_image(screen);
	screen.defined = true;
	return (screen);
}

/**
 * @brief gives deault informations to the structure
 *
 * @param screen
 * @return true if malloc failed
 * @return false
 */
bool	init_canvas(t_canvas *screen)
{
	screen->name = WINDOW_NAME;
	screen->ptr = mlx_init();
	if (!screen->ptr)
		return (true);
	screen->win = NULL;
	return (false);
}

// TODO
/**
 * @brief
 *
 * @param screen
 * @return true if malloc failed
 * @return false
 */
bool	open_canvas(t_canvas *screen)
{
	if (open_window(screen))
		return (true);
	return (false);
}

/**
 * @brief Closes and free the canvas
 *
 * @param screen
 */
void	close_canvas(t_canvas screen)
{
	if (screen.win)
		close_window(screen);
	if (screen.ptr && screen.picture && screen.picture->img)
		mlx_destroy_image(screen.ptr, screen.picture->img);
	if (screen.picture)
		free(screen.picture);
	if (screen.ptr)
		mlx_destroy_display(screen.ptr);
	free(screen.ptr);
}

/**
 * @brief puts canvas to window
 *
 * @param screen
 */
void	print_canvas(t_canvas screen)
{
	if (screen.win)
		mlx_put_image_to_window(screen.ptr,
			screen.win, screen.picture->img, 0, 0);
	else
		ft_printf("Canvas not opened\n");
}
