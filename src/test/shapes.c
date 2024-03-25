/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:11:49 by marvin            #+#    #+#             */
/*   Updated: 2024/03/24 20:11:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Scenario
 Given
 And
 When
 Then
 And
 And

 |  +x		| point(5, 0.5, 0)	| vector(-1, 0, 0)	|  4 |  6 |\n
 | -x		| point(-5, 0.5, 0)	| vector(1, 0, 0)	|  4 |  6 |\n
 |  +y		| point(0.5, 5, 0)	| vector(0,-1, 0)	|  4 |  6 |\n
 | -y		| point(0.5,-5, 0)	| vector(0, 1, 0)	|  4 |  6 |\n
 |  +z		| point(0.5, 0, 5)	| vector(0, 0,-1)	|  4 |  6 |\n
 | -z		| point(0.5, 0,-5)	| vector(0, 0, 1)	|  4 |  6 |\n
 | inside	| point(0, 0.5, 0)	| vector(0, 0, 1)	| -1 |  1 |\n
*/

t_unt	test_(void)
{
	t_unt	err;

	scenario_start("Outline: A ray intersects a cube");
	given("c ← cube()", 0);
	given("r ← ray(<origin>, <direction>)", 1);
	when("xs ← local_intersect(c, r)", 0);
	then("xs.count = 2", 1, 0);
	then("xs[0].t = <t1>", 1, 1);
	then("xs[1].t = <t2>", 1, 2);
	printf("Examples:\n |			| origin			| direction			| t1 | t2 |\n");
	err = ex("", 0);
	err += ex("", 0);
	scenario_end(err);
	return (err);
}
