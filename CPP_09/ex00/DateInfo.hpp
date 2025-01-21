
#ifndef DATE_INFO_HPP
# define DATE_INFO_HPP

#include <iostream>
#include <sstream>

typedef unsigned short ushort;

class DateInfo
{
	public :

		static ushort	LineNum;

		DateInfo( std::string & year, std::string & month, std::string & day );
		DateInfo( const DateInfo & ref );

		~DateInfo();

		DateInfo&		operator=( const DateInfo & rhs );

		// Getters :
		ushort			get_year( void ) const;
		ushort			get_month( void ) const;
		ushort			get_day( void ) const;


		void			show( void ) const;
		std::string		getAsStr( void ) const;
		static ushort	validate_year( std::string & year );
		static ushort	validate_month( std::string & month );
		static ushort	validate_day( std::string & day, const ushort & year, const ushort & month );
		static bool		is_leap_year( const ushort & year );

	private :

		DateInfo();

		ushort	_year;
		ushort	_month;
		ushort	_day;
};

bool	operator<( const DateInfo & lhs, const DateInfo & rhs );
bool	operator>( const DateInfo & lhs, const DateInfo & rhs );
bool	operator==( const DateInfo & lhs, const DateInfo & rhs );
#endif