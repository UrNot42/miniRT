/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:25:38 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/12 18:08:21 by ulevallo         ###   ########.fr       */
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
	printf("Type: %c(%u)\n", obj->type, obj->type);
	print_tup(obj->pos, 1);
	print_tup(obj->norm, 1);
	printf("ratio: %lf\n", obj->ratio);
	printf("diameter: %lf\n", obj->diameter);
	printf("height: %lf\n", obj->height);
	printf("fov: %u\n", obj->fov);
	print_col(&obj->col, 1);
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
		print_col(&scene->ambient_light.col, 0);
	}
	for (size_t i = 0; i < scene->cy_size.use; i++)
	{
		printf("\tCylinder %ld: \n", i);
		print_tup(scene->cylinder[i].pos, 1);
		printf("\tnorm:\t");
		print_tup(scene->cylinder[i].norm, 0);
		printf("\tDiameter: %f\t", scene->cylinder[i].diameter);
		printf("\tHeight: %f\t", scene->cylinder[i].height);
		printf("\tColor: \t");
		print_col(&scene->cylinder[i].col, 0);
	}
	for (size_t i = 0; i < scene->sp_size.use; i++)
	{
		printf("\tSphere %ld: \n", i + 1);
		print_tup(scene->sphere[i].pos, 1);
		printf("\tDiameter: %f\t", scene->sphere[i].diameter);
		printf("\tColor: \t");
		print_col(&scene->sphere[i].col, 0);
	}
	for (size_t i = 0; i < scene->pl_size.use; i++)
	{
		printf("\tPlane %ld: \n", i + 1);
		print_tup(scene->plane[i].pos, 1);
		printf("\tnorm:\t");
		print_tup(scene->plane[i].norm, 0);
		printf("\tColor: \t");
		print_col(&scene->plane[i].col, 0);
	}
	for (size_t i = 0; i < scene->l_size.use; i++)
	{
		printf("\tLight source %ld: \n", i);
		printf("\tLight ratio: %lf\n", scene->light[i].ratio);
		print_tup(scene->light[i].pos, 1);
		printf("\tColor: \t");
		print_col(&scene->light[i].col, 0);
	}
}
