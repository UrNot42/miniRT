/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:36:32 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 09:24:06 by ulevallo         ###   ########.fr       */
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

void	set_transform(t_o_mtrx *mtrx, t_4mtrx m)
{
	mtrx->transform = m;
	mtrx->inverse = inverse_4mtrx(m);
	mtrx->trans_inv = transpose(mtrx->inverse);
}

t_4mtrx	tup_scale_m(t_tuple pos)
{
	return (scale_mtrx(pos.x, pos.y, pos.z));
}

t_4mtrx	tup_translate_m(t_tuple pos)
{
	return (translation_mtrx(pos.x, pos.y, pos.z));
}
