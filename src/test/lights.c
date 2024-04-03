/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:52:18 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 09:44:39 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_unt	test_reflect_45(void)
{
	t_tuple	v;
	t_tuple	n;
	t_tuple	r;
	t_unt	err;

	scenario_start("Reflecting a vector approaching at 45°");
	given("v ← vector(1, -1, 0)", 0);
	v = set_vec(1, -1, 0);
	given("n ← vector(0, 1, 0)", 1);
	n = set_vec(0, 1, 0);
	when("r ← reflect(v, n)", 0);
	r = reflect(v, n);
	err = then("r = vector(1, 1, 0)", is_same_tuple(r, set_vec(1, 1, 0)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_reflect_slanted(void)
{
	t_tuple	v;
	t_tuple	n;
	t_tuple	r;
	t_unt	err;

	scenario_start("Reflecting a vector off a slanted surface");
	given("v ← vector(0, -1, 0)", 0);
	v = set_vec(0, -1, 0);
	given("n ← vector(√2/2, √2/2, 0)", 1);
	n = set_vec(sqrtf(2) / 2, sqrtf(2) / 2, 0);
	when("r ← reflect(v, n)", 0);
	r = reflect(v, n);
	err = then("r = vector(1, 0, 0)", is_same_tuple(r, set_vec(1, 0, 0)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_point_init(void)
{
	t_unt	err;
	t_color	intensity;
	t_obj	light;
	t_tuple	position;

	scenario_start("A point light has a position and intensity");
	given("intensity ← color(1, 1, 1)", 0);
	intensity = set_col(1, 1, 1);
	given("position ← point(0, 0, 0)", 1);
	position = origin();
	when("light ← point_light(position, intensity)", 0);
	light = o_light(position, intensity);
	err = then("light.position = position",
			is_same_tuple(light.pos, position), 0);
	err += then("light.intensity = intensity",
			is_same_tuple(light.m.col.tuple, intensity.tuple), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_material(void)
{
	t_mater	m;
	t_unt	err;

	scenario_start("The default material");
	given("m ← material()", 0);
	m = material();
	err = then("m.color = color(1, 1, 1)",
			is_same_col(m.col, set_col(1, 1, 1)), 0);
	err += then("m.diffuse = 0.9", f_eq(m.diffuse, 0.9), 2);
	err += then("m.specular = 0.9", f_eq(m.specular, 0.9), 3);
	err += then("m.shininess = 200.0", f_eq(m.shininess, 200.0), 4);
	scenario_end(err);
	return (err);
}

t_unt	test_default_mater(void)
{
	t_obj	s;
	t_mater	m;
	t_unt	err[2];

	s = o_sphere();
	scenario_start("A sphere has a default material");
	given("s ← sphere()", 0);
	when("m ← s.material", 0);
	m = s.m;
	err[0] = then(" m = material()", is_same_mat(m, material()), 0);
	scenario_end(err[0]);

	scenario_start("A sphere may be assigned a material");
	given("s ← sphere()", 0);
	given("m ← material()", 1);
	m = material();
	given("m.ambient ← 1", 2);
	when("s.material ← m", 0);
	s.m = m;
	err[1] = then("s.material = m", is_same_mat(s.m, m), 0);
	scenario_end(err[1]);
	return (err[0] + err[1]);
}

t_unt	test_light_eye_between(void)
{
	t_mater	m;
	t_tuple	p;
	t_tuple	eyev;
	t_tuple	normalv;
	t_obj	light;
	t_color	result;
	t_unt	err;

	scenario_start("Lighting with the eye between the light and the surface");
	given("m ← material()", 0);
	m = material();
	given("position ← point(0, 0, 0)", 1);
	p = origin();
	given("eyev ← vector(0, 0, -1)", 0);
	eyev = set_vec(0, 0, -1);
	given("normalv ← vector(0, 0, -1)", 1);
	normalv = set_vec(0, 0, -1);
	given("light ← point_light(point(0, 0, -10), color(1, 1, 1))", 2);
	light = o_light(set_point(0, 0, -10), set_col(1, 1, 1));
	when("result ← lighting(m, light, position, eyev, normalv)", 0);
	result = lighting((t_lgting){m, light,
			set_vec(0.1, 0.1, 0.1),
			p, eyev, normalv, false});
	err = then("result = color(1.9, 1.9, 1.9)",
			is_same_col(result, set_col(1.9, 1.9, 1.9)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_light_eye_between_ofst_45(void)
{
	t_mater	m;
	t_tuple	p;
	t_tuple	eyev;
	t_tuple	normalv;
	t_obj	light;
	t_color	result;
	t_unt	err;

	scenario_start("Lighting with the eye between light and surface, eye offset 45°");
	given("m ← material()", 0);
	m = material();
	given("position ← point(0, 0, 0)", 1);
	p = origin();
	given("eyev ← vector(0, √2/2, -√2/2)", 0);
	eyev = set_vec(0, sqrtf(2) / 2, -sqrtf(2) / 2);
	given("normalv ← vector(0, 0, -1)", 1);
	normalv = set_vec(0, 0, -1);
	given("light ← point_light(point(0, 0, -10), color(1, 1, 1))", 2);
	light = o_light(set_point(0, 0, -10), set_col(1, 1, 1));
	when("result ← lighting(m, light, position, eyev, normalv)", 0);
	result = lighting((t_lgting){m, light,
			set_vec(0.1, 0.1, 0.1),
			p, eyev, normalv, false});
	err = then("result = color(1.0, 1.0, 1.0)",
			is_same_col(result, set_col(1, 1, 1)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_light_eye_opposite_ofst_45(void)
{
	t_mater	m;
	t_tuple	p;
	t_tuple	eyev;
	t_tuple	normalv;
	t_obj	light;
	t_color	result;
	t_unt	err;

	scenario_start("Lighting with eye opposite surface, light offset 45°");
	given("m ← material()", 0);
	m = material();
	given("position ← point(0, 0, 0)", 1);
	p = origin();
	given("eyev ← vector(0, 0, -1)", 0);
	eyev = set_vec(0, 0, -1);
	given("normalv ← vector(0, 0, -1)", 1);
	normalv = set_vec(0, 0, -1);
	given("light ← point_light(point(0, 10, -10), color(1, 1, 1))", 2);
	light = o_light(set_point(0, 10, -10), set_col(1, 1, 1));
	when("result ← lighting(m, light, position, eyev, normalv)", 0);
	result = lighting((t_lgting){m, light,
			set_vec(0.1, 0.1, 0.1),
			p, eyev, normalv, false});
	err = then("result = color(0.7364, 0.7364, 0.7364)",
			is_same_col(result, set_col(0.7364, 0.7364, 0.7364)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_light_eye_in_path(void)
{
	t_mater	m;
	t_tuple	p;
	t_tuple	eyev;
	t_tuple	normalv;
	t_obj	light;
	t_color	result;
	t_unt	err;

	scenario_start("Lighting with eye in the path of the reflection vector");
	given("m ← material()", 0);
	m = material();
	given("position ← point(0, 0, 0)", 1);
	p = origin();
	given("eyev ← vector(0, -√2/2, -√2/2)", 0);
	eyev = set_vec(0, -sqrt(2) / 2, -sqrt(2) / 2);
	given("normalv ← vector(0, 0, -1)", 1);
	normalv = set_vec(0, 0, -1);
	given("light ← point_light(point(0, 10, -10), color(1, 1, 1))", 2);
	light = o_light(set_point(0, 10, -10), set_col(1, 1, 1));
	when("result ← lighting(m, light, position, eyev, normalv)", 0);
	result = lighting((t_lgting){m, light,
			set_vec(0.1, 0.1, 0.1),
			p, eyev, normalv, false});
	err = then("result = color(1.6364, 1.6364, 1.6364)",
			is_same_col(result, set_col(1.6364, 1.6364, 1.6364)), 0);
	scenario_end(err);
	return (err);
}

t_unt	test_light_behind_surface(void)
{
	t_mater	m;
	t_tuple	p;
	t_tuple	eyev;
	t_tuple	normalv;
	t_obj	light;
	t_color	result;
	t_unt	err;

	scenario_start("Lighting with the light behind the surface");
	given("m ← material()", 0);
	m = material();
	given("position ← point(0, 0, 0)", 1);
	p = origin();
	given("eyev ← vector(0, 0, -1)", 0);
	eyev = set_vec(0, 0, -1);
	given("normalv ← vector(0, 0, -1)", 1);
	normalv = set_vec(0, 0, -1);
	given("light ← point_light(point(0, 0, 10), color(1, 1, 1))", 2);
	light = o_light(set_point(0, 0, 10), set_col(1, 1, 1));
	when("result ← lighting(m, light, position, eyev, normalv)", 0);
	result = lighting((t_lgting){m, light,
			set_vec(0.1, 0.1, 0.1),
			p, eyev, normalv, false});
	err = then("result = color(0.1, 0.1, 0.1)",
			is_same_col(result, set_col(0.1, 0.1, 0.1)), 0);
	scenario_end(err);
	return (err);
}
