

#ifndef RPN_HPP
# define RPN_HPP

#include <sstream>
#include <stack>
#include <exception>
#include <iostream>

typedef enum	e_token_type
{
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION,
	OPERAND,
	UNKNOWN
}	token_type;

class RPNCalculator
{

	public :

		~RPNCalculator();

		static float		calculate( const std::string & expression );

	private :

		RPNCalculator();
		RPNCalculator( const RPNCalculator & ref );

		void				push_operand(std::string & token );
		void				operate( const token_type & type );
		float				getResult( void );
		static token_type	find_token_type( const std::string & token );
		static bool			is_num( const std::string & token );
		static float		divide( float a, float b );

		std::stack<float>		operands;

};


#endif