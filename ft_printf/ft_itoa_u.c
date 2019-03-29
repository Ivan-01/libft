/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:08:56 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 13:56:04 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*itoa_fill(char *tab, uintmax_t value)
{
	uintmax_t	tmp;
	int			size;
	char		*str;

	size = 0;
	tmp = value;
	while (tmp /= 10)
		size++;
	size = size + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[value % 10];
		size--;
		value = value / 10;
	}
	return (str);
}

char			*ft_itoa_u(uintmax_t value)
{
	char		*str;
	char		*tab;

	tab = "0123456789abcdef";
	str = itoa_fill(tab, value);
	return (str);
}
