# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cstannis <cstannis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 21:33:54 by cstannis          #+#    #+#              #
#    Updated: 2021/02/02 06:26:55 by cstannis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a
CC =		gcc -g
GFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
SRC =		ft_memset.c \
	  		ft_bzero.c \
	  		ft_memcpy.c \
	  		ft_memccpy.c \
	  		ft_memmove.c \
	  		ft_memchr.c \
	  		ft_memcmp.c \
	  		ft_strlen.c \
	  		ft_strlcpy.c \
	  		ft_strlcat.c \
	  		ft_strchr.c \
	  		ft_strrchr.c \
	  		ft_strnstr.c \
	  		ft_strncmp.c \
	  		ft_atoi.c \
	  		ft_isalpha.c \
	  		ft_isdigit.c \
	  		ft_isalnum.c \
	  		ft_isascii.c \
	  		ft_isprint.c \
	  		ft_toupper.c \
	  		ft_tolower.c \
	  		ft_calloc.c \
	  		ft_strdup.c \
	  		ft_substr.c \
	  		ft_strjoin.c \
	  		ft_strtrim.c \
	  		ft_split.c \
	  		ft_itoa.c \
	  		ft_strmapi.c \
	  		ft_putchar_fd.c \
	  		ft_putstr_fd.c \
	  		ft_putendl_fd.c \
	  		ft_putnbr_fd.c \
			ft_toupper_str.c \
			ft_ultoa_hex.c \
			ft_ltoa_dec.c \
			ft_nblen.c \
			ft_cmpstr.c
OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(GFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:	
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		clean fclean
