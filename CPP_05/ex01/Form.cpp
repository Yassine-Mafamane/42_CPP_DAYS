/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 03:50:28 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 14:51:14 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Form Exceptions constructors

Form::GradeTooHighException::GradeTooHighException( std::string message ) : invalid_argument(message) {}

Form::GradeTooLowException::GradeTooLowException( std::string message ) : invalid_argument(message) {}

// Form constructors

Form::Form( std::string name, int sign_grade, int exec_grade )
	try
	: name(name), is_signed(false), req_sign_grade(Form::validate_grade(sign_grade)), req_execute_grade(Form::validate_grade(exec_grade))
	{
		std::cout << "Form: " << name << " has been created successfully!" << std::endl;
	}
	catch ( const std::exception& e )
	{
		throw ;
	}

Form::Form( const Form& ref )
	: name(ref.name), is_signed(ref.is_signed), req_sign_grade(ref.req_execute_grade), req_execute_grade(ref.req_execute_grade)
{
	std::cout << "Form: " << name << " has been created successfully!" << std::endl;
}


// Form copy assignment operator overload

Form &Form::operator = ( const Form& rhs )
{
	if (this == &rhs)
	{
		return (*this);
	}

	this->is_signed = rhs.is_signed;
	return (*this);
}


// Form destructor

Form::~Form()
{
	std::cout << "Form destroyed." << std::endl;
}


// Form methods

void	Form::beSigned( const Bureaucrat& B )
{
	if (this->is_signed)
	{
		std::cout << "Form already signed!" << std::endl;
		return;
	}

	if (B.getGrade() > this->req_sign_grade)
		throw Form::GradeTooLowException(get_reason(B));

	this->is_signed = true;
}

std::string	Form::get_reason( const Bureaucrat& B ) const
{
	std::ostringstream strm;

	strm << "Bureaucrat: " << B.getName() << " couldn’t sign " << this->name << " because grade " << B.getGrade() << " is lower than the required grade " << this->req_sign_grade << ".";

	return (strm.str()); 
}

std::string	Form::getName( void ) const
{
	return (this->name);
}

int	Form::getSignGrade( void ) const
{
	return (this->req_sign_grade);
}

int	Form::getExecuteGrade( void ) const
{
	return (this->req_execute_grade);
}

bool Form::isSigned( void ) const
{
	return (this->is_signed);
}

int	Form::validate_grade( int grade )
{
	if (grade < 1)
		throw Form::GradeTooHighException("Form construction error! Reason: A grade cannot be higher than 1!");

	if (grade > 150)
		throw Form::GradeTooLowException("Form construction error! Reason: A grade cannot be lower than 150!");

	return (grade);
}

std::ostream &operator << ( std::ostream& stream, const Form& f )
{
	if (f.isSigned())
		stream << "Form " << f.getName() << " is already signed and requires a minimum grade of " << f.getExecuteGrade() << " to be executed.";
	else
		stream << "Form " << f.getName() << " is not yet signed and requires a minimum grade of " << f.getSignGrade() << " to be signed and a minimum grade of " << f.getSignGrade() << " to be signed.";
	return (stream);
}