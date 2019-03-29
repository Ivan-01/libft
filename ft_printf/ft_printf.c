/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:23:50 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:04:06 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				final_print(const char *format, char *str)
{
	int			length;

	str = ft_update(str, ft_strjoin(str, format));
	write(1, str, ft_strlen(str));
	length = ft_strlen(str);
	free(str);
	return (length);
}

int				narrow_ft_printf(const char *format, va_list *arg, char *str)
{
	t_ptf_flags	flags;
	char		*next;
	char		*tmp;
	static int	length;

	if (!length)
		length = 0;
	next = ft_strchr(format, '%');
	if (next == NULL)
		return (length + final_print(format, str));
	tmp = ft_strccrt(format, '%');
	str = ft_update(str, ft_strjoin(str, tmp));
	free(tmp);
	++next;
	ft_bzero(&flags, sizeof(t_ptf_flags));
	parse_flags(&next, &flags, arg);
	tmp = conversions(&flags, arg, &length, &str);
	str = ft_update(str, ft_strjoin(str, tmp));
	++next;
	free(tmp);
	free(flags.format);
	return (narrow_ft_printf(next, arg, str));
}

int				ft_printf(const char *restrict format, ...)
{
	int			length;
	char		*str;
	va_list		arg;

	length = 0;
	str = ft_strnew(1);
	va_start(arg, format);
	length = narrow_ft_printf(format, &arg, str);
	va_end(arg);
	return (length);
}
