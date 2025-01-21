/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 05:39:05 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/09 06:09:37 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int main()
{
    Base *ptr1 = generate();
    Base *ptr2 = generate();
    Base *ptr3 = generate();

    Base &ref1 = *ptr1;
    Base &ref2 = *ptr2;
    Base &ref3 = *ptr3;

    identify(ptr1);
    identify(ptr2);
    identify(ptr3);

    identify(ref1);
    identify(ref2);
    identify(ref3);

    delete ptr1;
    delete ptr2;
    delete ptr3;

}