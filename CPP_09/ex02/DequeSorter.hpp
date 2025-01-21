

#ifndef DEQUE_SORTER
# define DEQUE_SORTER

#include <string>
#include <deque>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

class DequeSorter
{
	public :

		DequeSorter();

		std::deque<int>	sort( char *args[], size_t size );
		double					get_elapsed_time( void );


	private :

		DequeSorter( const DequeSorter& ref );

		void					sort_deque( const std::deque<int> & numbers );
		void					make_pairs( const std::deque<int> & numbers );
		void					sort_pairs( void );
		void					fill_chains( void );
		void					insert_to_main( void );

		static std::deque<int>	generateJacobsthalSeq( int size );
		static int				to_int( const std::string & nb );

		std::deque<std::pair<int, int> >	pairs;
		std::deque<int>						main_chain;
		std::deque<int>						pend;

		int									odd_element;

		double								elapsed_time;
};

#endif