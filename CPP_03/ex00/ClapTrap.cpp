/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:52:48 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/24 06:31:23 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("Standard Name"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap's default constructor has been called!" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap's parametrized constructor has been called!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& ref)
{
	this->_name = ref.get_name();
	this->_hit_points = ref.get_hit_points();
	this->_energy_points = ref.get_energy_points();
	this->_attack_damage = ref.get_attack_damage();
	
	std::cout << "ClapTrap's copy constructor has been called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap's destructor has been called!";
}

ClapTrap& ClapTrap::operator=( const ClapTrap& rhs )
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

void	ClapTrap::set_name( std::string name )
{
	this->_name = name;
}

void	ClapTrap::set_hit_points( unsigned int hp )
{
	this->_hit_points = hp;
}

void	ClapTrap::set_energy_points( unsigned int energy_points )
{
	this->_energy_points = energy_points;
}

void	ClapTrap::set_attack_damage( unsigned int ad )
{
	this->_attack_damage = ad;
}

std::string	ClapTrap::get_name( void ) const
{
	return (this->_name);
}

unsigned int	ClapTrap::get_hit_points( void ) const
{
	return (this->_hit_points);
}

unsigned int	ClapTrap::get_energy_points( void ) const
{
	return (this->_energy_points);
}

unsigned int	ClapTrap::get_attack_damage( void ) const
{
	return (this->_attack_damage);
}

void	ClapTrap::attack( const std::string& target )
{
	if (!this->_energy_points)
	{
		std::cout << "ALERT: ClapTrap " << this->_name << "'s energy reserves are completely drained! Need a nap!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;

	this->_energy_points--;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (!this->_energy_points)
	{
		std::cout << "ALERT: ClapTrap " << this->_name << "'s energy reserves are completely drained! Need a nap!" << std::endl;
		return ;
	}

	if (!amount)
	{
		std::cout << "ClapTrap "<< this->_name << " attempts to repair but gains no hit points." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->_name << " initiates self-repair protocol, regaining " << amount << " hit points!" << std::endl;

	this->_hit_points += amount;

	this->_energy_points--;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (!this->_hit_points)
	{
		std::cout << "ClapTrap " << this->_name << " is already out of HP and can't take more damage!" << std::endl;
		return ;
	}

	if (amount > this->_hit_points)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;

	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage. Current HP " << this->_hit_points << "." << std::endl;
}