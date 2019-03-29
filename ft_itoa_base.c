/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:33:09 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 15:51:50 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t		ft_mod(intmax_t nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static char			*itoa_fill(char *tab, intmax_t value, int base, int flag)
{
	uintmax_t		tmp;
	int				size;
	char			*str;

	size = 0;
	tmp = ft_mod(value);
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_mod(value % base)];
		size--;
		value = value / base;
	}
	return (str);
}

char				*ft_itoa_base(intmax_t value, int base)
{
	char			*str;
	char			*tab;
	int				flag;

	flag = 0;
	tab = "0123456789abcdef";
	if (value < 0 && base == 10)
		flag = 1;
	str = itoa_fill(tab, value, base, flag);
	return (str);
}
