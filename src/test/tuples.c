/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:22 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/07 12:12:37 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	test_tuple(void)
{
	t_tuple	a;
	unsingederr

	scenario_start("A tuple with w=1.0 is a point");
	set_tuple(&a, (t_tuple){4.3, -4.2, 3.1, 1.0});
	test("A.x = 4.3", a.x == 4.3);
	test("A.y = -4.2", a.y == -4.2);
	test("A.z = 3.1", a.z == 3.1);
	test("A.w = 1.0", a.w == 1.0);
	test("A is point", is_point(a));
	test("A is not vector", is_point(a));
}
