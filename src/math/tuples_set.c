/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:32:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 15:23:48 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	set_tuple(t_tuple a)
{
	return ((t_tuple){a.x, a.y, a.z, a.w});
}

t_tuple	set_point(t_pos a)
{
	return ((t_tuple){a.x, a.y, a.z, 1.0});
}

t_tuple	set_vec(t_pos a)
{
	return ((t_tuple){a.x, a.y, a.z, 0});
}
