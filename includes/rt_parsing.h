/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:56:40 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 13:39:26 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

typedef struct s_parscene	t_parscene;

struct s_parscene
{
	t_obj	camera;
	t_obj	ambient_light;
	t_obj	*objects;
	t_size	obj_size;
	t_obj	*light;
	t_size	li_size;
};

t_unt	parse_line(char *line, t_scene *scene);
bool	parse_pos(t_tuple *pos, char *line, t_unt *idx);
bool	parse_color(t_color *color, char *line, t_unt *idx);
bool	set_int_wbound(int *num, t_bound boundary,
			char *line, t_unt *idx);
bool	set_f_wbound(float *num, t_bound boundary,
			char *line, t_unt *idx);
bool	set_float(float *num, char *line, t_unt *idx);
bool	set_int(int *num, char *line, t_unt *idx);

// Scene
bool	scene_fill(t_scene *scene, int fd);
t_scene	scene_init(void);
bool	scene_free(t_scene *scene);

// Translate
void	translate_points(t_scene *world);
void	translate_set_camera(t_cam *cam);
void	translate_matrix(t_obj *obj, t_size size);
void	translate_special_obj(t_scene *world);

bool	read_file(char *file, t_scene *scene);

bool	sz_set(t_size *elmt);
bool	sz_add(t_size *elemt);
bool	add_obj_sz(t_obj **ptr, t_size *size);

#endif
