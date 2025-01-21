/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:30:02 by ymafaman          #+#    #+#             */
/*   Updated: 2024/05/26 06:37:28 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


#include <string>
#include "Contact.hpp"

class PhoneBook
{
	public:
		Contact	contacts[8];
		int		available_contacts;
		int		contacts_offset;

		void	add_new_contact(Contact newContact);
		void	search_contact();
};

#endif