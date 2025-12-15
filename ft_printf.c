/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilheda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:25:07 by guilheda          #+#    #+#             */
/*   Updated: 2025/12/15 21:52:14 by guilheda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char *str, int i, va_list *args)
{
	if (str[i] == 'c')
		return (ft_putstr(0, va_arg(*args, int), CHAR));
	if (str[i] == 's')
		return (ft_putstr(va_arg(*args, char *), 0, STR));
	if (str[i] == 'i' || str[i] == 'd')
		return (ft_putnbr(va_arg(*args, int)));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	count;
	size_t	i;

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
