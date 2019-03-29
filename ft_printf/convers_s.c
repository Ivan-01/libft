/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:39:17 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 14:07:30 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*convers_s(va_list *arg)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(*arg, char *);
	if (tmp == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(tmp);
	return (str);
}
