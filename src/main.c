/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:17:17 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/01 19:40:08 by marvin           ###   ########.fr       */
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
	t_wraper	data;

	if (ac != 2)
		return (launch_tests());
	if (ac == 2 && ft_toupper(av[1][0]) == 'R') // TODO RM
		return (try_ray_trace(), EXIT_SUCCESS);
	data.scene = scene_init();
	if (read_file(av[1], &data.scene))
		return (scene_free(&data.scene), EXIT_FAILURE);
	data.screen = render(data.scene.camera.camera, data.scene);
	start_loop(&data);
	return (EXIT_SUCCESS);
}
