/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:11:08 by ititkov           #+#    #+#             */
/*   Updated: 2018/12/21 11:59:38 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_skip_spc(char const *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	j;
	unsigned int	k;
	char			*str;

	k = 0;
	if (!s)
		return (NULL);
	if (s[ft_skip_spc(s)] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	str = (char *)malloc(sizeof(char) * (j - ft_skip_spc(s) + 2));
	if (str == NULL)
		return (NULL);
	while (k < j - ft_skip_spc(s) + 1)
	{
		str[k] = s[ft_skip_spc(s) + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}
