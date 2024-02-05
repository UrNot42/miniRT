/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:48:20 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 02:25:08 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrf(char *s, int fd)
{
	if (!s)
		return (ft_putstr_fd("(null)", fd), 6);
	else
		return (ft_putstr_fd(s, fd), ft_strlen(s));
}

void	ft_putnbrb(unsigned long n, const unsigned long div, char a, int fd)
{
	char	c;

	if (n < div)
	{
		c = n + '0';
		if (n >= 10)
			c = n + a - 33;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbrb(n / div, div, a, fd);
		ft_putnbrb(n % div, div, a, fd);
	}
}

int	ft_putnbrf(long n, int base, char a, int fd)
{
	int				count;
	unsigned long	un;

	un = 0;
	count = 0;
	if (n < 0 && !a)
	{
		un = (unsigned long) -n;
		write(fd, "-", 1);
		count++;
	}
	else
		un = (unsigned long) n;
	ft_putnbrb(un, base, a, fd);
	un += (!un);
	while (un != 0)
	{
		un /= base;
		count++;
	}
	return (count);
}

int	ft_putpf(uintptr_t p, int fd)
{
	if (!p)
		return (write(fd, "(nil)", 5), 5);
	else
	{
		write(1, "0x", 2);
		return (ft_putnbrf(p, 16, 'x', fd) + 2);
	}
}
