/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:36:08 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:12:11 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*convers_c(va_list *arg, int *length, t_ptf_flags *flags)
{
	char	*str;
	int		tmp;

	tmp = va_arg(*arg, int);
	if (tmp == '\0')
	{
		(*length)++;
		flags->null_char = 1;
		str = ft_strnew(1);
	}
	else
		str = ft_bchar(1, (char)tmp);
	return (str);
}
