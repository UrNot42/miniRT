/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:42:08 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/12 17:29:49 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*sphere(void)
{
	t_obj	*sphere;

	sphere = malloc(sizeof(t_obj));
	if (!sphere)
		return (p_error(ERR_MEM), NULL);
	sphere->defined = true;
	sphere->diameter = 1;
	sphere->pos = set_point(0, 0, 0);
	sphere->transform = get_id4mtrx();
	return (sphere);
}

void	set_transform(t_obj *o, t_4mtrx m)
{
	o->transform = m;
}
