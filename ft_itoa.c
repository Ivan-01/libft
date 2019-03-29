/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:19:29 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 15:48:32 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_make_str(char *str, int n)
{
	char	*tmp1;
	char	*tmp2;

	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		tmp1 = ft_itoa(-n);
		str = ft_update(str, ft_strjoin(str, tmp1));
		free(tmp1);
	}
	else if (n >= 10)
	{
		tmp1 = ft_itoa(n / 10);
		tmp2 = ft_itoa(n % 10);
		str = ft_update(str, ft_strjoin(tmp1, tmp2));
		free(tmp1);
		free(tmp2);
	}
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	return (str);
}
