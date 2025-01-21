/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 06:32:36 by ymafaman          #+#    #+#             */
/*   Updated: 2024/05/26 06:37:19 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static int ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

void	trim_field(std::string &field)
{
	int	start = 0;
	int	end = 0;

	start = 0;
	end = 0;
	while (ft_is_space (field[end]))
	{
		end++;
	}
	field.erase (start, end - start);

    if (field.length ())
    {
        end = field.length () - 1;
        start = end;
        while (start > 0 && ft_is_space (field[start]))
        {
            start--;
        }
        field.erase (start + 1, end - start);
    }
}

int	validat_phone_number(std::string field)
{
	int	i;

	i = 0;
	while (field[i])
	{
		if (field[i] < '0' || field[i] > '9')
		{
			std::cout << "Phone number must contain only digits!" << std::endl;
			return (-1);
		}
		i++;
	}

	if (field.length () != 10)
	{
		std::cout << "Phone number must be 10 digits long!" << std::endl;
		return (-1);
	}

	return (1);
}

void	show_labels( void )
{
	std::cout << std::setw(10) << std::right  << "Index";
	std::cout << " | ";
	std::cout << std::setw(10) << std::right  << "First Name";
	std::cout << " | ";
	std::cout << std::setw(10) << std::right  << "Last Name";
	std::cout << " | ";
	std::cout << std::setw(10) << std::right  << "Nickname" << std::endl;
	std::cout << std::setw(50) << std::setfill('-') << "-";
	std::cout << std::setfill(' ') << std::endl;
}