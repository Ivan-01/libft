/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:32:18 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:08:31 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

char		*apply_flags(char *answer, t_ptf_flags *flags, int *length, \
		char **str)
{
	if (flags->precision_exist != 0 && flags->null_char == 0)
	{
		answer = ft_update(answer, add_precision_string(flags, answer));
		answer = ft_update(answer, add_precision_number(flags, answer));
	}
	if (flags->minus == 1)
		answer = ft_update(answer, add_minus(flags, answer));
	else if (flags->plus == 1)
		answer = ft_update(answer, add_plus(flags, answer));
	else if (flags->space == 1)
		answer = ft_update(answer, add_space(flags, answer));
	if (flags->width != 0 && flags->null_char == 0)
		answer = add_width(flags, answer);
	if (flags->null_char == 1)
		answer = add_width_null_char(flags, answer, length, str);
	return (answer);
}

char		*convers_extra(t_ptf_flags *flags, va_list *arg, char *answer)
{
	if (flags->conversion == 'f')
		answer = ft_update(answer, convers_f(arg, flags));
	if (flags->conversion == 'b')
		answer = ft_update(answer, convers_b(arg, flags));
	if (flags->conversion == '%')
		answer = ft_update(answer, ft_bchar(1, '%'));
	return (answer);
}

char		*conversions(t_ptf_flags *flags, va_list *arg, int *length, \
		char **str)
{
	char	*answer;

	answer = ft_strnew(1);
	if (flags->conversion == 'C')
		answer = ft_update(answer, convers_wide_c(arg, length, flags));
	if (flags->conversion == 'S')
		answer = ft_update(answer, convers_wide_s(arg));
	if (flags->conversion == 's')
		answer = ft_update(answer, convers_s(arg));
	if (flags->conversion == 'c')
		answer = ft_update(answer, convers_c(arg, length, flags));
	if (flags->conversion == 'i' || flags->conversion == 'd')
		answer = ft_update(answer, convers_d_i(arg, flags));
	if (flags->conversion == 'p')
		answer = ft_update(answer, convers_p(arg));
	if (flags->conversion == 'D' || flags->conversion == 'u' || \
			flags->conversion == 'U')
		answer = ft_update(answer, convers_cu_cd_u(arg, flags));
	if (flags->conversion == 'o' || flags->conversion == 'O')
		answer = ft_update(answer, convers_co_o(arg, flags));
	if (flags->conversion == 'x' || flags->conversion == 'X')
		answer = ft_update(answer, convers_cx_x(arg, flags));
	answer = convers_extra(flags, arg, answer);
	answer = apply_flags(answer, flags, length, str);
	return (answer);
}
