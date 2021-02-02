# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cstannis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/31 04:07:16 by cstannis          #+#    #+#              #
#    Updated: 2021/01/31 04:08:50 by cstannis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= 	gcc

CFLAGS 		= 	-Wall -Wextra -Werror

NAME		= 	libftprintf.a

LIBFT		= 	libft/libft.a

SRC_PATH 	= 	src/

HEADER_FILE	= 	$(SRC_PATH)ft_printf.h

SRC 		=	ft_printf.c \
			  	ft_set_list.c \
				ft_type.c \
				ft_type_d.c \
				ft_type_u.c \
				ft_type_x.c \
				ft_type_s.c \
				ft_type_c.c \
				ft_type_p.c \
				ft_fill_utils.c

SRC_OBJ 	:= 	$(SRC:%.c=$(SRC_PATH)%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(SRC_OBJ)
	cp $< $@
	ar cr $@ $(SRC_OBJ)

%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	make fclean -C libft
	rm -f $(SRC_OBJ) 

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
