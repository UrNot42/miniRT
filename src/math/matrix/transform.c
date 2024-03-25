/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:36:32 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/11 12:40:23 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_4mtrx	translation_mtrx(float x, float y, float z)
{
	t_4mtrx	translate;

	translate = get_id4mtrx();
	translate[0][3] = x;
	translate[1][3] = y;
	translate[2][3] = z;
	return (translate);
}

t_4mtrx	scale_mtrx(float x, float y, float z)
{
	t_4mtrx	translate;

	translate = get_id4mtrx();
	translate[0][0] = x;
	translate[1][1] = y;
	translate[2][2] = z;
	return (translate);
}

t_4mtrx	shearing(t_shear rel)
{
	t_4mtrx	translate;

	translate = get_id4mtrx();
	translate[0][1] = rel[0];
	translate[0][2] = rel[1];
	translate[1][0] = rel[2];
	translate[1][2] = rel[3];
	translate[2][0] = rel[4];
	translate[2][1] = rel[5];
	return (translate);
}

void	set_transform(t_obj *o, t_4mtrx m)
{
	o->transform = m;
	o->inverse = inverse_4mtrx(m);
	o->trans_inv = transpose(o->inverse);
}
