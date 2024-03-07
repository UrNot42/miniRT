/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:32:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/07 12:43:36 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_tuple(t_tuple *a, t_tuple b)
{
	a->x = b.x;
	a->y = b.y;
	a->z = b.z;
	a->w = b.w;
}

bool	is_point(t_tuple a)
{
	if (a.w == 1.0)
		return (true);
	else
		return (false);
}

bool	is_vector(t_tuple a)
{
	if (a.w == 0)
		return (true);
	else
		return (false);
}
