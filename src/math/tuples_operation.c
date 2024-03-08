/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:58:47 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 15:25:12 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	tup_add(t_tuple a, t_tuple b)
{
	return ((t_tuple){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

t_tuple	tup_sub(t_tuple a, t_tuple b)
{
	return ((t_tuple){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w});
}
