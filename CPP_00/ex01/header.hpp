/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 06:35:39 by ymafaman          #+#    #+#             */
/*   Updated: 2024/05/26 06:37:47 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_HPP
# define HEADER_HPP

#include "PhoneBook.hpp"
#include "header.hpp"

void	trim_field(std::string &field);
void    show_labels(void);
int		validat_phone_number(std::string field);
int		get_field(std::string &field, std::string label);
int		get_contact_info(int& index, Contact& contact);

#endif