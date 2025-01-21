/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:28:31 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 14:24:29 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "The AMateria parametrized constructor has been called!" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "The AMateria destructor has been called!" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}
