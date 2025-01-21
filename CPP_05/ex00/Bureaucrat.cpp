/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 05:25:56 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 14:21:53 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Bureaucrat Creation Exceptions Constructors

Bureaucrat::GradeTooHighException::GradeTooHighException( std::string message ) : invalid_argument(message) {}

Bureaucrat::GradeTooLowException::GradeTooLowException( std::string message ) : invalid_argument(message) {}

// Bureaucrat Constructors

Bureaucrat::Bureaucrat( std::string name, int grade )
	try
		: grade(Bureaucrat::validateGrade( grade )), name(name)
	{
		std::cout << "Bureaucrat " << this->name << " has been created successfully!" << std::endl;
	}
	catch(const std::exception& e)
	{
		throw ;
	}

Bureaucrat::Bureaucrat( const Bureaucrat& ref ) : grade(ref.grade), name(ref.name)
{
	std::cout << "Bureaucrat " << this->name << " has been created successfully!" << std::endl;
}

Bureaucrat &Bureaucrat::operator = ( const Bureaucrat& rhs )
{
	if (this == &rhs)
	{
		return (*this);
	}

	this->grade = rhs.grade;

	return (*this);
}

// Destructor

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyed." << std::endl;
}

std::string Bureaucrat::getName( void ) const
{
	return (this->name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

void	Bureaucrat::upGrade( void )
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException("Upgrading failure! Grade is already to high.");

	this->grade--;
	std::cout << "Bureaucrat " << this->name << " has been up graded!" << std::endl;
}

void	Bureaucrat::downGrade( void )
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException("Downgrading failure! Grade is already too low.");

	this->grade++;

	std::cout << "Bureaucrat " << this->name << " has been down graded!" << std::endl;
}

int	Bureaucrat::validateGrade( int grade )
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Bureaucrat construction error! Reason: A grade cannot be higher than 1!");

	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Bureaucrat construction error! Reason: A grade cannot be lower than 150!");

	return (grade);
}

std::ostream &operator << ( std::ostream& stream, const Bureaucrat& b )
{
	stream << "Bureaucrat's " << b.getName() << " grade is : " << b.getGrade();
	return (stream);
}