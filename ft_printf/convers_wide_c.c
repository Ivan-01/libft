/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_wide_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:44:35 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:09:14 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*convers_wide_c(va_list *arg, int *length, t_ptf_flags *flags)
{
	wchar_t		tmp_chr;
	char		chr;
	char		*str;

	tmp_chr = va_arg(*arg, wint_t);
	chr = (char)tmp_chr;
	if (chr == '\0')
	{
		(*length)++;
		flags->null_char = 1;
		str = ft_strnew(1);
	}
	else
		str = ft_bchar(1, chr);
	return (str);
}
