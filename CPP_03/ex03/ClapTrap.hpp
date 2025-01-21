/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:44:22 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/20 03:55:14 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap{

public :

	// Constructors
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( const ClapTrap& ref );

	// Destructor
	virtual ~ClapTrap();

	// Assignment operator overload
	ClapTrap&	operator=( const ClapTrap& rhs );

	// Setters
	void	set_name( std::string name );
	void	set_hit_points( unsigned int hp );
	void	set_energy_points( unsigned int energy_points );
	void	set_attack_damage( unsigned int ad );

	// Getters
	std::string		get_name( void ) const;
	unsigned int	get_hit_points( void ) const;
	unsigned int	get_energy_points( void ) const;
	unsigned int	get_attack_damage( void ) const;
	
	// Public memeber functions
	virtual void	attack( const std::string& target );
	virtual void	takeDamage( unsigned int amount );
	virtual	void	beRepaired( unsigned int amount );
	
protected :

	std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;
};


#endif