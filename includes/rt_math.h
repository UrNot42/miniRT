/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:49:41 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/07 15:12:13 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

typedef unsigned int	t_unt;
typedef unsigned char	t_uchar;

typedef float			t_tuple	__attribute__((ext_vector_type(4)));

/* Tuples */
void	set_tuple(t_tuple *a, t_tuple b);
bool	is_point(t_tuple a);
bool	is_vector(t_tuple a);

#endif
