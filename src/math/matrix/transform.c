/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:36:32 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/10 19:40:23 by ulevallo         ###   ########.fr       */
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
