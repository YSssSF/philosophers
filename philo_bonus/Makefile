# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 17:52:57 by yel-aoun          #+#    #+#              #
#    Updated: 2022/07/04 15:03:25 by yel-aoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BONUS = philo_bonus

SRC_B = philosopher_bonus.c src_bonus/ft_atoi.c src_bonus/help_philo_bonus.c \
	src_bonus/manage_errors.c src_bonus/utils_philo_bonus.c

CC = cc -Wall -Wextra -Werror

FLAGS = -Wall -Wextra -Werror

OBJ_BONUS = $(SRC_B:.c=.o)

all : $(NAME_BONUS)
$(NAME_BONUS) : $(OBJ_BONUS)
		$(CC) $(FLAGS) $(SRC_B) -o $(NAME_BONUS)
		
clean :
	rm -f $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re