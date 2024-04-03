/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:17:17 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 12:08:06 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	opening_window(void)
{
	void	*context;
	void	*window;

	context = mlx_init();
	if (!context)
		return (1);
	window = mlx_new_window(context, 800, 600, "MiniRT");
	if (!window)
	{
		mlx_destroy_display(context);
		free(context);
		return (1);
	}
	while (1)
		;
	mlx_destroy_window(context, window);
	mlx_destroy_display(context);
	free(context);
	return (0);
}

int	main(int ac, char **av)
{
	t_scene	world;

	if (ac < 2)
		return (p_error(ERR_NO_PROMPT), EXIT_FAILURE);
	if (ac > 2)
		return (p_error(ERR_BAD_PROMPT), EXIT_FAILURE);
	if (read_file(av[1], &world))
		return (scene_free(&world), EXIT_FAILURE);
	ray_trace(world);
	return (EXIT_SUCCESS);
}
