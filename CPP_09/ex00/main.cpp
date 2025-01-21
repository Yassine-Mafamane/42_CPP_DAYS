
#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << ERR_USAGE << std::endl;
		return 1;
	}
	
	try
	{
		fetch_bitcoin_value(av[1]);
	}
	catch(const std::string & err)
	{
		std::cerr << RED << err << '\n';
		return 1;
	}

	return 0;
}
