/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:39:08 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 14:21:40 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) :  AMateria("ice")
{
	std::cout << "Ice default constructor has been called!" << std::endl;
}

Ice::Ice( const Ice& ref ) : AMateria(ref._type)
{
	std::cout << "Ice copy constructor has been called!" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor has been called!" << std::endl;
}

Ice&	Ice::operator=( const Ice& rhs )
{
	(void)rhs;
	std::cout << "Ice copy assginment operator has been called!" << std::endl;

	return (*this);
}

AMateria*	Ice::clone( void ) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
