
#include "PmergeMe.hpp"


static void	show_numbers(char *args[], size_t size, const std::vector<int> & result)
{
	std::cout << "Before:	";

	for (size_t i = 0; i < size; i++)
		std::cout << args[i] << " ";

	std::cout << std::endl << "After:	";

	for (size_t i = 0; i < result.size(); i++)
			std::cout << result[i] << " ";

	std::cout << std::endl;
}

static void	check_result(const std::vector<int> & vector_result, const std::deque<int> & deque_result)
{
	if (vector_result.size() != deque_result.size())
		throw std::runtime_error("Different sizes!");

	for (size_t i = 0; i < vector_result.size(); i++)
	{
		if (vector_result[i] != deque_result[i])
			throw std::runtime_error("Different values!");
	}
}

int	PergeMe(char *args[], size_t size)
{
	VectorSorter	vec_sorter;
	DequeSorter		deq_sorter;

	std::vector<int>	vector_result;
	std::deque<int>		deque_result;	

	try
	{
		vector_result = vec_sorter.sort(args, size);
		deque_result = deq_sorter.sort(args, size);
		check_result(vector_result, deque_result);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	show_numbers(args, size, vector_result);

	std::cout << "Time to process a range of " << size << " elements with std::vector : " << std::fixed << std::setprecision(5) << vec_sorter.get_elapsed_time() << " us" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::deque : " << std::fixed << std::setprecision(5) << deq_sorter.get_elapsed_time() << " us" << std::endl;

	return 0;
}	