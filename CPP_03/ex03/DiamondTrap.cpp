/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:07 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/24 06:33:22 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->_name = "Standard DiamondTrap";

	ClapTrap::_name = "Standard DiamondTrap_clap_name";

	std::cout << "DiamondTrap's default constructor has been called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->_name = name;

	std::cout << "DiamondTrap's parametrized constructor has been called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref), ScavTrap(ref), FragTrap(ref)
{
	std::cout << "DiamondTrap's copy constructor has been called!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap's destructor has been called!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "DiamondTrap assignment operator has been called!" << std::endl;

	if (this == &rhs)
	{
		return (*this);
	}

	FragTrap::operator=( rhs );
	ScavTrap::operator=( rhs );

	this->_name = rhs.DiamondTrap::get_name();
	this->_hit_points = rhs.DiamondTrap::get_hit_points();
	this->_energy_points = rhs.DiamondTrap::get_energy_points();
	this->_attack_damage = rhs.DiamondTrap::get_attack_damage();

	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "It's " << this->_name << " with \"" << this->ClapTrap::_name << "\" as ClapTrap name!" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (!this->_energy_points)
	{
		std::cout << "ALERT: DiamondTrap " << this->_name << "'s energy reserves are completely drained! Need a nap!" << std::endl;
		return;
	}

	if (!amount)
	{
		std::cout << "DiamondTrap " << this->_name << " attempts to repair but gains no hit points." << std::endl;
		return;
	}

	std::cout << "DiamondTrap " << this->_name << " initiates self-repair protocol, regaining " << amount << " hit points!" << std::endl;

	this->_hit_points += amount;

	this->_energy_points--;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (!this->_hit_points)
	{
		std::cout << "DiamondTrap " << this->_name << " is already out of HP and can't take more damage!" << std::endl;
		return;
	}

	if (amount > this->_hit_points)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;

	std::cout << "DiamondTrap " << this->_name << " takes " << amount << " damage. Current HP " << this->_hit_points << "." << std::endl;
}

void DiamondTrap::set_name(std::string name)
{
	this->_name = name;
}

void DiamondTrap::set_hit_points(unsigned int hp)
{
	this->_hit_points = hp;
}

void DiamondTrap::set_energy_points(unsigned int energy_points)
{
	this->_energy_points = energy_points;
}

void DiamondTrap::set_attack_damage(unsigned int ad)
{
	this->_attack_damage = ad;
}

std::string DiamondTrap::get_name(void) const
{
	return (this->_name);
}

unsigned int DiamondTrap::get_hit_points(void) const
{
	return (this->_hit_points);
}

unsigned int DiamondTrap::get_energy_points(void) const
{
	return (this->_energy_points);
}

unsigned int DiamondTrap::get_attack_damage(void) const
{
	return (this->_attack_damage);
}