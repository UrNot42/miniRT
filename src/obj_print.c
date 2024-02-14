/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:01:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/12 10:36:39 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_pos(t_pos	*pos)
{
	printf("x: %f\n", pos -> x);
	printf("\t\ty: %f\n", pos -> y);
	printf("\t\tz: %f\n", pos -> z);
}

void	print_col(t_color	*col)
{
	printf("Red  : %d\n", col -> red);
	printf("\t\tGreen: %d\n", col -> grn);
	printf("\t\tBlue : %d\n", col -> blu);
}

void	print_scene(t_scene *scene)
{
	printf("Scene {%p} : \n", scene);
	if (scene->camera.defined)
	{
		printf("\tCamera: \n");
		printf("\tpos:\t");
		print_pos(&scene->camera.position);
		printf("\tnorm:\t");
		print_pos(&scene->camera.orientation);
		printf("\tfov: %d\n", (unsigned int)scene->camera.fov);
	}
	if (scene->ambient_light.defined)
	{
		printf("\tAmbient Light: \n");
		printf("\tLight ratio: %lf\n", scene->ambient_light.ratio.light);
		printf("\tColor: \t");
		print_col(&scene->ambient_light.color);
	}
	for (size_t i = 0; i < scene->cy_size.use; i++)
	{
		printf("\tCylinder %ld: \n", i);
		print_pos(&scene->cylinder[i].position);
		printf("\tnorm:\t");
		print_pos(&scene->cylinder[i].orientation);
		printf("\tDiameter: %f\t", scene->cylinder[i].diameter);
		printf("\tHeight: %f\t", scene->cylinder[i].height);
		printf("\tColor: \t");
		print_col(&scene->cylinder[i].color);
	}
	for (size_t i = 0; i < scene->sp_size.use; i++)
	{
		printf("\tSphere %ld: \n", i + 1);
		print_pos(&scene->sphere[i].position);
		printf("\tDiameter: %f\t", scene->sphere[i].diameter);
		printf("\tColor: \t");
		print_col(&scene->sphere[i].color);
	}
	for (size_t i = 0; i < scene->pl_size.use; i++)
	{
		printf("\tPlane %ld: \n", i + 1);
		print_pos(&scene->plane[i].point);
		printf("\tnorm:\t");
		print_pos(&scene->plane[i].orientation);
		printf("\tColor: \t");
		print_col(&scene->plane[i].color);
	}
	for (size_t i = 0; i < scene->l_size.use; i++)
	{
		printf("\tLight source %ld: \n", i);
		// printf("\tLight ratio: %lf\n", scene->light[i].brgt.light);
		print_pos(&scene->light[i].position);
		printf("\tColor: \t");
		print_col(&scene->light[i].color);
	}
}
