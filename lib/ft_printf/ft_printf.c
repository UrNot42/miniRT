/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:03:33 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 02:26:04 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_flags(char c, va_list args, int fd)
{
	if (c == 'c')
		return (ft_putchar_fd((char) va_arg(args, int), 1), 1);
	else if (c == 's')
		return (ft_putstrf(va_arg(args, char *), fd));
	else if (c == 'p')
		return (ft_putpf((uintptr_t)va_arg(args, void *), fd));
	else if (c == 'd' || c == 'i')
		return (ft_putnbrf((long)va_arg(args, int), 10, '\0', fd));
	else if (c == 'u')
		return (ft_putnbrf((long)va_arg(args, unsigned int), 10, '\0', fd));
	else if (c == 'x' || c == 'X')
		return (ft_putnbrf((unsigned int)va_arg(args, int), 16, c, fd));
	else if (c == '%')
		return (write(fd, "%", 1), 1);
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_printf_flags(s[++i], args, 1);
			i++;
		}
		else if (s[i])
		{
			count++;
			write(1, &s[i++], 1);
		}
	}
	return (count);
}

int	ft_fprintf(int fd, const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_printf_flags(s[++i], args, fd);
			i++;
		}
		else if (s[i])
		{
			count++;
			write(fd, &s[i++], 1);
		}
	}
	return (count);
}
