/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 05:39:47 by ymafaman          #+#    #+#             */
/*   Updated: 2024/12/10 03:41:57 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "functions.hpp"

Base * generate(void)
{
    std::srand(static_cast<unsigned>(std::time(0)));

    if ((std::rand() % 3) == 0)
        return (new A());
    else if ((std::rand() % 3) == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p)
{
    A *a = dynamic_cast<A *>(p);
    if (a)
    {
        std::cout << "The type is A." << std::endl;
        return ;
    }
    
    B *b = dynamic_cast<B *>(p);
    if (b)
    {
        std::cout << "The type is B." << std::endl;
        return ;
    }
    
    C *c = dynamic_cast<C *>(p);
    if (c)
    {
        std::cout << "The type is C." << std::endl;
        return ;
    }
    
    std::cout << "Unknown type!" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "The type is A." << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        
    }

    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "The type is B." << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        
    }

    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "The type is C." << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        
    }

    std::cout << "Unknown type!" << std::endl;
}