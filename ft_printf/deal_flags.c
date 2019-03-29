/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:27:17 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:06:56 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*deal_flags(char **format, t_ptf_flags *flags)
{
	while (**format == '#' || **format == ' ' || **format == '+' || \
			**format == '-' || **format == '0')
	{
		if (**format == '#')
			flags->hashtag = 1;
		if (**format == '-')
			flags->right_padding = 1;
		if (**format == ' ')
			flags->space = 1;
		if (**format == '+')
			flags->plus = 1;
		if (**format == '0')
			flags->zero_padding = 1;
		if (flags->right_padding == 1)
			flags->zero_padding = 0;
		(*format)++;
	}
	return (*format);
}
