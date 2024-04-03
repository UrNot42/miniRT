/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:40:37 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 11:41:47 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_col(t_color color)
{
	printf("Color: ( %f | %f | %f )\n", color.red, color.green, color.blue);
}

void	print_base(t_o_base base)
{
	printf("material:\n");
	printf("defined: %s\n", base.defined ? "yes" : "no");
	printf("diffuse: %f\n", base.m.diffuse);
	printf("specular: %f\n", base.m.specular);
	printf("shininess: %f\n", base.m.shininess);
	print_col(base.m.col);
	print_tup(base.pos, false);
}

void	print_mtx(t_o_mtrx mtx)
{
	print_m(mtx.transform, "Transform");
	// print_m(mtx.inverse, "Inverse Transform");
	// print_m(mtx.trans_inv, "Transpose of the Inverse Transform");
}

void	print_obj_details(t_obj obj)
{
	if (obj.kind == OBJ_SPHERE)
		printf("diameter: %f\n", obj.sphere.diameter);
	if (obj.kind == OBJ_CONE || obj.kind == OBJ_CYLINDER)
	{
		printf("width: %f\n", obj.cylinder.width);
		printf("height: %f\n", obj.cylinder.height);
		printf("minimum: %f\n", obj.cylinder.minimum);
		printf("maximum: %f\n", obj.cylinder.maximum);
		printf("min caped: %s\n", obj.cylinder.min_caped ? "yes" : "no");
		printf("min caped: %s\n", obj.cylinder.max_caped ? "yes" : "no");
	}
}

void	print_scene(t_scene	scene)
{
	printf("Printing scene\n");
	printf("-------\n");
	printf("Camera:\n");
	print_base(scene.camera.base);
	print_mtx(scene.camera.camera.mtx);
	print_tup(scene.camera.camera.normal, false);
	printf("horizontal size: %u\n", scene.camera.camera.hz_size);
	printf("vertical size: %u\n", scene.camera.camera.v_size);
	printf("pixel size: %f\n", scene.camera.camera.pxl_size);
	printf("hald width: %f\n", scene.camera.camera.half_width);
	printf("half height: %f\n", scene.camera.camera.half_height);
	printf("field of view: %f\n", scene.camera.camera.fov);
	printf("-------\n");
	/* printf("amb light:\n");
	print_base(scene.ambient_light.base);
	printf("ratio: %f\n", scene.ambient_light.alght.ratio);
	printf("-------\n\n");
	printf("Lights\n");
	printf("Size (%d) -use- (%d)\n=========\n", scene.li_size.max, scene.li_size.use);
	for (t_unt i = 0; i < scene.li_size.use; i++)
	{
		printf("light %u:\n", i);
		print_base(scene.light[i].base);
		printf("ratio: %f\n", scene.light[i].light.ratio);
		printf("-------\n");
	}
	printf("\nObjects\n");
	printf("Size (%d) -use- (%d)\n=========\n", scene.obj_size.max, scene.obj_size.use);
	for (t_unt i = 0; i < scene.obj_size.use; i++)
	{
		t_obj	obj = scene.objects[i];
		printf("object (%u) -> %d :\n", i, obj.kind);
		print_base(obj.base);
		if (obj.kind == OBJ_PLANE || obj.kind == OBJ_CYLINDER || obj.kind == OBJ_CUBE || obj.kind == OBJ_CONE)
			print_tup(obj.plane.normal, false);
		if (obj.kind == OBJ_SPHERE || obj.kind == OBJ_PLANE || obj.kind == OBJ_CYLINDER || obj.kind == OBJ_CUBE || obj.kind == OBJ_CONE)
			print_mtx(obj.sphere.mtx);
		print_obj_details(obj);
		printf("-------\n");
	} */
}
