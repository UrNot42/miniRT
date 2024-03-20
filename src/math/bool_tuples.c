/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_tuples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:27:51 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/20 17:28:49 by ulevallo         ###   ########.fr       */
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

bool	is_same_col(t_color a, t_color b)
{
	if (f_eq(a.red, b.red) && f_eq(a.green, b.green) && f_eq(a.blue, b.blue))
		return (true);
	else
		return (false);
}

bool	is_same_mat(t_mater a, t_mater b)
{
	if (is_same_col(a.col, b.col)
		&& f_eq(a.ambient, b.ambient) && f_eq(a.diffuse, b.diffuse)
		&& f_eq(a.specular, b.specular) && f_eq(a.shininess, b.shininess))
		return (true);
	else
		return (false);
}
