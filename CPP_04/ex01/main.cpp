/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:34:56 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/26 15:38:42 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* arr[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	for (int i = 0; i < 4; i++)
		delete arr[i];

	// std::cout << std::endl;

	// Cat c;
	// Dog d(c);

	// c.store_new_idea( "new idea1" );
	// c.store_new_idea( "new idea2" );
	// c.store_new_idea( "new idea3" );

	// c.list_idea(2);
	// d.list_idea(1);

	// std::cout << std::endl;

	return 0;
}
