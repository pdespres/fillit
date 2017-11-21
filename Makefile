# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdespres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 21:46:29 by pdespres          #+#    #+#              #
#    Updated: 2017/11/21 18:03:07 by pdespres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 
SRC = ft_error.c ft_memset.c ft_strjoin.c ft_strcpy.c ft_strcat.c \
	  ft_strlen.c \
	  main.c map.c utils.c algo.c load_file.c input.c
SRCO = ft_error.o ft_memset.o ft_strjoin.o ft_strcpy.o ft_strcat.o \
	  ft_strlen.o \
	  main.o map.o utils.o algo.o load_file.o input.o

$(NAME): 
	gcc -Wextra -Wall -Werror -c $(SRC)
	gcc $(SRCO) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
