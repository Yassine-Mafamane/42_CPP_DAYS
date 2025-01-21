/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:18:46 by ymafaman          #+#    #+#             */
/*   Updated: 2024/12/21 21:36:49 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Span {

	public :
		Span( void );
		Span( const Span& ref );
		Span( unsigned int size );
		
		~Span();
		
		Span& operator=( const Span& rhs );

		void            addNumber( int num );
		unsigned int    shortestSpan( void );
		unsigned int    longestSpan( void );

		template <typename T>
		void            addNumber( T arr, unsigned int size ); // Improved addNumber function to add multiple elements using a single call.

	private :

		unsigned int		N;
		std::vector<int>	array;
};



#endif