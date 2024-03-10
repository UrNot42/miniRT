/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:50:39 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/10 19:41:05 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_translation_multiplication(void)
{
	t_4mtrx	transform;
	t_tuple	p;
	t_unt	err;

	scenario_start("Multiplying by a translation matrix");
	given("transform ← translation(5, -3, 2)", 0);
	transform = translation_mtrx(5, -3, 2);
	given("p ← point(-3, 4, 5)", 0);
	p = set_point(-3, 4, 5);
	err = then("transform * p = point(2, 1, 7)", is_same_tuple(tup_mtrx(transform, p),
			set_point(2, 1, 7)), 0);
	scenario_end(err);
	return (err);
}
