/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:34:11 by ymafaman          #+#    #+#             */
/*   Updated: 2024/07/04 02:44:36 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip> 
#include <cstdlib>

class Contact
{
	private:
		int			index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:

		Contact& setIndex(int index);

		Contact& setFirst_name(std::string first_name);

		Contact& setlast_name(std::string last_name);

		Contact& setnickname(std::string nickname);

		Contact& setphone_number(std::string phone_number);

		Contact& setdarkest_secret(std::string darkest_secret);
		
		int	getIndex(void);
	
		std::string get_full_name(void);

		void	show_full_contact_info(void);

		void	show_partial_contact_info(void);
};


#endif