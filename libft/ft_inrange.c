/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:02:12 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 03:06:15 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
A bool value function to tell if a <= num <= b
*/
int	ft_inr(int num, int a, int b)
{
	return (a <= num && num <= b);
}
