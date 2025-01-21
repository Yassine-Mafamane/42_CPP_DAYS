/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 04:37:17 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 14:34:21 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
	{
		_learned[i] = NULL;
	}

	std::cout << "MateriaSource default constructor has been called!" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource& ref )
{
	for (int i = 0; i < 4; i++)
	{
		if (!ref._learned[i])
			_learned[i] = NULL;
		else
			_learned[i] = ref._learned[i]->clone();
	}

	std::cout << "MateriaSource copy constructor has been called!" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor has been called!" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		delete (this->_learned[i]);
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& rhs )
{
	std::cout << "MateriaSource copy assignment operator has been called!" << std::endl;

	if (this == &rhs)
	{
		return (*this);
	}

	for (int i = 0; i < 4; i++)
	{
		if (!rhs._learned[i])
			_learned[i] = NULL;
		else
			_learned[i] = rhs._learned[i]->clone();
	}

	return (*this);
}

void		MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_learned[i])
		{
			this->_learned[i] = m;
			std::cout << "Materia " << m->getType() << " has been learned successfully!" << std::endl;
			return ;
		}
	}

	std::cout << "This MateriaSource can not learn more Materias!" << std::endl;
	delete (m);
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learned[i] && (this->_learned[i]->getType() == type))
			return (_learned[i]->clone());
	}

	std::cout << "The Materia type : (" << type << ") is unknown for this MateriaSource!" << std::endl;
	return ((AMateria*) 0);
}