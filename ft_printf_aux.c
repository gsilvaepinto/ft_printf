/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilheda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:25:13 by guilheda          #+#    #+#             */
/*   Updated: 2025/12/15 15:46:57 by guilheda         ###   ########.fr       */
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
