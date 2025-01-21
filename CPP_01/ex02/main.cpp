/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 03:09:28 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/08 12:28:40 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main( void )
{
	std::string var = "HI THIS IS BRAIN";
	std::string* stringPTR = &var;
	std::string& stringREF = var;

	std::cout << std::endl;

	std::cout << std::setw(41) << std::left << "The memory address of the string variable" << " : " << &var << std::endl;
	std::cout << std::setw(41) << std::left << "The memory address held by stringPTR" << " : " << stringPTR << std::endl;
	std::cout << std::setw(41) << std::left << "The memory address held by stringREF" << " : " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(41) << std::left << "The value of the string variable" << " : " << var << std::endl;
	std::cout << std::setw(41) << std::left << "The value pointed to by stringPTR" << " : " << *stringPTR << std::endl;
	std::cout << std::setw(41) << std::left << "The value pointed to by stringREF" << " : " << stringREF << std::endl;
	
	std::cout << std::endl;
	
	return 0;
}
