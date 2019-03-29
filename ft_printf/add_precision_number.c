/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:51:04 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:15:50 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*create_precision_string(t_ptf_flags *flags, char *str)
{
	int		i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * flags->precision + 1);
	i = 0;
	while (i < (flags->precision - (int)ft_strlen(str)))
		tmp[i++] = '0';
	while (*str)
	{
		tmp[i++] = *str;
		++str;
	}
	tmp[i] = '\0';
	return (tmp);
}

char		*add_precision_number(t_ptf_flags *flags, char *str)
{
	char	*tmp;

	tmp = ft_strnew(1);
	if (flags->conversion != 'd' && flags->conversion != 'i' && \
		flags->conversion != 'U' && flags->conversion != 'u' && \
		flags->conversion != 'D' && flags->conversion != 'X' && \
		flags->conversion != 'o' && flags->conversion != 'x' && \
		flags->conversion != 'O')
	{
		tmp = ft_update(tmp, ft_strdup(str));
		return (tmp);
	}
	if (!((flags->conversion == 'o' || flags->conversion == 'O') && \
		flags->hashtag == 1))
		if (flags->precision == 0 && !ft_strcmp(str, "0"))
			return (tmp);
	if (flags->precision <= (int)ft_strlen(str))
	{
		tmp = ft_update(tmp, ft_strdup(str));
		return (tmp);
	}
	tmp = ft_update(tmp, create_precision_string(flags, str));
	return (tmp);
}
