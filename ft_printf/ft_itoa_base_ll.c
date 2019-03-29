/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:50:30 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 11:22:22 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char						*ft_itoa_base_ll(long long int n, char *base)
{
	unsigned long long int	nbr;
	int						len;
	int						base_len;
	char					*str;

	base_len = ft_strlen(base);
	nbr = (unsigned long long int)n;
	nbr = n < 0 ? -nbr : nbr;
	len = 2;
	while (nbr /= base_len)
		len++;
	nbr = (unsigned long long int)n;
	nbr = n < 0 ? -nbr : nbr;
	len += n < 0;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len-- > 0)
	{
		str[len] = base[nbr % base_len];
		nbr /= base_len;
	}
	str[0] = n < 0 ? '-' : str[0];
	return (str);
}
