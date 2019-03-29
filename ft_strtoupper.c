/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:14:00 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 15:56:04 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtoupper(char *str)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new[i] = str[i] - 32;
		else
			new[i] = str[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
