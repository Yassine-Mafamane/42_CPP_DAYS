/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:51:11 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 13:55:51 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void )
{
	this->type = "Unknown creature";

	std::cout << "AAnimal's default constructor has been called!" << std::endl;
}

AAnimal::AAnimal( const AAnimal& ref )
{
	this->type = ref.type;

	std::cout << "AAnimal's copy constructor has been called!" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal's destructor has been called!" << std::endl;
}

AAnimal& AAnimal::operator=( const AAnimal& rhs )
{
	std::cout << "AAnimal's copy assignment operator has been called!" << std::endl;

	if (this == &rhs)
	{
		return (*this);
	}

	this->type = rhs.type;

	return (*this);	
}

std::string	AAnimal::getType( void ) const
{
	return (this->type);
}
