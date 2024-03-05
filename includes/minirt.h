/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:54:43 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/05 19:17:55 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* --==--==--==--==--INCLUDES--==--==--==--==-- */

# define XK_MISCELLANY
# define XK_LATIN1
# include <X11/keysymdef.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/time.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "rt_error.h"
# include "rt_obj.h"
# include "parsing.h"

/* --==--==--==--==--DEFINES--==--==--==--==-- */

# define EXTENSION ".rt"
# define EXT_SIZE 3

/* -=-=-=-=-COLORS-=-=-=-=- */

# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define RESET   "\033[0;0m"
# define BACK    "\033[F"
# define PREV_LN "\033[A"

/* --==--==--==--==--FUNCTIONS--==--==--==--==-- */

void	print_scene(t_scene *scene);

#endif
