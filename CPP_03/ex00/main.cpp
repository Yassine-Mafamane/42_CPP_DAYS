/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:56:26 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/16 02:01:36 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{

	ClapTrap c("Tom");
	c.set_attack_damage(3);
	c.set_hit_points(100);
	c.attack( "Jerry ");
	c.beRepaired( 2 );
	c.takeDamage( 55 );
	c.takeDamage( 55 );

}