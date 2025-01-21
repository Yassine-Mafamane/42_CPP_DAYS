/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 03:55:36 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/08 12:34:29 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( const std::string& type )
{
	this->type = type;
};

void	Weapon::setType( const std::string& type )
{
	this->type = type;
}

const std::string& Weapon::getType( void ) const
{
	return (this->type);
}