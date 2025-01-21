/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:08:34 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 12:28:46 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{

public :

	Dog( void );
	Dog( const Dog& ref );

	~Dog();

	Dog& operator=( const Dog& rhs );

	void	makeSound( void ) const;

	void	store_new_idea( std::string new_idea );

	void	list_idea( int idx );

private :

	Brain* _brain;

};


#endif