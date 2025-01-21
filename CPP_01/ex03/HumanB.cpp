/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 04:26:28 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/06 19:09:57 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL){
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
}

void	HumanB::removeWeapon( void )
{
	this->_weapon = NULL;
}

void	HumanB::attack( void )
{
	if (this->_weapon == NULL)
	{
		std::cout << this->_name <<" Has No Weapon!!" << std::endl;
		return ;
	}

	std::cout << this->_name << " attacks with their " << this->_weapon->getType () << std::endl;		
}
