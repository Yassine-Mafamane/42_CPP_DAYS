/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:58:56 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/06 21:34:59 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl{

	typedef void (Harl::*f)( void );

public :

	void complain( std::string level );

private :

	f action;
	
	void debug( void );

	void info( void );

	void warning( void );

	void error( void );

	void unlistedLevel( void );

};

#endif