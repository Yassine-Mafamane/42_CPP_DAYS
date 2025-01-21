/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:25:06 by ymafaman          #+#    #+#             */
/*   Updated: 2024/12/20 18:00:59 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>

template <typename T>
typename T::iterator    easyfind(T container, int to_find)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), to_find);

    if (it == container.end())
        throw (std::invalid_argument("The number was not found in the container."));

    return it;
}

#endif