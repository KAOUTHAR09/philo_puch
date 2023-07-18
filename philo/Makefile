# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 12:21:16 by kkouaz            #+#    #+#              #
#    Updated: 2023/07/18 11:52:29 by kkouaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = philo
CC = cc
RM  = rm -rf
CFLAGS = -Wall -Wextra -Werror  -pthread
SRC = main.c parse.c tools.c  routines.c philo.c tools2.c philosophers.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

