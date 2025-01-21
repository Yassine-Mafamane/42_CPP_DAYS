
#include "BitcoinRateLoader.hpp"

BitcoinRateLoader::BitcoinRateLoader( const char & separator ) : separator(separator)
{}

BitcoinRateLoader::~BitcoinRateLoader(){}

std::map<DateInfo, double>	BitcoinRateLoader::load_data(const std::string & file_name)
{
	std::list<t_token_info>	data_tokens = FileTokenizer::tokenize_file(file_name, ',');

	BitcoinRateLoader	loader(',');

	return	loader.store_data(data_tokens);
}

std::map<DateInfo, double>	BitcoinRateLoader::store_data(std::list<t_token_info> & data_tokens)
{
	std::map<DateInfo, double>	data;

	check_first_line(data_tokens);

	while (!data_tokens.empty())
	{
		data.insert(extract_info(data_tokens));
	}
	return data;
}

std::pair<DateInfo, double>	BitcoinRateLoader::extract_info(std::list<t_token_info> & data_tokens)
{
	t_token_info	info;
	token_type		t = static_cast<token_type> (-1);

	while (!data_tokens.empty())
	{
		t = static_cast<token_type> (static_cast<int> (t) + 1);

		if (data_tokens.front().type != t)
			BitcoinRateLoader::missing_token(t, data_tokens.front().line_num, separator);

		info = data_tokens.front();
		data_tokens.pop_front();

		parse_token(info);
		save_token(info);

		if ((t == RATE) && !data_tokens.empty() && (data_tokens.front().type != YEAR))
		{
			t_token_info	bad_token = data_tokens.front();
			BitcoinRateLoader::unexpected_token(bad_token);
		}

		if (t == RATE)
			break;
	}

	if (t != RATE)
		BitcoinRateLoader::missing_token(static_cast<token_type>(static_cast<int>(t) + 1), info.line_num, separator);

	return build_info(info.line_num);
}

void	BitcoinRateLoader::check_first_line(std::list<t_token_info> & data_tokens)
{
	if (data_tokens.size() < 3)
		throw std::string("Invalid start line!");

	ushort	line_num = data_tokens.front().line_num;

	for (int i = 0; i < 3; i++)
	{
		t_token_info	info = data_tokens.front();

		if ((i == 0) && info.token != "date")
			throw std::string("Invalid start line!");
		else if ((i == 1) && (info.token.length() != 1) && info.token[0] != separator)
			throw std::string("Invalid start line!");
		else if (i == 2)
		{
			if ((separator == ',') && info.token != "exchange_rate")
				throw std::string("Invalid start line!");
			else if ((separator == '|') && info.token != "value")
				throw std::string("Invalid start line!");
		}
		data_tokens.pop_front();
	}

	if (!data_tokens.empty() && (data_tokens.front().line_num == line_num))
		BitcoinRateLoader::unexpected_token(data_tokens.front());
}

void	BitcoinRateLoader::save_token(t_token_info & info)
{
	switch (info.type)
	{
		case YEAR :
			year = info.token;
			break;
		case MONTH :
			month = info.token;
			break;
		case DAY :
			day = info.token;
			break;
		case RATE :
			rate = info.token;
			break;
		default :
			break;
	}
}

void	BitcoinRateLoader::parse_token( t_token_info & info )
{
	if (info.type == YEAR)
	{
		if (info.token.length() != 4 || !BitcoinRateLoader::is_num(info.token, false))
			BitcoinRateLoader::bad_token(info, separator);
	}
	else if (info.type == MONTH)
	{
		if (info.token.length() < 1 || info.token.length() > 2 || !BitcoinRateLoader::is_num(info.token, false))
			BitcoinRateLoader::bad_token(info, separator);
	}
	else if (info.type == DAY)
	{
		if (info.token.length() < 1 || info.token.length() > 2 || !BitcoinRateLoader::is_num(info.token, false))
			BitcoinRateLoader::bad_token(info, separator);
	}
	else if (info.type == SEPARATOR1 || info.type == SEPARATOR2)
	{
		if (info.token != "-")
			BitcoinRateLoader::bad_token(info, separator);
	}
	else if (info.type == SEPARATOR3)
	{
		if ((info.token.length() != 1) || (info.token[0] != separator))
			BitcoinRateLoader::bad_token(info, separator);
	}
	else if (info.type == RATE)
	{
		if (!BitcoinRateLoader::is_num(info.token, true))
			BitcoinRateLoader::bad_token(info, separator);
	}
}

