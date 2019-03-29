/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_minus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:48:53 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:16:41 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_minus(t_ptf_flags *flags, char *str)
{
	char	*tmp;

	if (flags->conversion != 'd' && flags->conversion != 'i' && \
			flags->conversion != 'D')
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	tmp = ft_strnew(1);
	tmp = ft_update(tmp, ft_strjoin("-", str));
	return (tmp);
}
