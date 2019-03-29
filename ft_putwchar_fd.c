/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:30:43 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/14 15:36:59 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putwchar_fd(wchar_t c, int fd)
{
	if (c <= 0x7F)
		ft_putchar_fd(c, fd);
	else if (c <= 0x7FF)
	{
		ft_putchar_fd((c >> 6) + 0xC0, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar_fd((c >> 12) + 0xE0, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar_fd((c >> 18) + 0xF0, fd);
		ft_putchar_fd(((c >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
}
