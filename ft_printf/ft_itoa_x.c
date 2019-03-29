/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:05:36 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 14:11:09 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_mod(long long nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static char			*itoa_fill(char *tab, long long value, int flag)
{
	long long		tmp;
	int				size;
	char			*str;

	size = 0;
	tmp = ft_mod(value);
	while (tmp /= 10)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_mod(value % 10)];
		size--;
		value = value / 10;
	}
	return (str);
}

char				*ft_itoa_x(long long value)
{
	char			*str;
	char			*tab;
	int				flag;

	flag = 0;
	tab = "0123456789abcdef";
	if (value < 0)
		flag = 1;
	str = itoa_fill(tab, value, flag);
	return (str);
}
