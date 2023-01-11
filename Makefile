# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboiko <mboiko@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 18:25:45 by mboiko            #+#    #+#              #
#    Updated: 2022/10/12 15:28:56 by mboiko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST = ft_printf.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_putchar.c\
		ft_print_u.c\
		ft_print_hexadecimal.c\

OBJ = $(LIST:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	ar -rc  $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all 

.PHONY : all clean fclean re