/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 03:58:22 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/22 00:33:51 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE
# define MATERIA_SOURCE

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource {

public :
	
	MateriaSource( void );
	MateriaSource( const MateriaSource& ref );
	
	~MateriaSource();

	MateriaSource&	operator=( const MateriaSource& rhs );

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const & type);

private :

	AMateria* _learned[4];
};

#endif