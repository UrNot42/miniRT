/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:57:43 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 13:00:29 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	hadamard_product(t_color c1, t_color c2)
{
	float	r;
	float	g;
	float	b;

	r = c1.red * c2.red;
	g = c1.green * c2.green;
	b = c1.blue * c2.blue;
	return (set_col(r, g, b));
}
