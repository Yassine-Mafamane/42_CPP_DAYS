/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 03:16:35 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/24 06:32:41 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	this->_name = "Standard FragTrap";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;

	std::cout << "FragTrap default constructor has been called!" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;

	std::cout << "FragTrap's parametrized constructor has been called!" << std::endl;
}

FragTrap::FragTrap( const FragTrap& ref) : ClapTrap(ref)
{
	this->_attack_damage = ref.FragTrap::_attack_damage;
	this->_hit_points = ref.FragTrap::_hit_points;
	std::cout << "FragTrap's copy constructor has been called!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap's destructor has been called!" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& rhs )
{
	std::cout << "FragTrap assignment operator has been called!" << std::endl;

	if (this == &rhs)
	{
		return (*this);
	}

	ClapTrap::operator=( rhs );

	this->_name = rhs.get_name();
	this->_hit_points = rhs.get_hit_points();
	this->_energy_points = rhs.get_energy_points();
	this->_attack_damage = rhs.get_attack_damage();
	
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap" << this->_name << " is feeling positive! High fives, everyone! ✋" << std::endl;
}

void	FragTrap::attack( const std::string& target )
{
	if (!this->_energy_points)
	{
		std::cout << "ALERT: FragTrap " << this->_name << "'s energy reserves are completely drained! Need a nap!" << std::endl;
		return ;
	}

	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;

	this->_energy_points--;
}

void	FragTrap::beRepaired( unsigned int amount )
{
	if (!this->_energy_points)
	{
		std::cout << "ALERT: FragTrap " << this->_name << "'s energy reserves are completely drained! Need a nap!" << std::endl;
		return ;
	}

	if (!amount)
	{
		std::cout << "FragTrap "<< this->_name << " attempts to repair but gains no hit points." << std::endl;
		return ;
	}
	
	std::cout << "FragTrap " << this->_name << " initiates self-repair protocol, regaining " << amount << " hit points!" << std::endl;

	this->_hit_points += amount;

	this->_energy_points--;
}

void	FragTrap::takeDamage( unsigned int amount )
{
	if (!this->_hit_points)
	{
		std::cout << "FragTrap " << this->_name << " is already out of HP and can't take more damage!" << std::endl;
		return ;
	}

	if (amount > this->_hit_points)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;

	std::cout << "FragTrap " << this->_name << " takes " << amount << " damage. Current HP " << this->_hit_points << "." << std::endl;
}

void	FragTrap::set_name( std::string name )
{
	this->_name = name;
}

void	FragTrap::set_hit_points( unsigned int hp )
{
	this->_hit_points = hp;
}

void	FragTrap::set_energy_points( unsigned int energy_points )
{
	this->_energy_points = energy_points;
}

void	FragTrap::set_attack_damage( unsigned int ad )
{
	this->_attack_damage = ad;
}

std::string	FragTrap::get_name( void ) const
{
	return (this->_name);
}

unsigned int	FragTrap::get_hit_points( void ) const
{
	return (this->_hit_points);
}

unsigned int	FragTrap::get_energy_points( void ) const
{
	return (this->_energy_points);
}

unsigned int	FragTrap::get_attack_damage( void ) const
{
	return (this->_attack_damage);
}