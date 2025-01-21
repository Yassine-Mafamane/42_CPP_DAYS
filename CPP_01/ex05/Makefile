# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 01:58:07 by ymafaman          #+#    #+#              #
#    Updated: 2024/05/29 02:25:27 by ymafaman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++

CPP_FILES = main.cpp Harl.cpp

O_FILES = $(CPP_FILES:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Harl

all : $(NAME)

$(NAME) : $(O_FILES)
	$(CPP) $(FLAGS) $(O_FILES) -o $(NAME)

%.o : %.cpp Harl.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(O_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
	