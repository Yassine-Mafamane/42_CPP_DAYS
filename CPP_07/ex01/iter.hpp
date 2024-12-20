/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:11:42 by ymafaman          #+#    #+#             */
/*   Updated: 2024/12/20 16:45:23 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename U>
void    iter(T array, size_t size, U f)
{
    for (size_t i = 0; i < size; i++)
        f(array[i]);
}

#endif