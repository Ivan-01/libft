/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_co_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:37:50 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:11:49 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*convers_co_o(va_list *arg, t_ptf_flags *flags)
{
	char		*answer;
	intmax_t	tmp;

	tmp = va_arg(*arg, uintmax_t);
	if (!ft_strcmp(flags->format, "ll"))
		tmp = (unsigned long long int)tmp;
	else if (!ft_strcmp(flags->format, "l"))
		tmp = (unsigned long int)tmp;
	else if (!ft_strcmp(flags->format, "hh"))
		tmp = (unsigned char)tmp;
	else if (!ft_strcmp(flags->format, "h"))
		tmp = (unsigned short int)tmp;
	else if (!ft_strcmp(flags->format, "j"))
		tmp = (uintmax_t)tmp;
	else if (!ft_strcmp(flags->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (unsigned int)tmp;
	answer = ft_itoa_base_u(tmp, 8);
	if (flags->hashtag == 1 && tmp != 0)
		answer = ft_update(answer, ft_strjoin("0", answer));
	return (answer);
}
