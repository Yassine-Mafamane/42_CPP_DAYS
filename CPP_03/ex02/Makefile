# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 01:49:45 by ymafaman          #+#    #+#              #
#    Updated: 2024/07/20 03:10:39 by ymafaman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

CPP_FILES = main.cpp ClapTrap.cpp FragTrap.cpp

OBJ_FILES = $(CPP_FILES:.cpp=.o)

NAME = ClapTrap

all : $(NAME)

$(NAME) : $(OBJ_FILES)
		$(CPP) $(FLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.cpp ClapTrap.hpp FragTrap.hpp
		$(CPP) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ_FILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean