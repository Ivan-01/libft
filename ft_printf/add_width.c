/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:55:39 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:14:05 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*assign_width(t_ptf_flags *flags, char *str)
{
	char	fill;
	char	*width;

	fill = ' ';
	if (flags->zero_padding == 1 && flags->conversion == 'f')
		fill = '0';
	if (flags->zero_padding == 1 && flags->precision == 0 && \
			flags->conversion != 'p')
		fill = '0';
	if ((flags->conversion != 'x' || flags->conversion != 'X') && \
			flags->zero_padding == 1 && flags->hashtag == 1)
	{
		width = ft_bchar(flags->width - (int)ft_strlen(str) - 2, fill);
		width = ft_update(width, ft_strjoin("0x", width));
	}
	else
		width = ft_bchar(flags->width - (int)ft_strlen(str), fill);
	return (width);
}

char		*add_width(t_ptf_flags *flags, char *str)
{
	char	*width;

	if (flags->width <= (int)ft_strlen(str))
		return (str);
	width = assign_width(flags, str);
	if (flags->zero_padding == 1 && (str[0] == '+' || str[0] == '-' || \
			str[0] == ' '))
		str = ft_update(str, ft_strsub(str, 1, ft_strlen(str) - 1));
	if (flags->right_padding == 1)
		str = ft_update(str, ft_strjoin(str, width));
	if (flags->right_padding == 0)
		str = ft_update(str, ft_strjoin(width, str));
	if (flags->zero_padding == 1 && flags->minus == 1)
		str = ft_update(str, ft_strjoin("-", str));
	else if (flags->zero_padding == 1 && flags->plus == 1)
		str = ft_update(str, ft_strjoin("+", str));
	else if (flags->zero_padding == 1 && flags->space == 1)
		str = ft_update(str, ft_strjoin(" ", str));
	free(width);
	return (str);
}
