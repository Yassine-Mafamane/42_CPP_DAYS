/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:53:36 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/20 08:08:49 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) : _offset(0)
{
	std::cout << "The brain's default constructor has been called!" << std::endl;
}

Brain::Brain( const Brain& ref )
{
	for (int i = 0; i <= ref._offset; i++)
	{
		this->_ideas[i] = ref._ideas[i];
	}

	this->_offset = ref._offset;

	std::cout << "The brain's copy constructor has been called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain's destructor has been called!" << std::endl;
}

Brain&	Brain::operator=( const Brain& rhs )
{
	std::cout << "Brain's copy assignment operator has been called!" << std::endl;

	if (this == &rhs)
	{
		return (*this);
	}

	for (int i = 0; i < rhs._offset; i++)
	{
		this->_ideas[i] = rhs._ideas[i];
	}

	this->_offset = rhs._offset;

	return (*this);
}

void	Brain::store_new_idea( std::string new_idea )
{
	if (this->_offset == 99)
	{
		std::cout << "Brain is full!" << std::endl; // TODO : try to show the name of the animal.
		return ;
	}
	
	this->_ideas[this->_offset] = new_idea;

	this->_offset++;
}