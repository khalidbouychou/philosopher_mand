# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 18:30:44 by khbouych          #+#    #+#              #
#    Updated: 2023/05/07 15:06:37 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = parsing.c philo.c utils_list.c creation.c routine.c \
check_dead.c eat_slep_think.c free.c utils.c
NAME = philo
OBJ = $(SRC:%.c=%.o)

FSANITAZE = -fsanitize=thread -g
all:$(NAME)
# -fsanitize=thread -g
$(NAME): $(OBJ)
	cc   -Wall -Werror -Wextra  $(OBJ) -o $(NAME)
%.o:%.c philo.h
	cc   -Wall -Werror -Wextra  -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf philo
re : fclean all