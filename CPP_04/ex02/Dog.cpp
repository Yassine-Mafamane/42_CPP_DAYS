/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:21:14 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 13:58:22 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : _brain(new Brain())
{
	this->type = "Dog";

	std::cout << "Dog's default constructor has been called!" << std::endl;
}

Dog::Dog( const Dog& ref )
{
	this->type = ref.type;

	if (ref._brain)
		this->_brain = new Brain((const Brain&) *ref._brain);
	else
		this->_brain = NULL;

	std::cout << "Dog's copy constructor has been called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog's destructor has been called!" << std::endl;

	if (this->_brain)
		delete this->_brain;
}

Dog&	Dog::operator=( const Dog& rhs )
{
	std::cout << "Dog's copy assignment operator has been called!" << std::endl;

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

void	Dog::makeSound( void ) const
{
	std::cout << "Woof! The classic sound of a loyal companion." << std::endl;
}