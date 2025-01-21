/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:48:33 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/06 18:09:10 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main( void )
{
	int		N = 4;
	Zombie* heapZombies = zombieHorde ( N, "ZombieGang");

	if (!heapZombies)
	{
		std::cout << "Allocation can not be done!" << std::endl;
		return (1);
	}

	for (int i = 0; i < N; i++)
		heapZombies[i].announce ();

	delete [] heapZombies;

	return (0);
}

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 0)
	{
		return (NULL);
	}

	Zombie* zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombies[i].setName(name);

	return (zombies);
}