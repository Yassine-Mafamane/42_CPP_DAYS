/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:03:12 by ymafaman          #+#    #+#             */
/*   Updated: 2024/05/29 22:43:02 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::unlistedLevel( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::complain( std::string level )
{
	int	levelNum;

	levelNum = level == "DEBUG" ? 1 : (level == "INFO" ? 2 : (level == "WARNING" ? 3 : (level == "ERROR" ? 4 : -1)));

	switch (levelNum)
	{
	case 1:
		std::cout << "[ DEBUG ]" << std::endl;
		this->action = &Harl::debug;
		(this->*action) ();
	case 2:
		std::cout << "[ INFO ]" << std::endl;
		this->action = &Harl::info;
		(this->*action) ();
	case 3:
		std::cout << "[ WARNING ]" << std::endl;
		this->action = &Harl::warning;
		(this->*action) ();
	case 4:
		std::cout << "[ ERROR ]" << std::endl;
		this->action = &Harl::error;
		(this->*action) ();
		break ;
	default:
		this->action = &Harl::unlistedLevel;
		(this->*action) ();
	}
}