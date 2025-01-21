#include "RPN.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Usage ./RPN \"<expression>\"";
		return 1;
	}

	try
	{
		std::cout << RPNCalculator::calculate(static_cast<std::string>(av[1])) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	return 0;
}