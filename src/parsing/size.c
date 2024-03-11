/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:54:04 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/11 18:00:52 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	sz_set(t_size *elmt)
{
	elmt->max = O_SIZE_SET;
	elmt->use = 0;
	return (false);
}

bool	sz_add(t_size *elemt)
{
	if (elemt->use >= elemt->max)
		return (true);
	elemt->use++;
	return (false);
}

void	copy_element(t_obj *obj_1, t_obj obj_2)
{
	*obj_1 = (t_obj){obj_2.type,
		(t_tuple){obj_2.pos.x, obj_2.pos.y, obj_2.pos.z},
		(t_tuple){obj_2.norm.x, obj_2.norm.y, obj_2.norm.z},
		obj_2.ratio,
		obj_2.diameter,
		obj_2.height,
		obj_2.fov,
		set_col(obj_2.col.red, obj_2.col.green, obj_2.col.blue),
		obj_2.size,
		obj_2.defined};
}

bool	sz_new_elemmt(t_obj **ptr, t_size *size)
{
	t_obj	*new_ptr;
	t_unt	i;

	if (!sz_add(size))
		return (false);
	if (size->max * 2 > O_SIZE_MAX)
		return (p_error(ERR_OBJ_MAX_SZ), true);
	size->max *= 2;
	if (size->max < 1)
		sz_set(size);
	new_ptr = ft_calloc(sizeof(t_obj), size->max);
	if (!new_ptr)
		return (p_error(ERR_MEM), true);
	i = 0;
	while (i < size->use)
	{
		copy_element(&new_ptr[i], (*ptr)[i]);
		i++;
	}
	free(*ptr);
	(*ptr) = new_ptr;
	size->use++;
	return (false);
}
