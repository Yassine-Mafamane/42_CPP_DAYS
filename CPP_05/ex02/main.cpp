/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:58:49 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 15:26:48 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	try
	{
		Bureaucrat B1("B1", 1);

		RobotomyRequestForm F1("targ");
		
		B1.signForm(F1);

		std::cout << std::endl << std::endl;
		
		B1.executeForm(F1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "/* ------------------ */ "<< std::endl;
	std::cout << std::endl;
	
	try
	{
		Bureaucrat B1("B1", 1);

		ShrubberyCreationForm F1("targ");
		
		B1.signForm(F1);

		std::cout << std::endl << std::endl;
		
		B1.executeForm(F1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	std::cout << "/* ------------------ */ "<< std::endl;
	std::cout << std::endl;
	
	try
	{
		Bureaucrat B1("B1", 1);

		PresidentialPardonForm F1("targ");
		
		B1.signForm(F1);

		std::cout << std::endl << std::endl;
		
		B1.executeForm(F1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}