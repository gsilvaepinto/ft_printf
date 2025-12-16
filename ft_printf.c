/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilheda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:25:07 by guilheda          #+#    #+#             */
/*   Updated: 2025/12/16 12:05:59 by guilheda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char *str, int i, va_list *args)
{
	void	*ptr;

	if (str[i] == 'c')
		return (ft_putstr(0, va_arg(*args, int), CHAR));
	if (str[i] == 's')
		return (ft_putstr(va_arg(*args, char *), 0, STR));
	if (str[i] == 'i' || str[i] == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	if (str[i] == 'u')
		return (ft_putnbrbase(va_arg(*args, unsigned int), DEC, 10));
	if (str[i] == 'x')
		return (ft_putnbrbase(va_arg(*args, unsigned int), HEXLOW, 16));
	if (str[i] == 'X')
		return (ft_putnbrbase(va_arg(*args, unsigned int), HEXUP, 16));
	if (str[i] == '%')
		return (ft_putstr(0, '%', CHAR));
	if (str[i] == 'p')
	{
		ptr = va_arg(*args, void *);
		if (!ptr)
			return (write(1, "(nil)", 5));
		write(1, "0x", 2);
		return (2 + ft_putnbrbase((unsigned long)ptr, HEXLOW, 16));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_format(str, i, &args);
		}
		else
			count += ft_putstr(0, str[i], CHAR);
		i++;
	}
	va_end(args);
	return (count);
}
