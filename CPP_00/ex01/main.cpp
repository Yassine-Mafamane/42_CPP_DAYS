/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:34:36 by ymafaman          #+#    #+#             */
/*   Updated: 2024/05/26 06:40:43 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "header.hpp"

int	main()
{
	Contact	new_contact;
	PhoneBook my_phone_book;
	std::string	input;
	int index = 1;
	
	my_phone_book.available_contacts = 0;
	my_phone_book.contacts_offset = 0;

	while (1)
	{
		std::cout << std::endl;

		std::cout << std::setw(30) << std::right <<" ADD | SEARCH | EXIT" << std::endl << std::endl;

		std::cout << "CHOOSE A COMMAND : ";
		
		getline (std::cin, input);

		if (std::cin.eof ())
			break ;

		std::cout << std::endl;

		if (!input.compare("ADD"))
		{
			if (!get_contact_info(index, new_contact))
				break ;
			my_phone_book.add_new_contact (new_contact);

			if (my_phone_book.available_contacts < 8)
				my_phone_book.available_contacts++;
		}
		else if (!input.compare("SEARCH"))
		{
			my_phone_book.search_contact();
		}
		else if (!input.compare("EXIT"))
			break ;
		else
			std::cout << "UNKNOWN COMMAND!" << std::endl << std::endl;
	}
	
	std::cout << std::endl << std::endl <<"Phone book closed. Until next time!" << std::endl << std::endl;
	return (0);
}