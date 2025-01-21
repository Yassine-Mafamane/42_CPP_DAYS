/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 02:53:23 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/20 03:12:20 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap{

public :	

	// Constructors
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap& ref);

	// Destructor
	virtual ~ScavTrap();

	// Assignment operator overload
	ScavTrap&	operator=( const ScavTrap& rhs );

	// Public memeber functions
	void	guardGate( void );

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

protected :

	unsigned int	_energy_points;

};


#endif