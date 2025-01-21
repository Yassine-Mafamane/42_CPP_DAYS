/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 01:50:15 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 14:51:09 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{

public :

	// Form Exceptions

	class GradeTooHighException : public std::invalid_argument
	{
		public :
			GradeTooHighException( std::string message );
	};

	class GradeTooLowException : public std::invalid_argument
	{
		public :
			GradeTooLowException( std::string message );
	};

	// Constructors

	Form( std::string name, int sign_grade, int exec_grade );
	Form( const Form& ref );

	// Destructor

	~Form();

	// Copy assignment operator

	Form &operator = ( const Form& rhs );

	// Form methods

	std::string	getName( void ) const;
	int			getSignGrade( void ) const;
	int			getExecuteGrade( void ) const;
	bool		isSigned( void ) const;

	void	beSigned( const Bureaucrat& B );


private :

	const std::string	name;
	bool				is_signed;
	const int			req_sign_grade;
	const int			req_execute_grade;
	
	std::string	get_reason( const Bureaucrat& B ) const;
	static int	validate_grade( int grade );
	
};

std::ostream &operator << ( std::ostream& stream, const Form& f );



#endif