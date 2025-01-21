/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:20:25 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 15:18:24 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// AForm Exceptions constructors

AForm::GradeTooHighException::GradeTooHighException( std::string message ) : invalid_argument(message) {}

AForm::GradeTooLowException::GradeTooLowException( std::string message ) : invalid_argument(message) {}

// AForm constructors

AForm::AForm( std::string name, int sign_grade, int exec_grade, std::string target )
	try
	: name(name), is_signed(false), req_sign_grade(AForm::validate_grade(sign_grade)), req_execute_grade(AForm::validate_grade(exec_grade)), target(target)
	{
		std::cout << "AForm: " << name << " has been created successfully!" << std::endl;
	}
	catch ( const std::exception& e )
	{
		throw ;
	}

AForm::AForm( const AForm& ref )
	: name(ref.name), is_signed(ref.is_signed), req_sign_grade(ref.req_execute_grade), req_execute_grade(ref.req_execute_grade), target(ref.target)
{
	std::cout << "AForm: " << name << " has been created successfully!" << std::endl;
}


// AForm copy assignment operator overload

AForm &AForm::operator = ( const AForm& rhs )
{
	if (this == &rhs)
	{
		return (*this);
	}

	this->is_signed = rhs.is_signed;
	this->target = rhs.target;
	return (*this);
}


// AForm destructor

AForm::~AForm()
{
	std::cout << "AForm destroyed." << std::endl;
}


// AForm methods

void	AForm::beSigned( const Bureaucrat& B )
{
	if (this->is_signed)
	{
		std::cout << "AForm already signed!" << std::endl;
		return;
	}

	if (B.getGrade() > this->req_sign_grade)
		throw AForm::GradeTooLowException(get_reason(B));

	this->is_signed = true;
}

std::string	AForm::get_reason( const Bureaucrat& B ) const
{
	std::ostringstream strm;

	strm << "Bureaucrat: " << B.getName() << " couldn’t sign " << this->name << " because grade " << B.getGrade() << " is lower than grade " << this->req_sign_grade << ".";

	return (strm.str()); 
}

std::string	AForm::getName( void ) const
{
	return (this->name);
}

std::string AForm::getTarget( void ) const
{
	return (this->target);
}

int	AForm::getSignGrade( void ) const
{
	return (this->req_sign_grade);
}

int	AForm::getExecuteGrade( void ) const
{
	return (this->req_execute_grade);
}

bool AForm::isSigned( void ) const
{
	return (this->is_signed);
}

int	AForm::validate_grade( int grade )
{
	if (grade < 1)
		throw AForm::GradeTooHighException("Form construction error! Reason: A grade cannot be higher than 1!");

	if (grade > 150)
		throw AForm::GradeTooLowException("Form construction error! Reason: A grade cannot be lower than 150!");

	return (grade);
}


std::ostream &operator << ( std::ostream& stream, const AForm& f )
{
	if (f.isSigned())
		stream << "Form " << f.getName() << " is already signed and requires a minimum grade of " << f.getExecuteGrade() << " to be executed.";
	else
		stream << "Form " << f.getName() << " is not yet signed and requires a minimum grade of " << f.getSignGrade() << " to be signed and a minimum grade of " << f.getSignGrade() << " to be signed.";
	return (stream);
}