/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:00:41 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 13:36:12 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
	this->_type = "Unknown creature";

	std::cout << "Animal's default constructor has been called!" << std::endl;
}

Animal::Animal( std::string type ) : _type(type)
{
	std::cout << "Animal's parametrized constructor has been called!" << std::endl;
}

Animal::Animal( const Animal& ref )
{
	this->_type = ref._type;

	std::cout << "Animal's copy constructor has been called!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal's destructor has been called!" << std::endl;
}

Animal& Animal::operator=( const Animal& rhs )
{
	std::cout << "Animal's copy assignment operator has been called!" << std::endl;

	if (this == &rhs)
	{
		return (*this);
	}

	this->_type = rhs._type;

	return (*this);	
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "Unknown creature, unknown sound..." << std::endl;
}