/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:19:55 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 15:17:17 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{

public :

	// AForm Exceptions

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

	AForm( std::string name, int sign_grade, int exec_grade, std::string target );
	AForm( const AForm& ref );

	// Destructor

	virtual	~AForm();

	// Copy assignment operator

	AForm &operator = ( const AForm& rhs );

	// AForm methods

	std::string	getName( void ) const;
	std::string	getTarget( void ) const;
	int			getSignGrade( void ) const;
	int			getExecuteGrade( void ) const;
	bool		isSigned( void ) const;	

	void	beSigned( const Bureaucrat& B );
	virtual void	execute( Bureaucrat const & executor ) const = 0;


private :

	const std::string	name;
	bool				is_signed;
	const int			req_sign_grade;
	const int			req_execute_grade;
	std::string			target;
	
	std::string	get_reason( const Bureaucrat& B ) const;
	static int	validate_grade( int grade );
	
};

std::ostream &operator << ( std::ostream& stream, const AForm& f );


#endif