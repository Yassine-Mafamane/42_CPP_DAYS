
#include "BitcoinExchange.hpp"

static std::string	build_err_message(const DateInfo & min_date, const DateInfo & target, ushort line_num)
{
	std::stringstream	strm;

	strm << "Error: No data found for target date [";
	strm << target.getAsStr();
	std::cout.flush();
	strm << "] (line : ";
	strm << line_num;
	strm << "). Earliest available date is [";
	strm << min_date.getAsStr();
	strm << "].";

	return strm.str();
}

static double	find_rate(std::map<DateInfo, double> data, const DateInfo & target, ushort line_num)
{
	std::map<DateInfo, double>::iterator it = data.lower_bound(target);

	if ((it == data.end()))
		return ((--it)->second);
	else if (it->first == target)
		return it->second;
	else if (it == data.begin())
		throw build_err_message(data.begin()->first, target, line_num);
	else
		return ((--it)->second);
}

static std::map<DateInfo, double>	get_data()
{
	std::map<DateInfo, double>	data = BitcoinRateLoader::load_data("data.csv");;

	if (data.empty())
		throw std::string("Error: The data file \"data.csv\" is empty. Please ensure the file contains valid data and try again.");
	
	return data;
}

int	fetch_bitcoin_value(const std::string & input_file)
{
	std::map<DateInfo, double>	data 			= get_data();
	std::list<t_token_info>		input_tokens	= FileTokenizer::tokenize_file(input_file, '|');

	BitcoinRateLoader	loader('|');

	loader.check_first_line(input_tokens);

	while (!input_tokens.empty())
	{
		ushort	line_number = input_tokens.front().line_num;
		try
		{
			std::pair<DateInfo, double>	info = loader.extract_info(input_tokens);
			double	rate = find_rate(data, info.first, line_number);

			std::cout << GREEN << info.first.getAsStr() << " => " << info.second << " = " << info.second * rate << RESET << std::endl;
		}
		catch(const std::string & err)
		{
			std::cerr << RED << err << RESET << '\n';
			BitcoinRateLoader::remove_current_line_tokens(input_tokens);
		}
	}
	return 0;
}
