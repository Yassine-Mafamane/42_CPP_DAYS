/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:29:51 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/20 06:38:27 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{

public :

	Cat( void );
	Cat( const Cat& ref );

	~Cat();

	Cat& operator=( const Cat& rhs );

	void	makeSound( void ) const;
};


#endif