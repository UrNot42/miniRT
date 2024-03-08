/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:32:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 14:58:26 by ulevallo         ###   ########.fr       */
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

void	set_point(t_tuple *a, t_pos b)
{
	a->x = b.x;
	a->y = b.y;
	a->z = b.z;
	a->w = 1.0;
}

void	set_vec(t_tuple *a, t_pos b)
{
	a->x = b.x;
	a->y = b.y;
	a->z = b.z;
	a->w = 0;
}
