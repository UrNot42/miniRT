/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:56:40 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/30 07:04:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

typedef unsigned int	t_unt;
typedef unsigned char	t_uchar;

t_unt	parse_line(char *line, t_scene *scene);
bool	parse_pos(t_tuple *pos, char *line, t_unt *idx);
bool	parse_color(t_color *color, char *line, t_unt *idx);
bool	set_int_wbound(int *num, t_bound boundary,
			char *line, t_unt *idx);
bool	set_f_wbound(float *num, t_bound boundary,
			char *line, t_unt *idx);
bool	set_float(float *num, char *line, t_unt *idx);
bool	set_int(int *num, char *line, t_unt *idx);
bool	parse_obj(t_scene *scene, int id);

void	scene_translate_matrix(t_scene	world);
bool	scene_fill(t_scene *scene, int fd);
t_scene	scene_init(void);
bool	scene_free(t_scene *scene);

bool	read_file(char *file, t_scene *scene);

bool	sz_set(t_size *elmt);
bool	sz_add(t_size *elemt);
bool	add_obj_sz(t_obj **ptr, t_size *size);

#endif
