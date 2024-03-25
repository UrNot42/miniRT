/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:17:17 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/24 10:42:01 by marvin           ###   ########.fr       */
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
	if (ac != 2)
		return (launch_tests());
	if (ac == 2 && ft_toupper(av[1][0]) == 'R')
		try_ray_trace();
	// scene = (t_scene){0};
	// if (read_file(av[1], &scene))
	// 	return (scene_free(&scene), EXIT_FAILURE);
	// scene_free(&scene);
	// printf("Code ran acordingly\n");
	// return (opening_window());
	return (EXIT_SUCCESS);
}
