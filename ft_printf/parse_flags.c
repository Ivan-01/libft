/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:25:46 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:01:43 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_flags(char **format, t_ptf_flags *flags, va_list *arg)
{
	if ((deal_flags(format, flags)) == NULL)
		return (-1);
	if ((deal_width(format, flags, arg)) == NULL)
		return (-1);
	if ((deal_precision(format, flags, arg)) == NULL)
		return (-1);
	if ((deal_format(format, flags)) == NULL)
		return (-1);
	flags->conversion = (**format);
	if (!ft_strcmp(flags->format, "l") && (**format) == 'c')
		flags->conversion = 'C';
	if (!ft_strcmp(flags->format, "l") && (**format) == 's')
		flags->conversion = 'S';
	return (1);
}
