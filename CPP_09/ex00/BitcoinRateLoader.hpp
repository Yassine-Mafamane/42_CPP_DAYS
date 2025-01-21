
#ifndef BTC_RATE_LOADER_HPP
# define BTC_RATE_LOADER_HPP

#include <map>
#include <fstream>
#include <sstream>
#include "DateInfo.hpp"
#include "FileTokenizer.hpp"

class BitcoinRateLoader
{
	public :
		BitcoinRateLoader( const char & separator );
		~BitcoinRateLoader();

		static std::map<DateInfo, double>	load_data( const std::string & file_name );
		std::pair<DateInfo, double>			extract_info( std::list<t_token_info> & data_tokens );
		static void							remove_current_line_tokens( std::list<t_token_info> & data_tokens );
		void								check_first_line( std::list<t_token_info> & data_tokens );

	private :

		BitcoinRateLoader();
		BitcoinRateLoader( const BitcoinRateLoader& ref );

		std::map<DateInfo, double>			store_data( std::list<t_token_info> & data_tokens );
		void								parse_token( t_token_info & info );
		static void							missing_token( const token_type & t, ushort & line_num, const char & separator );
		static void							bad_token( t_token_info & info, const char & separator );
		static void							unexpected_token( t_token_info & info );
		static bool							is_num( const std::string & token, const bool & sign_allowed );
		void								save_token( t_token_info & info );
		std::pair<DateInfo, double>			build_info( ushort & line_num );

		char		separator;

		std::string	year;
		std::string	month;
		std::string	day;
		std::string	rate;
};



#endif