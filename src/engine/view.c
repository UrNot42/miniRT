/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:16:11 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/20 19:23:14 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_4mtrx	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple	left;
	t_tuple	true_up;
	t_tuple	forward;
	t_tuple	upn;
	t_4mtrx	orientation;

	forward = vec_norm(to - from);
	upn = vec_norm(up);
	left = vec_cross(forward, upn);
	true_up = vec_cross(left, forward);
	orientation = set_4mtrx((t_i4mtr){left.x, left.y, left.z, 0,
			true_up.x, true_up.y, true_up.z, 0,
			-forward.x, -forward.y, -forward.z, 0,
			0, 0, 0, 1});
	return (orientation * translation_mtrx(-from.x, -from.y, -from.z));
}
