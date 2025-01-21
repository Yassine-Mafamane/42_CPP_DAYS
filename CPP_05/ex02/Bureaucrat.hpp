/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 05:03:30 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 15:20:57 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

public :

	// Bureaucrat Creation Exceptions

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

	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat& ref );

	// Destructor

	~Bureaucrat();

	// Copy assignment operator overload

	Bureaucrat &operator = ( const Bureaucrat& rhs );

	// Getters

	std::string	getName( void ) const;
	int			getGrade( void ) const;

	// Public member methods

	void	upGrade( void );
	void	downGrade( void );
	
	void	signForm( AForm& form );
	void	executeForm(AForm const & form);

private :

	int 				grade;	
	const std::string	name;

	static int	validateGrade( int grade );
	
};

std::ostream &operator << ( std::ostream& stream, const Bureaucrat& b );

#endif