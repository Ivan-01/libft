/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:59:02 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 20:19:29 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "../libft.h"

typedef struct	s_ptf_flags
{
	int			null_char;
	int			hashtag;
	int			right_padding;
	int			minus;
	int			plus;
	int			zero_padding;
	int			width;
	int			precision;
	int			precision_exist;
	int			space;
	char		conversion;
	char		*format;
}				t_ptf_flags;

int				parse_flags(char **format, t_ptf_flags *flags, \
		va_list *arg);
char			*deal_flags(char **format, t_ptf_flags *flags);
char			*deal_format(char **format, t_ptf_flags *flags);
char			*deal_precision(char **format, t_ptf_flags *flags, \
		va_list *arg);
char			*deal_width(char **format, t_ptf_flags *flags, va_list *arg);
int				regular_character_string(char **next, t_ptf_flags *flags, \
		va_list *arg);
int				wide_character_string(char **next, t_ptf_flags *flags, \
		va_list *arg);
char			*conversions(t_ptf_flags *flags, va_list *arg, int *length, \
		char **str);
char			*convers_c(va_list *arg, int *length, t_ptf_flags *flags);
char			*convers_wide_c(va_list *arg, int *length, t_ptf_flags *flags);
char			*convers_wide_s(va_list *arg);
char			*convers_s(va_list *arg);
char			*convers_b(va_list *arg, t_ptf_flags *flags);
char			*convers_p(va_list *arg);
char			*convers_d_i(va_list *arg, t_ptf_flags *flags);
char			*convers_co_o(va_list *arg, t_ptf_flags *flags);
char			*convers_cx_x(va_list *arg, t_ptf_flags *flags);
char			*convers_cu_cd_u(va_list *arg, t_ptf_flags *flags);
char			*add_width(t_ptf_flags *flags, char *str);
int				add_width_wide(t_ptf_flags *flags, int length_str);
char			*add_width_null_char(t_ptf_flags *flags, char *answer, \
		int *length, char **str);
char			*add_plus(t_ptf_flags *flags, char *str);
char			*add_space(t_ptf_flags *flags, char *str);
char			*add_minus(t_ptf_flags *flags, char *str);
char			*add_precision_string(t_ptf_flags *flags, char *str);
char			*add_precision_number(t_ptf_flags *flags, char *str);
int				ft_printf(const char *restrict format, ...);
int				print_wide_str(wchar_t *str);
char			*ft_itoa_x(long long value);
char			*ft_itoa_u(uintmax_t value);
char			*ft_itoa_base_u(uintmax_t value, int base);
char			*convers_f(va_list *args, t_ptf_flags *f);
char			*ft_itoa_base_ll(long long int n, char *base);

#endif
