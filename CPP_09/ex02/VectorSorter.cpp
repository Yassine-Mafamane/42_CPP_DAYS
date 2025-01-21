
#include "VectorSorter.hpp"


VectorSorter::VectorSorter()
{
	odd_element = -1;
}

std::vector<int>	VectorSorter::sort(char *args[], size_t size)
{
	std::vector<int>	numbers;

	std::clock_t start = std::clock();

	for (size_t i = 0; i < size; i++)
	{
		numbers.push_back(VectorSorter::to_int(static_cast<std::string> (args[i])));
	}

	sort_vector(numbers);
	elapsed_time = (static_cast<double> (std::clock() - start) / CLOCKS_PER_SEC) * 1000000;

	return main_chain;
}


int	VectorSorter::to_int( const std::string & nb )
{
	std::stringstream	strm(nb);
	int					res;

	strm >> res;

	if (strm.fail() || !strm.eof())
		throw std::invalid_argument("Invalid input: Only numeric values are allowed.");
	else if (res < 0)
		throw std::invalid_argument("Invalid input : Only positive numbers are accepted!");
	
	return res;
}

void	VectorSorter::sort_vector( const std::vector<int> & numbers )
{
	make_pairs(numbers);
	sort_pairs();
	fill_chains();
	insert_to_main();

}

void	VectorSorter::sort_pairs()
{
	std::vector<std::pair<int, int> >::iterator	it = pairs.begin();
	std::vector<std::pair<int, int> >::iterator	end = pairs.end();

	for ( ; it != end ; it++ )
	{
		std::vector<std::pair<int, int> >::iterator	it2 = it;

		while ((it2 != pairs.begin()) && (it2->second < (it2 - 1)->second))
		{
			std::pair<int, int>	temp = *(it2 - 1);
			*(it2 - 1) = *it2;
			*it2 = temp;
			it2--;
		}
	}
}

void	VectorSorter::make_pairs(const std::vector<int> & numbers)
{
	std::pair<int, int>	pair;

	pair.first = -1;
	pair.second = -1;

	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (!(i % 2))
		{
			pair.first = numbers[i];
		}
		else
		{
			if (numbers[i] < pair.first)
			{
				pair.second = pair.first;
				pair.first = numbers[i];
			}
			else
				pair.second = numbers[i];

			pairs.push_back(pair);

			pair.first = -1;
			pair.second = -1;
		}
	}

	if (pair.first != -1)
	{
		odd_element = pair.first;
	}
}

void	VectorSorter::fill_chains()
{
	if (pairs.size())
	{
		main_chain.push_back(pairs[0].first);
		main_chain.push_back(pairs[0].second);

		std::vector<std::pair<int, int> >::iterator	it = pairs.begin();
		std::vector<std::pair<int, int> >::iterator	end = pairs.end();

		while (++it != end)
		{
			main_chain.push_back(it->second);
			pend.push_back(it->first);
		}
	}

	if (odd_element != -1)
		pend.push_back(odd_element);
}

void	VectorSorter::insert_to_main()
{
	std::vector<int>	jSequesnce = VectorSorter::generateJacobsthalSeq(pend.size());

	for (size_t i = 0; i < jSequesnce.size(); i++)
	{
		size_t j = jSequesnce[i];

		if (j > pend.size())
			break ;

		std::vector<int>::iterator	pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend[j - 1]);
		main_chain.insert(pos, pend[j - 1]);
		pend[j - 1] = -1;
		pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend[j - 2]);
		main_chain.insert(pos, pend[j - 2]);
		pend[j - 2] = -1;
	}

	for (int i = pend.size() - 1; i >= 0; i--)
	{
		if (pend[i] != -1)
		{
			std::vector<int>::iterator	pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend[i]);
			main_chain.insert(pos, pend[i]);
		}
	}
}

std::vector<int>	VectorSorter::generateJacobsthalSeq(int size)
{
	std::vector<int>	sequence;

	sequence.push_back(1);
	sequence.push_back(1);

	for (int i = 2; ; i++)
	{
		int res = sequence[i - 1] + (2 * sequence[i - 2]);
		sequence.push_back(res);

		if (res > size)
			break ;
	}
	
	sequence.erase(sequence.begin());
	sequence.erase(sequence.begin());

	return sequence;	
}


double	VectorSorter::get_elapsed_time()
{
	return elapsed_time;
}