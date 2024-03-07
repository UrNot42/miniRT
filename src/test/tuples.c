/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:22 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/07 12:02:16 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	test_tuple(void)
{
	t_tuple	a;

	scenario_start("Tuple_init");
	set_tuple(&a, (t_tuple){4.3, -4.2, 3.1, 1.0});
	test("x val", a.x == 4.3);
	test("y val", a.y == -4.2);
	test("z val", a.z == 3.1);
	test("w val", a.w == 1.0);
	test("is point", is_point(a));
	test("is not vector", is_point(a));
}
