/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:53:28 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:15:12 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*add_precision_string(t_ptf_flags *flags, char *str)
{
	char		*tmp;

	tmp = ft_strdup(str);
	if (flags->conversion != 'S' && flags->conversion != 's')
		return (tmp);
	if (flags->precision == 0)
	{
		tmp = ft_strnew(1);
		return (tmp);
	}
	if (flags->precision >= (int)ft_strlen(str))
		return (tmp);
	tmp = ft_update(tmp, ft_strsub(str, 0, flags->precision));
	return (tmp);
}