void	BitcoinRateLoader::missing_token(const token_type & t, ushort & line_num, const char & separator)
{
	std::stringstream	err;

	switch (t)
	{
		case YEAR:
		case MONTH :
		case DAY :
			err << "Error: Invalid date format on line ";
			err << line_num;
			err << ". Use 'YYYY-MM-DD'.";
			break;
		case SEPARATOR1 :
		case SEPARATOR2 :
			err << "Error: Missing hyphen in date on line ";
			err << line_num;
			err << ". Use 'YYYY-MM-DD'";
			break;
		case SEPARATOR3 :
			err << "Error: Missing separator '";
			err << separator;
			err << "' on line ";
			err << line_num;
			err << ". Expected format: 'YYYY-MM-DD ";
			err << separator;
			err << " exchange_rate'.";
			break;
		case RATE :
			err << "Error: Missing rate on line ";
			err << line_num;
			err << ". Expected format: 'YYYY-MM-DD ";
			err << separator;
			err <<  " exchange_rate'.";
			break;
	}
	throw err.str();
}

void	BitcoinRateLoader::bad_token(t_token_info & info, const char & separator)
{
	std::stringstream	err;

	switch (info.type)
	{
		case YEAR:
			err << "Error: Invalid year \"";
			err << info.token;
			err << "\" on line ";
			err << info.line_num;
			err << ". Must be numeric 'YYYY'.";
			break;
		case MONTH :
			err << "Error: Invalid month \"";
			err << info.token;
			err << "\" on line ";
			err << info.line_num;
			err << ". Must be numeric 'MM'.";
			break;
		case DAY :
			err << "Error: Invalid day \"";
			err << info.token;
			err << "\" on line ";
			err << info.line_num;
			err << ". Must be numeric 'DD'.";
			break;
		case SEPARATOR1 :
		case SEPARATOR2 :
		case SEPARATOR3 :
			BitcoinRateLoader::missing_token(info.type, info.line_num, separator);
			BitcoinRateLoader::missing_token(info.type, info.line_num, separator);
			break;
		case RATE :
			err << "Error: Invalid rate \"";
			err << info.token;
			err << "\" on line ";
			err << info.line_num;
			err << ". Must be numeric.";
			break;
	}
	throw err.str();
}

void	BitcoinRateLoader::unexpected_token(t_token_info & info)
{
	std::stringstream	err;

	err << "Unexpected token \"";
	err << info.token;
	err << "\" on line ";
	err << info.line_num;
	err << ".";

	throw err.str();
}

void	BitcoinRateLoader::remove_current_line_tokens(std::list<t_token_info> & data_tokens)
{
	while (!data_tokens.empty() && data_tokens.front().type != YEAR)
	{
		data_tokens.pop_front();
	}
}

bool	BitcoinRateLoader::is_num(const std::string & token, const bool & sign_allowed)
{
	size_t	i = 0;
	bool	decimal_point_found = false;

	if (sign_allowed && (token[i] == '-' || token[i] == '+'))
	{
		if (token.length() == 1)
			return false;
		i++;
	}

	for ( ; i < token.length(); i++)
	{
		if ((token[i] < '0' || token[i] > '9') && ((token[i] != '.') || (token[i] == '.' && decimal_point_found)))
			return false;
		if (token[i] == '.')
			decimal_point_found = true;
	}

	return true;
}

std::pair<DateInfo, double>	BitcoinRateLoader::build_info( ushort & line_num )
{
	DateInfo::LineNum = line_num;
	DateInfo			date(year, month, day);
	std::stringstream	strm(rate);

	double	d_rate;

	strm >> d_rate;

	if (strm.fail() || d_rate > INT_MAX || (separator == '|' && d_rate > 1000))
	{
		strm.clear();
		strm.str("");
		strm << "Error: The provided value is too large. Line: [";
		strm << line_num;
		strm << "].";
		throw strm.str();
	}

	if (d_rate < 0)
	{
		strm.clear();
		strm.str("");
		strm << "Error: Negative values are not allowed. Line: [";
		strm << line_num;
		strm << "].";
		throw strm.str();
	}

	return std::make_pair(date, d_rate);
}