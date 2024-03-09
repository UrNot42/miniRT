/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_graphic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:18:23 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/09 14:22:04 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_GRAPHIC_H
# define RT_GRAPHIC_H

# define WINDOW_NAME  "Mini Roaaaaaaaaaad Trip"

typedef struct s_canvas	t_canvas;
typedef struct s_data	t_data;
typedef unsigned int	t_unt;
typedef t_unt			t_dim	__attribute__((ext_vector_type(2)));

struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct	s_canvas
{
	void		*ptr;
	void		*win;
	char		*name;
	t_data		*data;
	t_unt		height;
	t_unt		width;
};

#endif
