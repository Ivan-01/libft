/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:25:40 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 15:31:10 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_bchar(int n, char c)
{
	int			i;
	char		*str;

	str = (char*)malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
