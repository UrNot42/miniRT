/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:32:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 16:36:37 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	set_tuple(float x, float y, float z, float w)
{
	return ((t_tuple){x, y, z, w});
}

t_tuple	set_point(float x, float y, float z)
{
	return ((t_tuple){x, y, z, 1.0});
}

t_tuple	set_vec(float x, float y, float z)
{
	return ((t_tuple){x, y, z, 0});
}

t_color	set_col(float r, float g, float b)
{
	t_color	a;

	a.red = r;
	a.green = g;
	a.blue = b;
	a.tuple.w = 0;
	return (a);
}
