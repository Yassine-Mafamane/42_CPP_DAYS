# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 03:50:16 by ymafaman          #+#    #+#              #
#    Updated: 2024/07/06 19:10:20 by ymafaman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++

CPP_FILES = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

O_FILES = $(CPP_FILES:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = UnnecessaryViolence

all : $(NAME)

$(NAME) : $(O_FILES)
	$(CPP) $(FLAGS) $(O_FILES) -o $(NAME)

%.o : %.cpp Weapon.hpp HumanA.hpp HumanB.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(O_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
	
	