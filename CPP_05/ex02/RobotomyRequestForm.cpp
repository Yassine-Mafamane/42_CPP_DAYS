/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:06:17 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/22 12:37:33 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45, target)
{

}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& ref ) : AForm(ref)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm& rhs )
{
	if (this == &rhs)
	{
		return (*this);
	}

	AForm::operator=(rhs);
	return (*this);
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (!this->isSigned())
		throw (std::invalid_argument("Can not execute the form " + this->getName() + "! Form not signed yet!"));

	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException(executor.getName() + "'s grade is too low to execute " + this->getName()));
	
	std::srand(static_cast<unsigned>(std::time(0)));

	if (std::rand() % 2)
	{
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << this->getTarget() << " robotomy has failed!" << std::endl;
	}
}