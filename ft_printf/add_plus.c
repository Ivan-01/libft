/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:49:49 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:16:15 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_plus(t_ptf_flags *flags, char *str)
{
	char	*tmp;

	if (flags->conversion != 'd' && flags->conversion != 'i' && \
		flags->conversion != 'D' && flags->conversion != 'f')
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	tmp = ft_strnew(1);
	if (flags->minus == 0)
		tmp = ft_update(tmp, ft_strjoin("+", str));
	return (tmp);
}
