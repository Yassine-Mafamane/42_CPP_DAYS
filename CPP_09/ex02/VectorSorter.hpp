

#ifndef VECTOR_SORTER
# define VECTOR_SORTER

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

class VectorSorter
{
	public :

		VectorSorter();

		std::vector<int>	sort( char *args[], size_t size );
		double					get_elapsed_time( void );


	private :

		VectorSorter( const VectorSorter& ref );

		void					sort_vector( const std::vector<int> & numbers );
		void					make_pairs( const std::vector<int> & numbers );
		void					sort_pairs( void );
		void					fill_chains( void );
		void					insert_to_main( void );

		static std::vector<int>	generateJacobsthalSeq( int size );
		static int				to_int( const std::string & nb );

		std::vector<std::pair<int, int> >	pairs;
		std::vector<int>					main_chain;
		std::vector<int>					pend;

		int									odd_element;

		double								elapsed_time;
};

#endif