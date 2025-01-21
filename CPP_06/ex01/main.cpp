/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 03:39:20 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/21 17:24:36 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data d = {1337, "hello, World!", 3.14};

    Data *ptr = &d;

    uintptr_t res = Serializer::serialize(ptr);
    Data *d1 = Serializer::deserialize(res);

    std::cout << d1->raw << std::endl;
    std::cout << d1->str << std::endl;
    std::cout << d1->f << std::endl;

    return 0;
}
