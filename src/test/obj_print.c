/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:25:38 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/26 10:08:06 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
	WARNING ->
	THIS IS A DEBUG FILE IT OUGHT TO BE REMOVED
	TODO RM WHOLE FILE

	The purpose of the global variable is to keep a norm error here
*/

void	*g_a;

void	print_col(t_color	*col, bool tab)
{
	if (tab)
		printf("\t\t");
	printf("Red  : %f\n", col -> red);
	printf("\t\tGreen: %f\n", col -> green);
	printf("\t\tBlue : %f\n", col -> blue);
}

void	print_obj(t_obj *obj)
{
	printf("OBJECT\n type: %u\n", obj->type);
	printf("pos: ");
	print_tup(obj->pos, false);
	printf("norm: ");
	print_tup(obj->norm, false);
	printf("ratio: %f\n", obj->ratio);
	printf("diameter: %f\n", obj->diameter);
	printf("height: %f\n", obj->height);
	printf("size: %p\n", obj->size);
	printf("ratio: %f\n", obj->fov);
	printf("matter col: ");
	print_tup(obj->m.col.tuple, false);
	printf("matter: \n\t ambiant: %f\n\t diffuse: %f\n\t specular: %f\n\t\
 shininess: %f\n", obj->m.ambient, obj->m.diffuse,
		obj->m.specular, obj->m.shininess);
	print_m(obj->transform, 'T');
	print_m(obj->inverse, 'I');
	print_m(obj->trans_inv, 'i');
	printf("defined: %s\n", obj->defined ? "yes" : "no");
}

void	print_scene(t_scene *scene)
{
	printf("Scene {%p} : \n", scene);
	if (scene->camera.defined)
	{
		printf("\tCamera: \n");
		printf("\tpos:\t");
		print_tup(scene->camera.pos, 0);
		printf("\tnorm:\t");
		print_tup(scene->camera.norm, 0);
		printf("\tfov: %d\n", (t_unt)scene->camera.fov);
	}
	if (scene->ambient_light.defined)
	{
		printf("\tAmbient Light: \n");
		printf("\tLight ratio: %lf\n", scene->ambient_light.ratio);
		printf("\tColor: \t");
		print_col(&scene->ambient_light.m.col, 0);
	}
	// TODO print objects
}

