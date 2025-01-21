/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:30:31 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 13:41:51 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat's default constructor has been called!" << std::endl;
}

Cat::Cat( const Cat& ref ) : Animal(ref)
{
	this->_type = ref._type;

	if (ref._brain)
		this->_brain = new Brain((const Brain&) *(ref._brain));
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

	this->_type = rhs._type;

	if (this->_brain)
		delete this->_brain;

	if (rhs._brain)
		this->_brain = new Brain((const Brain&) rhs._brain);
	else
		this->_brain = NULL;

	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow!" << std::endl;
}

void	Cat::store_new_idea( std::string new_idea )
{
	if (!this->_brain)
	{
		std::cout << "This cat has no brain!" << std::endl;
		return ;
	}

	if (this->_brain->get_offset() == 99)
	{
		std::cout << "This cat's brain is full!" << std::endl;
		return ;
	}

	this->_brain->add_idea(new_idea);
}

void	Cat::list_idea( int idx )
{
	if (!this->_brain)
	{
		std::cout << "This cat has no brain!" << std::endl;
		return ;
	}

	if (idx < 0 || idx > 99)
	{
		std::cout << "The index is out of range!" << std::endl;
		return ;
	}

	this->_brain->show_idea(idx);
}