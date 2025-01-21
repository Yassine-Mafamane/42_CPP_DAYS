/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 03:16:35 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/24 06:32:15 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	this->_name = "Standard ScavTrap";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	
	std::cout << "ScavTrap default constructor has been called!" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	
	std::cout << "ScavTrap's parametrized constructor has been called!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& ref) : ClapTrap(ref)
{
	std::cout << "ScavTrap's copy constructor has been called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap's destructor has been called!" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& rhs )
{
	if (this == &rhs)
	{
		return (*this);
	}

	this->_name = rhs.get_name();
	this->_hit_points = rhs.get_hit_points();
	this->_energy_points = rhs.get_energy_points();
	this->_attack_damage = rhs.get_attack_damage();
	
	return (*this);
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}

void	ScavTrap::attack( const std::string& target )
{
	if (!this->_energy_points)
	{
		std::cout << "ALERT: ScavTrap " << this->_name << "'s energy reserves are completely drained! Need a nap!" << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;

	this->_energy_points--;
}

void	ScavTrap::beRepaired( unsigned int amount )
{
	if (!this->_energy_points)
	{
		std::cout << "ALERT: ScavTrap " << this->_name << "'s energy reserves are completely drained! Need a nap!" << std::endl;
		return ;
	}

	if (!amount)
	{
		std::cout << "ScavTrap "<< this->_name << " attempts to repair but gains no hit points." << std::endl;
		return ;
	}
	
	std::cout << "ScavTrap " << this->_name << " initiates self-repair protocol, regaining " << amount << " hit points!" << std::endl;

	this->_hit_points += amount;

	this->_energy_points--;
}

void	ScavTrap::takeDamage( unsigned int amount )
{
	if (!this->_hit_points)
	{
		std::cout << "ScavTrap " << this->_name << " is already out of HP and can't take more damage!" << std::endl;
		return ;
	}

	if (amount > this->_hit_points)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;

	std::cout << "ScavTrap " << this->_name << " takes " << amount << " damage. Current HP " << this->_hit_points << "." << std::endl;
}