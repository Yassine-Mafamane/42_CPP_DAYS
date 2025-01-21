/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 06:34:13 by ymafaman          #+#    #+#             */
/*   Updated: 2024/05/26 06:37:09 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	get_field(std::string &field, std::string label)
{
	std::cout << label;
	getline (std::cin, field);

	if (std::cin.eof ())
		return (0);

	trim_field (field);

	if (field.empty ())
	{
		std::cout << std::endl;
		std::cout << "This field can not be empty!";
		std::cout << std::endl << std::endl;
		return (get_field (field, label));
	}

	if (label == "phone number   : ")
	{
		if (validat_phone_number (field) == -1)
			return (get_field (field, label));
	}

	// replace white spaces with spaces

	for (int i = 0; i < (int) field.length(); i++)
	{
		if (field[i] >= 9 && field[i] <= 13)
			field[i] = ' ';
	}

	return (1);
}

int	get_contact_info(int& index, Contact& contact)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << std::setw(40) << std::right <<"Enter Contact Info";
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	
	if (!get_field (first_name, "first name     : ")
		|| !get_field (last_name, "last name      : ")
		|| !get_field (nickname, "nickname       : ")
		|| !get_field (phone_number, "phone number   : ")
		|| !get_field (darkest_secret, "darkest_secret : "))
		return (0);

	if (index == 9)
		index = 1;

	contact.setIndex(index)
			.setFirst_name(first_name)
			.setlast_name(last_name)
			.setnickname(nickname)
			.setphone_number(phone_number)
			.setdarkest_secret(darkest_secret);

	index++;

	return (1);
}