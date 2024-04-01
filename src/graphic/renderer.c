/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:30:30 by marvin            #+#    #+#             */
/*   Updated: 2024/04/01 01:30:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	render_scene(t_wraper *data)
{
	open_canvas(data->screen);
	printf("Hey %p\n", data->screen);
	print_canvas(*data->screen);
	usleep(20000000);
	// while (displaying)
	// {
	// 	;
	// }
	free_loop(data);
	return (0);
}
