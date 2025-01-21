/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:27:01 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/22 12:41:10 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string name, std::string target ) : AForm(name, 25, 5, target)
{

}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& ref ) : AForm(ref)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm& rhs )
{
	if (this == &rhs)
	{
		return (*this);
	}

	AForm::operator=(rhs);
	return (*this);
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (!this->isSigned())
		throw (std::invalid_argument("Can not execute the form " + this->getName() + "! Form not signed yet!"));

	if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException(executor.getName() + "'s grade is too low to execute " + this->getName()));

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}