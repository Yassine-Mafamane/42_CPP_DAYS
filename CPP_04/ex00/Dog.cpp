/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:21:14 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/26 15:37:45 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog's default constructor has been called!" << std::endl;
}

Dog::Dog( const Dog& ref ) : Animal(ref)
{
	this->_type = ref._type;

	std::cout << "Dog's copy constructor has been called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog's destructor has been called!" << std::endl;
}

Dog&	Dog::operator=( const Dog& rhs )
{
	std::cout << "Dog's copy assignment operator has been called!" << std::endl;

	if (this == &rhs)
	{
		return (*this);
	}

	this->_type = rhs._type;

	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "Woof! The classic sound of a loyal companion." << std::endl;
}