/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:33:21 by ymafaman          #+#    #+#             */
/*   Updated: 2024/12/20 17:58:55 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>

int main()
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(55);
    v.push_back(99);
    v.push_back(1);

    try
    {
        std::vector<int>::iterator    it1 = easyfind(v, 1);
        std::cout << "Found " << *it1 << "." <<std::endl;

        std::vector<int>::iterator    it2 = easyfind(v, 100);
        std::cout << "Found " << *it2 << "." <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
