/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:48:36 by ymafaman          #+#    #+#             */
/*   Updated: 2024/12/13 02:41:49 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

void    nan_converter( void )
{
	std::cout << "char: " << IMPOSSIBLE_CONVERTION << std::endl;
	std::cout << "int: " << IMPOSSIBLE_CONVERTION << std::endl;
	std::cout << "float: " << NOT_A_FLOAT << std::endl;
	std::cout << "double: " << NOT_A_DOUBLE << std::endl;
}

void    char_converter( const std::string& input )
{
	char val = input[0];
	
	if (val >= 32 && val <= 126)
		std::cout << "char: " << val << std::endl;
	else
		std::cout << "char: " << NON_DISP << std::endl;

	std::cout << "int: " << static_cast<int>(val) << std::endl;
	std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

void    int_converter( const std::string& input )
{
	int	val;
	std::istringstream strm(input);

	strm >> val;

	if (strm.fail())
		return nan_converter();

	if (val >= 32 && val <= 126)
		std::cout << "char: " << static_cast<char>(val) << std::endl;
	else
		std::cout << "char: " << NON_DISP << std::endl;

	std::cout << "int: " << val << std::endl;
	std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

void    float_converter( const std::string& input )
{
	if (input == NOT_A_FLOAT || input == NEG_NOT_A_FLOAT || input == POS_NOT_A_FLOAT)
	{
		return nan_converter();
	}
	else if (input == NEG_FLOAT_INF)
	{
		std::cout << "char: " << NON_DISP << std::endl;
		std::cout << "int: " << NON_DISP << std::endl;
		std::cout << "float: " << NEG_FLOAT_INF << std::endl;
		std::cout << "double: " << NEG_DOUBLE_INF << std::endl;
	}
	else if (input == FLOAT_INF || input == POS_FLOAT_INF)
	{
		std::cout << "char: " << NON_DISP << std::endl;
		std::cout << "int: " << NON_DISP << std::endl;
		std::cout << "float: " << FLOAT_INF << std::endl;
		std::cout << "double: " << DOUBLE_INF << std::endl;
	}
	else
	{
		float   val;
		std::stringstream strm(input.substr(0, input.length() - 1));

		strm >> val;

		if (strm.fail())
			return nan_converter();

		if (val >= 32 && val <= 126)
			std::cout << "char: " << static_cast<char>(val) << std::endl;
		else
			std::cout << "char: " << NON_DISP << std::endl;

		if (val <= INT_MAX && val >= INT_MIN)
			std::cout << "int: " << static_cast<int>(val) << std::endl;
		else
			std::cout << "int: " << NON_DISP << std::endl;

		strm.clear();
		strm.str("");
		strm << val;

		if (strm.str().find('.') == std::string::npos)
		{
			std::cout << "float: " << val << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;       
		}
		else
		{
			std::cout << "float: " << val << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(val) << std::endl;    
		}
	}
}

void    double_converter( const std::string& input )
{
	if (input == NOT_A_DOUBLE || input == NEG_NOT_A_DOUBLE || input == POS_NOT_A_DOUBLE)
	{
		return nan_converter();
	}
	else if (input == NEG_DOUBLE_INF)
	{
		std::cout << "char: " << NON_DISP << std::endl; // this has to be non disp
		std::cout << "int: " << NON_DISP << std::endl;
		std::cout << "float: " << NEG_FLOAT_INF << std::endl;
		std::cout << "double: " << NEG_DOUBLE_INF << std::endl;
	}
	else if (input == DOUBLE_INF || input == POS_DOUBLE_INF)
	{
		std::cout << "char: " << NON_DISP << std::endl;
		std::cout << "int: " << NON_DISP << std::endl;
		std::cout << "float: " << FLOAT_INF << std::endl;
		std::cout << "double: " << DOUBLE_INF << std::endl;
	}
	else
	{
		double val;
		std::stringstream strm(input);

		strm >> val;

		if (strm.fail())
			return nan_converter();

		if (val >= 32 && val <= 126)
			std::cout << "char: " << static_cast<char>(val) << std::endl;
		else
			std::cout << "char: " << NON_DISP << std::endl;

		if (val <= INT_MAX && val >= INT_MIN)
			std::cout << "int: " << static_cast<int>(val) << std::endl;
		else
			std::cout << "int: " << NON_DISP << std::endl;

		strm.clear();
		strm.str("");
		strm << val;

		if (strm.str().find('.') == std::string::npos)
		{
			if (val >= -FLT_MAX && val <= FLT_MAX)
				std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
			else
				std::cout << "float: " << NON_DISP << std::endl;   
			std::cout << "double: " << val << ".0" << std::endl;
		}
		else
		{
			if (val >= FLT_MIN && val <= FLT_MAX)
				std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
			else
				std::cout << "float: " << NON_DISP << std::endl;
			std::cout << "double: " << val << std::endl;
		}
	}
}
