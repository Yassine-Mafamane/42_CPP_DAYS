/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:51:19 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 13:52:32 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal {

public :

	AAnimal( void );
	AAnimal( const AAnimal& ref );
	virtual ~AAnimal();

	AAnimal& operator=(const AAnimal& rhs);

	std::string	getType( void ) const;

	virtual void	makeSound( void ) const = 0;

protected :
	
	std::string type;

};





#endif