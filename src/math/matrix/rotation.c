/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:36:14 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/11 12:38:46 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_4mtrx	rotation_x(float r)
{
	t_4mtrx	translate;

	translate = get_id4mtrx();
	translate[1][1] = cos(r);
	translate[1][2] = -sin(r);
	translate[2][1] = sin(r);
	translate[2][2] = cos(r);
	return (translate);
}

t_4mtrx	rotation_y(float r)
{
	t_4mtrx	translate;

	translate = get_id4mtrx();
	translate[0][0] = cos(r);
	translate[0][2] = sin(r);
	translate[2][0] = -sin(r);
	translate[2][2] = cos(r);
	return (translate);
}

t_4mtrx	rotation_z(float r)
{
	t_4mtrx	translate;

	translate = get_id4mtrx();
	translate[0][0] = cos(r);
	translate[0][1] = -sin(r);
	translate[1][0] = sin(r);
	translate[1][1] = cos(r);
	return (translate);
}
