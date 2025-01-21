/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:08:34 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 13:53:32 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{

public :

	Dog( void );
	Dog( const Dog& ref );

	~Dog();

	Dog& operator=( const Dog& rhs );

	void	makeSound( void ) const;

private :

	Brain* _brain;

};


#endif