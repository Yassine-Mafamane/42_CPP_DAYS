/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:29:51 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 12:28:33 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{

public :

	Cat( void );
	Cat( const Cat& ref );

	~Cat();

	Cat& operator=( const Cat& rhs );

	void	makeSound( void ) const;

	void	store_new_idea( std::string new_idea );

	void	list_idea( int idx );

private :

	Brain* _brain;

};


#endif