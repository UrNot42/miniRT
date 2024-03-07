/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:29:22 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/07 15:26:49 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	test_tuple(void)
{
	t_tuple	a;
	t_unt	err;

	scenario_start("A tuple with w=1.0 is a point");
	given("a ← tuple(4.3, -4.2, 3.1, 1.0)");
	set_tuple(&a, (t_tuple){4.3, -4.2, 3.1, 1.0});
	err = 0;
	err += test_print("a.x = 4.3", a.x == 4.3);
	err += test_print("a.y = -4.2", a.y == -4.2);
	err += test_print("a.z = 3.1", a.z == 3.1);
	err += test_print("a.w = 1.0", a.w == 1.0);
	err += test_print("a is point", is_point(a));
	err += test_print("a is not vector", !is_vector(a));
	scenario_end(err);
	return (err);
}
