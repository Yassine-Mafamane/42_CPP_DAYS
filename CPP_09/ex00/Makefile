CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

CPP_FILES = BitcoinRateLoader.cpp DateInfo.cpp FileTokenizer.cpp main.cpp BitcoinExchange.cpp

OBJ_FILES = $(CPP_FILES:.cpp=.o)

NAME = btc

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CPP) $(FLAGS) $(OBJ_FILES) -o $(NAME)

%.o : %.cpp BitcoinExchange.hpp BitcoinRateLoader.hpp DateInfo.hpp FileTokenizer.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_FILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean