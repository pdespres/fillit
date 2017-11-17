# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdespres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 21:46:29 by pdespres          #+#    #+#              #
#    Updated: 2017/11/17 18:23:15 by pdespres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 
REP1 = ./srcs/
REPH = ./includes/
SRC = ft_error.c ft_memset.c \
	  main.c map.c utils.c algo.c
SRCO = 

all: $(NAME)

$(NAME): 
	gcc -Wextra -Wall -Werror $(SRC) -o $(NAME)

clean:

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
