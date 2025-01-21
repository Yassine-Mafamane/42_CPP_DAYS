/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:30:45 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 22:37:49 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( const Intern& ref )
{
	(void)ref;
}

Intern::~Intern() {}

Intern&	Intern::operator=( const Intern& rhs )
{
	(void)rhs;
	return *this;
}

int		Intern::MatchesRobotomyRequest( std::string name )
{
	return (!name.compare("robotomy request") ? 1 : 0);
}

int		Intern::MatchesShrubberyCreation( std::string name )
{
	return (!name.compare("shrubbery creation") ? 2 : 0);
}

int		Intern::MatchesPresidentialPardon( std::string name )
{
	return (!name.compare("presidential pardon") ? 3 : 0);
}


AForm	*Intern::makeForm( std::string name, std::string target )
{
	int		key = 0;

	key += MatchesRobotomyRequest(name);
	key += MatchesShrubberyCreation(name);
	key += MatchesPresidentialPardon(name);

	switch (key)
	{
	case 1:
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		return (new RobotomyRequestForm(name, target));
	case 2:
		std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
		return (new ShrubberyCreationForm(name, target));
	case 3:
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;
		return (new PresidentialPardonForm(name, target));
	default:
		throw std::invalid_argument("Unknown form type!");
	}
}
