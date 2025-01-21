
#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage : ./PergeMe N1 N2 ... Nn" << std::endl;
		return 1;
	}

	return PergeMe(argv + 1, argc - 1);
}