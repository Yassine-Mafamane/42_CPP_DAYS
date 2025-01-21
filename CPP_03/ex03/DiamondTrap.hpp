/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 02:36:02 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/20 03:11:15 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{

public :

	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap& ref );

	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& rhs);

	// public member functions
	void	whoAmI( void );
	
	// Base class memeber functions overriding 
	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	
	// Setters redefinition
	void	set_name( std::string name );
	void	set_hit_points( unsigned int hp );
	void	set_energy_points( unsigned int energy_points );
	void	set_attack_damage( unsigned int ad );

	// Getters redefinition
	std::string		get_name( void ) const;
	unsigned int	get_hit_points( void ) const;
	unsigned int	get_energy_points( void ) const;
	unsigned int	get_attack_damage( void ) const;

private :

	std::string _name;
};



#endif