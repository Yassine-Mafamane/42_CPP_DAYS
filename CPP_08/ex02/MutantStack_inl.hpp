/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack_inl.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:32:53 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 11:36:00 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_INL_HPP
# define MUTANT_STACK_INL_HPP

#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack( void )
{
    
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack( const MutantStack& ref )
{
    this->stack = ref.stack;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
    
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=( const MutantStack& rhs )
{
    if (this == &rhs)
    {
        return *this;
    }

    this->stack = rhs.stack;
    return *this;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin( void )
{
    return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end( void )
{
    return this->c.end();
}

#endif