# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ititkov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 21:08:09 by ititkov           #+#    #+#              #
#    Updated: 2019/03/25 16:16:00 by ititkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCCW = gcc -Wall -Werror -Wextra
FILES = ./ft_atoi.c \
		./ft_bzero.c \
		./ft_funintarr.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_itoa.c \
		./ft_itoa_base.c \
		./ft_lstadd.c \
		./ft_lstdel.c \
		./ft_lstdelone.c \
		./ft_lstiter.c \
		./ft_lstmap.c \
		./ft_lstnew.c \
		./ft_memalloc.c \
		./ft_memccpy.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memdel.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_numevenodd.c \
		./ft_numposneg.c \
		./ft_putchar.c \
		./ft_putchar_fd.c \
		./ft_putendl.c \
		./ft_putendl_fd.c \
		./ft_putintarr.c \
		./ft_putnbr.c \
		./ft_putnbr_fd.c \
		./ft_putstr.c \
		./ft_putstr_fd.c \
		./ft_strcat.c \
		./ft_strchr.c \
		./ft_strclr.c \
		./ft_strcmp.c \
		./ft_strcpy.c \
		./ft_strdel.c \
		./ft_strdup.c \
		./ft_strequ.c \
		./ft_striter.c \
		./ft_striteri.c \
		./ft_strjoin.c \
		./ft_strlcat.c \
		./ft_strlen.c \
		./ft_strmap.c \
		./ft_strmapi.c \
		./ft_strncat.c \
		./ft_strncmp.c \
		./ft_strnequ.c \
		./ft_strnew.c \
		./ft_strnstr.c \
		./ft_strrchr.c \
		./ft_strsplit.c \
		./ft_strstr.c \
		./ft_strsub.c \
		./ft_strtrim.c \
		./ft_swapintarr.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./get_next_line.c \
		./ft_bchar.c \
		./ft_putwchar.c \
		./ft_putwchar_fd.c \
		./ft_strccrt.c \
		./ft_strtolower.c \
		./ft_strtoupper.c \
		./ft_wstrdup.c \
		./ft_wstrlen.c \
		./ft_update.c \
		./ft_printf/add_minus.c \
		./ft_printf/add_plus.c \
		./ft_printf/add_precision_number.c \
		./ft_printf/add_precision_string.c \
		./ft_printf/add_space.c \
		./ft_printf/add_width.c \
		./ft_printf/add_width_null_char.c \
		./ft_printf/convers_b.c \
		./ft_printf/convers_c.c \
		./ft_printf/convers_co_o.c \
		./ft_printf/convers_cu_cd_u.c \
		./ft_printf/convers_cx_x.c \
		./ft_printf/convers_d_i.c \
		./ft_printf/convers_f.c \
		./ft_printf/convers_p.c \
		./ft_printf/convers_s.c \
		./ft_printf/convers_wide_c.c \
		./ft_printf/convers_wide_s.c \
		./ft_printf/conversions.c \
		./ft_printf/deal_flags.c \
		./ft_printf/deal_format.c \
		./ft_printf/deal_precision.c \
		./ft_printf/deal_width.c \
		./ft_printf/ft_itoa_base_ll.c \
		./ft_printf/ft_itoa_base_u.c \
		./ft_printf/ft_itoa_u.c \
		./ft_printf/ft_itoa_x.c \
		./ft_printf/ft_printf.c \
		./ft_printf/parse_flags.c \
		./ft_printf/print_wide_str.c \

OBJ =	./ft_atoi.o \
		./ft_bzero.o \
		./ft_funintarr.o \
		./ft_isalnum.o \
		./ft_isalpha.o \
		./ft_isascii.o \
		./ft_isdigit.o \
		./ft_isprint.o \
		./ft_itoa.o \
		./ft_itoa_base.o \
		./ft_lstadd.o \
		./ft_lstdel.o \
		./ft_lstdelone.o \
		./ft_lstiter.o \
		./ft_lstmap.o \
		./ft_lstnew.o \
		./ft_memalloc.o \
		./ft_memccpy.o \
		./ft_memchr.o \
		./ft_memcmp.o \
		./ft_memcpy.o \
		./ft_memdel.o \
		./ft_memmove.o \
		./ft_memset.o \
		./ft_numevenodd.o \
		./ft_numposneg.o \
		./ft_putchar.o \
		./ft_putchar_fd.o \
		./ft_putendl.o \
		./ft_putendl_fd.o \
		./ft_putintarr.o \
		./ft_putnbr.o \
		./ft_putnbr_fd.o \
		./ft_putstr.o \
		./ft_putstr_fd.o \
		./ft_strcat.o \
		./ft_strchr.o \
		./ft_strclr.o \
		./ft_strcmp.o \
		./ft_strcpy.o \
		./ft_strdel.o \
		./ft_strdup.o \
		./ft_strequ.o \
		./ft_striter.o \
		./ft_striteri.o \
		./ft_strjoin.o \
		./ft_strlcat.o \
		./ft_strlen.o \
		./ft_strmap.o \
		./ft_strmapi.o \
		./ft_strncat.o \
		./ft_strncmp.o \
		./ft_strnequ.o \
		./ft_strnew.o \
		./ft_strnstr.o \
		./ft_strrchr.o \
		./ft_strsplit.o \
		./ft_strstr.o \
		./ft_strsub.o \
		./ft_strtrim.o \
		./ft_swapintarr.o \
		./ft_tolower.o \
		./ft_toupper.o \
		./get_next_line.o \
		./ft_bchar.o \
		./ft_putwchar.o \
		./ft_putwchar_fd.o \
		./ft_strccrt.o \
		./ft_strtolower.o \
		./ft_strtoupper.o \
		./ft_wstrdup.o \
		./ft_wstrlen.o \
		./ft_update.o \
		./add_minus.o \
		./add_plus.o \
		./add_precision_number.o \
		./add_precision_string.o \
		./add_space.o \
		./add_width.o \
		./add_width_null_char.o \
		./convers_b.o \
		./convers_c.o \
		./convers_co_o.o \
		./convers_cu_cd_u.o \
		./convers_cx_x.o \
		./convers_d_i.o \
		./convers_f.o \
		./convers_p.o \
		./convers_s.o \
		./convers_wide_c.o \
		./convers_wide_s.o \
		./conversions.o \
		./deal_flags.o \
		./deal_format.o \
		./deal_precision.o \
		./deal_width.o \
		./ft_itoa_base_ll.o \
		./ft_itoa_base_u.o \
		./ft_itoa_u.o \
		./ft_itoa_x.o \
		./ft_printf.o \
		./parse_flags.o \
		./print_wide_str.o \

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m

all: $(NAME)

$(NAME):
		@echo "$(GREEN)	Libft: Making objects for libft.a$(RESET)"
		@$(GCCW) -c $(FILES)
		@echo "$(GREEN)	Libft: Compiling libft.c$(RESET)"
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "$(BLUE)	Libft: $(NAME) is  completed$(RESET)"

clean:
		@echo "$(RED)	Libft: Deleting objects for libft.a$(RESET)"
		@/bin/rm -f $(OBJ)

fclean: clean
		@echo "$(RED)	Libft: Deleting libft.a$(RESET)"
		@/bin/rm -f $(NAME)

re: fclean all
