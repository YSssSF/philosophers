# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 17:52:57 by yel-aoun          #+#    #+#              #
#    Updated: 2022/06/26 14:56:11 by yel-aoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philosopher.c src/manage_errors.c src/ft_atoi.c src/help_philo.c

CC = gcc -Wall -Wextra -Werror

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re