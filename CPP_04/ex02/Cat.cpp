/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:30:31 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/20 21:38:12 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : _brain(new Brain())
{
	this->type = "Cat";

	std::cout << "Cat's default constructor has been called!" << std::endl;
}

Cat::Cat( const Cat& ref )
{
	this->type = ref.type;

	if (ref._brain)
		this->_brain = new Brain((const Brain&) *ref._brain);
	else
		this->_brain = NULL;

	std::cout << "Cat's copy constructor has been called!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat's destructor has been called!" << std::endl;

	if (this->_brain)
		delete this->_brain;
}

Cat&	Cat::operator=( const Cat& rhs )
{
	std::cout << "Cat's copy assignment operator has been called!" << std::endl;

	if (this == &rhs)
	{
		return (*this);
	}

	this->type = rhs.type;

	if (this->_brain)
		delete this->_brain;

	if (rhs._brain)
		this->_brain = new Brain((const Brain&) *rhs._brain);
	else
		this->_brain = NULL;

	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow!" << std::endl;
}