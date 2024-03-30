/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:17:17 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/30 07:36:13 by marvin           ###   ########.fr       */
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
	t_scene		world;
	t_canvas	*screen;
	t_cam		cam;

	if (ac != 2)
		return (launch_tests());
	if (ac == 2 && ft_toupper(av[1][0]) == 'R') // TODO RM
		return (try_ray_trace(), EXIT_SUCCESS);
	world = (t_scene){0};
	if (read_file(av[1], &world))
		return (scene_free(&world), EXIT_FAILURE);
	cam = camera(300, 300, M_PI / 2);
	set_transform(&cam.mtx, view_transform(set_point(0, 1.5, -5), set_point(-0.2, 1.5, 0), set_vec(0, 1, 0)));
	screen = render(cam, world);
	open_canvas(screen);
	print_canvas(*screen);
	usleep(20000500);
	scene_free(&world);
	return (EXIT_SUCCESS);
}
