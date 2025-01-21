
#include "DateInfo.hpp"

ushort	DateInfo::LineNum = 0;

DateInfo::DateInfo()
{}

DateInfo::DateInfo(std::string & year, std::string & month, std::string & day)
	try
	: _year(DateInfo::validate_year(year))
	, _month(DateInfo::validate_month(month))
	, _day(DateInfo::validate_day(day, _year, _month))
	{}
	catch (const char * e)
	{
		throw ;
	}

DateInfo::DateInfo(const DateInfo & ref)
{
	this->_year = ref._year;
	this->_month = ref._month;
	this->_day = ref._day;
}

DateInfo::~DateInfo()
{

}

ushort	DateInfo::get_year() const
{
	return this->_year;
}

ushort	DateInfo::get_month() const
{
	return this->_month;
}

ushort	DateInfo::get_day() const
{
	return this->_day;
}

DateInfo&	DateInfo::operator=(const DateInfo & rhs)
{
	if (this == &rhs)
		return *this;

	this->_year = rhs._year;
	this->_month = rhs._month;
	this->_day = rhs._day;

	return *this;
}

bool	operator==( const DateInfo & lhs, const DateInfo & rhs )
{
	return ((lhs.get_year() == rhs.get_year())
			&& (lhs.get_month() == rhs.get_month())
			&& (lhs.get_day() == rhs.get_day()));
}

bool	operator<(const DateInfo & lhs, const DateInfo & rhs)
{
	return ((lhs.get_year() < rhs.get_year())
			|| (lhs.get_year() == rhs.get_year() && lhs.get_month() < rhs.get_month())
			|| (lhs.get_year() == rhs.get_year() && lhs.get_month() == rhs.get_month() && lhs.get_day() < rhs.get_day()));
}

bool	operator>(const DateInfo & lhs, const DateInfo & rhs)
{
	return ((lhs.get_year() > rhs.get_year())
			|| (lhs.get_year() == rhs.get_year() && lhs.get_month() > rhs.get_month())
			|| (lhs.get_year() == rhs.get_year() && lhs.get_month() == rhs.get_month() && lhs.get_day() > rhs.get_day()));
}

void	DateInfo::show( void ) const
{
	std::cout << _year << '-';

	if (_month < 10)
		std::cout << '0';
	std::cout << _month << '-';

	if (_day < 10)
		std::cout << '0';
	std::cout << _day;
}

std::string		DateInfo::getAsStr( void ) const
{
	std::stringstream	strm;

	strm << _year;
	strm << '-';

	if (_month < 10)
		strm << '0';
	strm << _month;
	strm << '-';

	if (_day < 10)
		strm << '0';
	strm << _day;

	return strm.str();
}

ushort	DateInfo::validate_year(std::string & year)
{
	std::stringstream	strm(year);
	ushort				us_year;

	strm >> us_year;
	return (us_year);
}

ushort	DateInfo::validate_month(std::string & month)
{
	std::stringstream	strm(month);
	ushort				us_month;

	strm >> us_month;

	if (us_month < 1 || us_month > 12)
	{
		strm.clear();
		strm.str("");
		strm << "Error: Invalid month value. Please enter a number between 1 and 12. Line: [";
		strm << DateInfo::LineNum;
		strm << "].";
		throw strm.str();
	}

	return (us_month);
}

ushort	DateInfo::validate_day(std::string & day, const ushort & year, const ushort & month)
{
	std::stringstream	strm(day);
	ushort				us_day;

	strm >> us_day;

	if (us_day < 1 || us_day > 31)
	{
		strm.clear();
		strm.str("");
		strm << "Error: Invalid day value. Please enter a number between 1 and 31. Line: [";
		strm << DateInfo::LineNum;
		strm << "].";
		throw strm.str();
	}

	if ((month == 2) && (us_day == 29) && !DateInfo::is_leap_year(year))
	{
		strm.clear();
		strm.str("");
		strm << "Error: Invalid day value. February 29 is not valid in a non-leap year. Line: [";
		strm << DateInfo::LineNum;
		strm << "].";
		throw strm.str();
	}
	else if ((month == 2) && (us_day > 29))
	{
		strm.clear();
		strm.str("");
		strm << "Error: Invalid day value. February cannot have more than 29 days. Line: [";
		strm << DateInfo::LineNum;
		strm << "].";
		throw strm.str();
	}
	else if ((us_day == 31) && (month == 4 || month == 6 || month == 9 || month == 11))
	{
		strm.clear();
		strm.str("");
		strm << "Error: Invalid day value. The selected month only has 30 days. Line: [";
		strm << DateInfo::LineNum;
		strm << "].";
		throw strm.str();
	}

	return (us_day);
}

bool	DateInfo::is_leap_year( const ushort & year )
{
	return ((!(year % 100) && !(year % 400))
			|| ((year % 100) && !(year % 4)));
}