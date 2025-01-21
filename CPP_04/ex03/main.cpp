/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:19:12 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/26 15:40:25 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());


	ICharacter* me = new Character("me");

	AMateria* tmp;

	tmp = src->createMateria("ice");

	me->equip(tmp);

	tmp = src->createMateria("Unknown");

	me->equip(tmp);

	me->unequip(2);

	ICharacter* bob = new Character("bob");

	me->use(5, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}