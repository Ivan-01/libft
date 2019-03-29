/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:42:49 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:10:02 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		prepare_float(int *sign, long double *n, t_ptf_flags *f)
{
	long double	pi;
	int			i;

	i = 0;
	pi = 0.5;
	*sign = 0;
	if (*n < 0)
	{
		*n = -(*n);
		*sign = 1;
	}
	f->precision = (f->precision_exist == 1) ? f->precision : 6;
	while (f->precision >= 0 && i++ < f->precision)
		pi /= 10;
	*n += pi;
}

static char		*ft_ftoa(long double n, t_ptf_flags *f)
{
	int			len;
	char		*dst;
	char		*dec;
	int			sign;
	int			pos;

	prepare_float(&sign, &n, f);
	dec = ft_itoa_base_ll((long long int)n, "0123456789");
	len = ft_strlen(dec);
	dst = ft_strnew(sign + len + 1 + ((f->precision > 0) ? f->precision : 0));
	pos = sign;
	ft_strcpy(dst + pos, dec);
	pos += len;
	if (f->precision > 0)
		dst[pos++] = '.';
	while (pos < len + sign + ((f->precision > 0) ? (f->precision + 1) : 0))
	{
		dst[pos++] = ((unsigned long long int)(n * 10) % 10) + '0';
		n *= 10;
	}
	if (sign)
		dst[0] = '-';
	ft_strdel(&dec);
	return (dst);
}

char			*convert_float_nbr(void *p, t_ptf_flags *f)
{
	char		*str;

	str = NULL;
	str = ft_ftoa(*(long double*)p, f);
	return (str);
}

char			*convers_f(va_list *args, t_ptf_flags *f)
{
	long double	n;

	if (!ft_strcmp(f->format, "l"))
		n = (double)va_arg(*args, double);
	else if (!ft_strcmp(f->format, "ll"))
		n = (long double)va_arg(*args, long double);
	else
		n = (double)va_arg(*args, double);
	return (convert_float_nbr((void*)&n, f));
}
