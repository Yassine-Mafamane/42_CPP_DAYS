/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:03:25 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/08 12:36:03 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "This program must take 1 argument!" << std::endl;
		return (1);
	}

	Harl harl;
	std::string level = av[1];

	harl.complain (level);
	return 0;
}
