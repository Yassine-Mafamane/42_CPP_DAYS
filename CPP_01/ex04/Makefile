# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 06:17:41 by ymafaman          #+#    #+#              #
#    Updated: 2024/05/28 06:21:16 by ymafaman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++

CPP_FILES = main.cpp

O_FILES = $(CPP_FILES:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = SedIsForLosers

all : $(NAME)

$(NAME) : $(O_FILES)
	$(CPP) $(FLAGS) $(O_FILES) -o $(NAME)

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(O_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
	
	