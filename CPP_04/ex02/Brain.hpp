/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:49:19 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/20 08:05:41 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{

public :

	Brain( void );
	Brain( const Brain& ref );

	~Brain();

	Brain&	operator=( const Brain& rhs );

	void	store_new_idea( std::string new_idea );

private :

	std::string _ideas[100];
	int			_offset;

};



#endif