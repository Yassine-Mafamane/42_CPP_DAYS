/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:21:14 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 13:41:05 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog's default constructor has been called!" << std::endl;
}

Dog::Dog( const Dog& ref ) : Animal(ref)
{
	this->_type = ref._type;

	if (ref._brain)
		this->_brain = new Brain((const Brain&) ref._brain);
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

	this->_type = rhs._type;

	if (this->_brain)
		delete this->_brain;

	if (rhs._brain)
		this->_brain = new Brain((const Brain&) *(rhs._brain));
	else
		this->_brain = NULL;

	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "Woof! The classic sound of a loyal companion." << std::endl;
}

void	Dog::store_new_idea( std::string new_idea )
{
	if (!this->_brain)
	{
		std::cout << "This dog has no brain!" << std::endl;
		return ;
	}

	if (this->_brain->get_offset() == 99)
	{
		std::cout << "This dog's brain is full!" << std::endl;
		return ;
	}

	this->_brain->add_idea(new_idea);
}

void	Dog::list_idea( int idx )
{
	if (!this->_brain)
	{
		std::cout << "This dog has no brain!" << std::endl;
		return ;
	}

	if (idx < 0 || idx > 99)
	{
		std::cout << "The index is out of range!" << std::endl;
		return ;
	}

	this->_brain->show_idea(idx);
}