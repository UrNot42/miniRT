/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:56:40 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 14:58:35 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

unsigned int	parse_line(char *line, t_scene *scene);
bool			set_pos(t_pos *pos, char *line, unsigned int *idx);

bool			set_ratio(t_light *light, char *line, unsigned int *idx);
bool			set_cylinder(t_cylinder *cy, char *line, unsigned int *idx);
bool			set_sphere(t_sphere *sp, char *line, unsigned int *idx);
bool			set_fov(t_camera *cam, char *line, unsigned int *idx);
bool			set_color(t_color *color, char *line, unsigned int *idx);

t_pos			*get_norm(t_scene *scene, unsigned int id);
t_pos			*get_pos(t_scene *scene, unsigned int id);
t_color			*get_color(t_scene *scene, unsigned int id);

#endif
