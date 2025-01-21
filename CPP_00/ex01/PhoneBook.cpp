/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:46:48 by ymafaman          #+#    #+#             */
/*   Updated: 2024/05/29 00:14:08 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "header.hpp"

void	PhoneBook::add_new_contact(Contact newContact)
{
	contacts[newContact.getIndex() - 1] = newContact;
}

void	PhoneBook::search_contact()
{
	std::string full_name;
	int			count = 0;
	std::string	input;
	int			choosen_index;
		 
	for (int i = 0; i < available_contacts; i++)
	{
		if (!count)
			show_labels();
		contacts[i].show_partial_contact_info();
		count++;
	}

	if (!count)
	{
		std::cout << std::endl <<"Phonebook is empty!" << std::endl << std::endl;
		return ;
	}

	std::cout << std::endl << "Choose An Index : ";

	getline(std::cin, input);

	if (std::cin.eof())
	{
		std::cout << std::endl << std::endl <<"Phone book closed. Until next time!" << std::endl << std::endl;
		exit (0);
	}

	std::cout << std::endl;

	if (input.length() != 1)
	{
		std::cout << "YOU HAVE CHOOSED A WRONG INDEX!" << std::endl;
		return ;
	}

	choosen_index = input[0] - 48;

	if (choosen_index < 1 || choosen_index > available_contacts)
	{
		std::cout << "YOU HAVE CHOOSED A WRONG INDEX!" << std::endl;
		return ;
	}	

	contacts[choosen_index - 1].show_full_contact_info();
}