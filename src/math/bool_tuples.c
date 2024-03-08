/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_tuples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:27:51 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 14:54:02 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_point(t_tuple a)
{
	if (f_eq(a.w, 1.0))
		return (true);
	else
		return (false);
}

bool	is_vec(t_tuple a)
{
	if (f_eq(a.w, 0))
		return (true);
	else
		return (false);
}

bool	is_same_tuple(t_tuple a, t_tuple b)
{
	if (f_eq(a.x, b.x) && f_eq(a.y, b.y) && f_eq(a.z, b.z) && f_eq(a.w, b.w))
		return (true);
	else
		return (false);
}
