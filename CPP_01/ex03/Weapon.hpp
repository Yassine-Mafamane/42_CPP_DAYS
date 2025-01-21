/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 03:51:37 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/06 21:47:52 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{

public :

	Weapon( const std::string& type);

	const std::string&	getType( void ) const;

	void				setType( const std::string& type );

private :

	std::string type;
	
};


#endif