CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

CPP_FILES = main.cpp VectorSorter.cpp DequeSorter.cpp PmergeMe.cpp

OBJ_FILES = $(CPP_FILES:.cpp=.o)

NAME = PmergeMe

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CPP) $(FLAGS) $(OBJ_FILES) -o $(NAME)

%.o : %.cpp VectorSorter.hpp DequeSorter.hpp PmergeMe.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_FILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean