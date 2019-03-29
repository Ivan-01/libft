/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:37:01 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:10:46 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*convers_d_i(va_list *arg, t_ptf_flags *flags)
{
	char		*answer;
	intmax_t	tmp;

	tmp = va_arg(*arg, intmax_t);
	if (!ft_strcmp(flags->format, "ll"))
		tmp = (long long)tmp;
	else if (!ft_strcmp(flags->format, "l"))
		tmp = (long int)tmp;
	else if (!ft_strcmp(flags->format, "hh"))
		tmp = (char)tmp;
	else if (!ft_strcmp(flags->format, "h"))
		tmp = (short int)tmp;
	else if (!ft_strcmp(flags->format, "j"))
		tmp = (intmax_t)tmp;
	else if (!ft_strcmp(flags->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (int)tmp;
	answer = ft_itoa_x(tmp);
	if (answer[0] == '-')
	{
		flags->minus = 1;
		answer = ft_update(answer, ft_strsub(answer, 1, ft_strlen(answer) - 1));
	}
	return (answer);
}
