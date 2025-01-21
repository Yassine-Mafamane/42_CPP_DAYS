/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:56:54 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/22 00:32:20 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria{

public :

	Cure( void );
	Cure( const Cure& ref );

	~Cure();

	Cure&	operator=( const Cure& rhs );

	AMateria* clone() const;

	void	use(ICharacter& target);

};



#endif