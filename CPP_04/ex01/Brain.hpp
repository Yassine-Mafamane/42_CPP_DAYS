/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 06:49:19 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/25 13:26:46 by ymafaman         ###   ########.fr       */
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

	int	get_offset( void );

	void	add_idea( std::string new_idea );

	void	show_idea( int idx );

private :

	std::string _ideas[100];
	int			_offset;

};



#endif