/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:28:56 by ymafaman          #+#    #+#             */
/*   Updated: 2024/12/22 23:15:08 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void )
{
	N = 0;
	std::cout << "A new array has been created with a maximum capacity of : 0."<< std::endl;
}

Span::Span( const Span& ref )
{
	this->array = ref.array;
	this->N = ref.N;

	std::cout << "A new array has been created with a maximum capacity of : " << N << std::endl;
}

Span::Span( unsigned int N )
{
	this->N = N;

	std::cout << "A new array has been created with a maximum capacity of : " << N << "."<< std::endl;
}

Span::~Span(){}

Span& Span::operator=( const Span& rhs )
{
	if (this == &rhs)
	{
		return *this;
	}

	this->array.clear();
	this->array = rhs.array;
	this->N = rhs.N;

	return *this;
}

void    Span::addNumber( int num )
{
	if (N - array.size())
		array.push_back(num);
	else
		throw std::length_error("No enough space in the array to add a new element!");
}

template <typename T>
void	Span::addNumber( T arr, unsigned int size )
{
	unsigned int	available_size = N - this->array.size();

	if (size > available_size)
		throw std::length_error("No enough space in the array to add the new elements!");

	for (unsigned int i = 0; i < size; i++)
	{
		this->array.push_back(arr[i]);
	}
}

unsigned int    Span::shortestSpan( void )
{
	if (!this->array.size() || this->array.size() == 1)
		throw std::length_error("No span can be found in this array!");

	std::vector<int>	sub = this->array;
	bool				first_time = true;
	unsigned int		span;

	std::sort(sub.begin(), sub.end());

	for (std::vector<int>::iterator it = sub.begin() + 1; it != sub.end(); it++)
	{
		if (first_time || (static_cast<unsigned int>(*it - *(it - 1)) < span))
		{
			span = *it - *(it - 1);
			first_time = false;
		}
	}
	return span;
}

unsigned int    Span::longestSpan( void )
{
	if (!this->array.size() || this->array.size() == 1)
		throw std::length_error("No span can be found in this array!");

	std::vector<int>	sub = this->array;
	unsigned int		span;

	std::sort(sub.begin(), sub.end());

	span = (unsigned int) *(sub.end() - 1) - *sub.begin();
	return span;
}