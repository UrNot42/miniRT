/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:39:43 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/02 17:09:30 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Set the default canvas object without allocating the mlx pointer
 *
 * @param screen
 * @param width
 * @param height
 * @return true
 * @return false
 */
bool	set_default_canvas(t_canvas	*screen, t_unt width, t_unt height)
{
	screen->width = width;
	screen->height = height;
	if (create_image(&screen->picture, (t_dim){width, height}, screen->ptr))
		return (true);
	set_image(*screen);
	screen->defined = true;
	return (false);
}

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
	if (init_canvas(&screen))
		return (screen);
	if (set_default_canvas(&screen, width, height))
		return (screen);
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

/**
 * @brief Closes and free the canvas
 *
 * @param screen
 */
void	close_canvas(t_canvas *screen)
{
	if (screen->win)
		close_window(screen);
	if (screen->ptr)
		mlx_destroy_display(screen->ptr);
	free(screen->ptr);
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
