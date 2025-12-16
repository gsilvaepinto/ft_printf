/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilheda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:25:13 by guilheda          #+#    #+#             */
/*   Updated: 2025/12/16 11:30:49 by guilheda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str, char c, int is_char)
{
	int	i;

	i = 0;
	if (is_char)
		return (write(1, &c, 1));
	if (!str)
		str = "(null)";
	while (str[i])
		i++;
	return (write(1, str, i));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483647)
	{
		count += write(1, "-", 1);
		count += write(1, "2", 1);
		nb = 147483647;
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (count);
}

int	ft_putnbrbase(unsigned long nb, char *str, int base)
{
	int count;

	count = 0;
	if (nb >= (unsigned long)base)
		count += ft_putnbrbase(nb / base, str, base);
	count += write(1, &str[nb % base], 1);
	return (count);
}