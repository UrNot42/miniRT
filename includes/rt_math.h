/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:49:41 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 15:25:26 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

# define EPSILON 0.0001

typedef unsigned int	t_unt;
typedef unsigned char	t_uchar;
typedef struct s_pos	t_pos;

typedef float			t_tuple	__attribute__((ext_vector_type(4)));

/* float */
float	my_fabs(float a);
bool	f_eq(float a, float b);

/* Tuples */
t_tuple	set_tuple(t_tuple a);
t_tuple	set_point(t_pos a);
t_tuple	set_vec(t_pos a);
bool	is_point(t_tuple a);
bool	is_vec(t_tuple a);
bool	is_same_tuple(t_tuple a, t_tuple b);
t_tuple	tup_add(t_tuple a, t_tuple b);
t_tuple	tup_sub(t_tuple a, t_tuple b);

#endif
