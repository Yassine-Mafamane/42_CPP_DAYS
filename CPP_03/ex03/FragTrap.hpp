/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 02:53:23 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/19 23:00:43 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap{

public :

	// Constructors
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( const FragTrap& ref);

	// Destructor
	virtual ~FragTrap();

	// Assignment operator overload
	FragTrap&	operator=( const FragTrap& rhs );

	// Public memeber functions
	void	highFivesGuys( void );

	// Base class memeber functions overriding 
	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void beRepaired( unsigned int const amount );

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

	unsigned int	_hit_points;
	unsigned int	_attack_damage;

};


#endif