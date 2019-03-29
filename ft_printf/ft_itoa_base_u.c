/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:03:57 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 14:01:15 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*itoa_fill(char *tab, uintmax_t value, int base)
{
	uintmax_t			tmp;
	int					size;
	char				*str;

	size = 0;
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[value % base];
		size--;
		value = value / base;
	}
	return (str);
}

char					*ft_itoa_base_u(uintmax_t value, int base)
{
	char				*str;
	char				*tab;

	tab = "0123456789abcdef";
	str = itoa_fill(tab, value, base);
	return (str);
}
