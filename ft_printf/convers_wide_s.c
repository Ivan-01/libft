/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_wide_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:45:26 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 14:40:59 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*convers_wide_s(va_list *arg)
{
	wchar_t		*tmp_str;
	char		*str;

	tmp_str = va_arg(*arg, wchar_t *);
	str = ft_wstrdup(tmp_str);
	return (str);
}
