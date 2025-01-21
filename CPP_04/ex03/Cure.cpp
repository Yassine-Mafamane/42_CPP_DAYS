/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:57:33 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 15:35:28 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) :  AMateria("cure")
{
	std::cout << "Cure default constructor has been called!" << std::endl;
}

Cure::Cure( const Cure& ref ) : AMateria(ref._type)
{
	std::cout << "Cure copy constructor has been called!" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor has been called!" << std::endl;
}

Cure&	Cure::operator=( const Cure& rhs )
{
	(void)rhs;
	std::cout << "Cure copy assginment operator has been called!" << std::endl;

	return (*this);
}

AMateria*	Cure::clone( void ) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}