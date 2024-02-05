/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:54:04 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 07:43:47 by ulevallo         ###   ########.fr       */
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
		return (elemt->use++, false);
	return (true);
}
