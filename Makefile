# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rklein <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 09:51:37 by rklein            #+#    #+#              #
#    Updated: 2020/01/24 14:07:53 by rklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRC = src/ft_printf.c src/ft_misc.c src/ft_base_print.c \
	  src/ft_char_print.c src/ft_double_print.c src/ft_e_print.c \
	  src/ft_g_print.c src/ft_int_print.c src/ft_uint_print.c \
	  src/ft_double_flags.c src/ft_int_flags.c src/ft_uint_flags.c

LIB = libft/ft_atoi.c libft/ft_isdigit.c libft/ft_putstr.c \
	  libft/ft_strclr.c libft/ft_strcmp.c libft/ft_strdup.c \
	  libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strnew.c \
	  libft/ft_strsub.c libft/ft_toupper.c

OBJ = ft_printf.o ft_misc.o ft_base_print.o ft_char_print.o ft_double_print.o \
	  ft_e_print.o ft_g_print.o ft_int_print.o ft_uint_print.o \
	  ft_double_flags.o ft_int_flags.o ft_uint_flags.o ft_atoi.o ft_isdigit.o \
	  ft_putstr.o ft_strclr.o ft_strcmp.o ft_strdup.o ft_strjoin.o \
	  ft_strlen.o ft_strnew.o ft_strsub.o ft_toupper.o

INC = ./

all: $(NAME)
$(NAME):
	gcc $(FLAGS) $(SRC) $(LIB) -I $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(OBFLIB)

fclean: clean
	rm -f $(NAME)

re: fclean all
