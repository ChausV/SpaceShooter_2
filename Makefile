#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaus <vchaus@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 16:27:48 by vchaus            #+#    #+#              #
#    Updated: 2018/10/06 16:27:49 by vchaus           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro
CC = clang++
FLAGS = -Wall -Wextra -Werror
SRC = 	main.cpp \
		$(CLASS_HEAD:.hpp=.cpp)
CLASS_HEAD = 	Coordinates.hpp \
				SpaceObject.hpp \
				Ship.hpp \
				SpaceField.hpp \
				Enemy.hpp \
				Bullet.hpp
OBJ = $(SRC:.cpp=.o)
NCURSES = -lncurses


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(NCURSES) $(OBJ)

# %.o: %.cpp %.hpp $(HEAD)
# 	$(CC) -c $(FLAGS) $<

%.o: %.cpp $(CLASS_HEAD)
	$(CC) -c $(FLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
