/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 00:08:40 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 15:36:38 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{

public:

	virtual ~ICharacter() {}

	virtual std::string const & getName() const = 0;

	virtual void equip( AMateria* m ) = 0;

	virtual void unequip(int idx) = 0;

	virtual void use(int idx, ICharacter& target) = 0;

};


#endif

