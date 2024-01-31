/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:17:17 by ulevallo          #+#    #+#             */
/*   Updated: 2024/01/22 03:37:54 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	void	*context;
	void	*window;

	context = mlx_init();
	if (!context)
		return (EXIT_FAILURE);
	window = mlx_new_window(context, 800, 600, "MiniRT");
	if (!window)
	{
		mlx_destroy_display(context);
		free(context);
		return (EXIT_FAILURE);
	}
	while (1)
		;
	mlx_destroy_window(context, window);
	mlx_destroy_display(context);
	free(context);
	return (EXIT_SUCCESS);
}
