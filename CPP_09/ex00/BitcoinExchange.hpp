

#ifndef BTC_EXCHANGE_HPP
# define BTC_EXCHANGE_HPP

#include "BitcoinRateLoader.hpp"
#include <iostream>

#define	ERR_USAGE			"Error: This program requires exactly one argument."

#define RED  "\033[31m"
#define GREEN  "\033[32m"
#define RESET  "\033[0m"

int	fetch_bitcoin_value(const std::string & input_file);


#endif