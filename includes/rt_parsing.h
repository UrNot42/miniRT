/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:56:40 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/06 14:49:59 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

# include "minirt.h"

unsigned int	parse_line(char *line, t_scene *scene);
bool			set_pos(t_pos *pos, char *line, unsigned int *idx);
bool			set_color(t_color *color, char *line, unsigned int *idx);
bool			set_int_wbound(int *num, t_bound boundary,
					char *line, unsigned int *idx);
bool			set_db_wbound(double *num, t_bound boundary,
					char *line, unsigned int *idx);
bool			set_db(double *num, char *line, unsigned int *idx);
bool			set_int(int *num, char *line, unsigned int *idx);
bool			set_obj(t_scene *scene, int id);

bool			scene_fill(t_scene *scene, int fd);
bool			scene_init(t_scene *scene);
bool			scene_free(t_scene *scene);

bool			read_file(char *file, t_scene *scene);

bool			sz_set(t_size *elmt);
bool			sz_add(t_size *elemt);
bool			sz_new_elemmt(t_obj **ptr, t_size *size);

#endif
