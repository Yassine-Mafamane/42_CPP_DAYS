/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:30:31 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/26 15:37:58 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat's default constructor has been called!" << std::endl;
}

Cat::Cat( const Cat& ref ) : Animal(ref)
{
	this->_type = ref._type;

	std::cout << "Cat's copy constructor has been called!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat's destructor has been called!" << std::endl;
}

Cat&	Cat::operator=( const Cat& rhs )
{
	std::cout << "Cat's copy assignment operator has been called!" << std::endl;

	if (this == &rhs)
	{
		return (*this);
	}

	this->_type = rhs._type;

	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow!" << std::endl;
}