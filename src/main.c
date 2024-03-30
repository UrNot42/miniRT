/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:17:17 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/29 19:05:50 by ulevallo         ###   ########.fr       */
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

	if (ac != 2)
		return (launch_tests());
	if (ac == 2 && ft_toupper(av[1][0]) == 'R') // TODO RM
		return (try_ray_trace(), EXIT_SUCCESS);
	world = (t_scene){0};
	if (read_file(av[1], &world))
		return (scene_free(&world), EXIT_FAILURE);
	scene_free(&world);
	printf("Code ran acordingly\n");
	return (opening_window());
	return (EXIT_SUCCESS);
}
