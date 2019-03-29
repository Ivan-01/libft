/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:38:32 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 14:13:16 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*convers_p(va_list *arg)
{
	char		*answer;
	intmax_t	tmp;

	answer = ft_strnew(1);
	tmp = va_arg(*arg, unsigned long);
	answer = ft_update(answer, ft_itoa_base(tmp, 16));
	answer = ft_update(answer, ft_strjoin("0x", answer));
	return (answer);
}
