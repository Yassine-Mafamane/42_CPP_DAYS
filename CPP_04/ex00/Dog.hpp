/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:08:34 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/20 06:38:16 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{

public :

	Dog( void );
	Dog( const Dog& ref );

	~Dog();

	Dog& operator=( const Dog& rhs );

	void	makeSound( void ) const;
};


#endif