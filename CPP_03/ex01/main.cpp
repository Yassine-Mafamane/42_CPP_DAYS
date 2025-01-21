/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:56:26 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/20 03:10:06 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

void call(ClapTrap& c)
{
	std::cout << ">>>>> " << std::endl;
	c.attack("target");
	std::cout << ">>>>> " << std::endl;
}


int main()
{
	
	
	ScavTrap c("cp");

	ScavTrap b(c);
}