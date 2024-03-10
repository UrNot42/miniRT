/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:32:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/10 13:58:57 by ulevallo         ###   ########.fr       */
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

	a.tuple = set_tuple(r, g, b, 0);
	return (a);
}

t_tuple	tup_mtrx(t_4mtrx a, t_tuple b)
{
	t_tuple	result;

	result = mtrx2vec(a * vec2mtrx(b));
	return (result);
}
