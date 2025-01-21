/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:29:51 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 13:53:23 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{

public :

	Cat( void );
	Cat( const Cat& ref );

	~Cat();

	Cat& operator=( const Cat& rhs );

	void	makeSound( void ) const;

private :

	Brain* _brain;

};


#endif