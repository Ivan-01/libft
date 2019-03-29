/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width_null_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:56:58 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:13:31 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_width_null_char(t_ptf_flags *flags, char *answer, \
		int *length, char **str)
{
	char	*width;

	*length += ft_strlen(*str);
	write(1, *str, ft_strlen(*str));
	*str = ft_update(*str, ft_strnew(1));
	if (flags->width <= 1)
	{
		ft_putchar('\0');
		return (answer);
	}
	width = ft_bchar(flags->width - 1, ' ');
	*length += ft_strlen(width);
	if (flags->right_padding == 0)
	{
		write(1, width, ft_strlen(width));
		ft_putchar('\0');
	}
	else
	{
		ft_putchar('\0');
		write(1, width, ft_strlen(width));
	}
	free(width);
	return (answer);
}
