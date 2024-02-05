/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:54:04 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 14:28:41 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sz_set(t_size *elmt)
{
	elmt->max = O_SIZE_SET;
	elmt->use = 0;
}

bool	sz_add(t_size *elemt)
{
	if (elemt->use < elemt->max)
		return (elemt->use++, true);
	return (false);
}

bool	sz_new_elemmt(void **ptr, t_size *elemt, size_t ptr_sz)
{
	void			**new_ptr;
	unsigned int	i;

	if (!sz_add(elemt))
		return (false);
	if (elemt->max >= O_SIZE_MAX)
		return (p_error(ERR_OBJ_MAX_SZ), true);
	elemt->max *= 10;
	new_ptr = malloc(ptr_sz * elemt->max);
	if (!new_ptr)
		return (p_error(ERR_MEM), true);
	i = 0;
	while (i < elemt->use)
	{
		new_ptr[i] = ptr[i];
		i++;
	}
	free(ptr);
	ptr = new_ptr;
	elemt->use++;
	return (false);
}
