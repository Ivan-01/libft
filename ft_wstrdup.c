/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstrdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:15:36 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 15:42:18 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_wstrdup(wchar_t *s1)
{
	int		i;
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (ft_wstrlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = (char)s1[i];
		++i;
	}
	s2[i] = '\0';
	return (s2);
}
