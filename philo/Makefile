# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 18:30:44 by khbouych          #+#    #+#              #
#    Updated: 2023/04/22 00:18:57 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = parsing.c philo.c utils_list.c creation.c routine.c \
check_dead.c eat_slep_think.c free.c utils.c
OBJ = $(SRC:%.c=%.o)
NAME = philo
all:$(NAME)

$(NAME): $(OBJ)
	cc  -Wall -Werror -Wextra $(OBJ) -o $(NAME)
%.o:%.c phlilo.h
	cc  -Wall -Werror -Wextra -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf philo
re : fclean all