/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:53:11 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 09:53:28 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_skip_spaces(char *line, unsigned int *pos)
{
	while (line && line[*pos] && ft_isispace(line[*pos]))
		(*pos)++;
}
