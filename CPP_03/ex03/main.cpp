/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:56:26 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/20 04:21:56 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"


int main()
{
	DiamondTrap d;
	DiamondTrap p;

	std::cout << "before changing : " << d.ScavTrap::get_energy_points() << std::endl;
	std::cout << "before changing : " << d.ClapTrap::get_energy_points() << std::endl;
	d.ScavTrap::set_energy_points( 500 );
	d.ClapTrap::set_energy_points( 800 );
	std::cout << "after changing : " << d.ScavTrap::get_energy_points() << std::endl;
	std::cout << "after changing : " << d.ClapTrap::get_energy_points() << std::endl;

	p = d;
	

	std::cout << "before changing : " << p.ScavTrap::get_energy_points() << std::endl;
	std::cout << "before changing : " << p.ClapTrap::get_energy_points() << std::endl;
	std::cout << "after changing : " << p.ScavTrap::get_energy_points() << std::endl;
	std::cout << "after changing : " << p.ClapTrap::get_energy_points() << std::endl;
}