/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:34:55 by ymafaman          #+#    #+#             */
/*   Updated: 2024/12/23 00:28:24 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>
#include <iostream>
#include <iterator>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>
{

    public :

        typedef typename Container::iterator iterator;

        MutantStack( void );
        MutantStack( const MutantStack& ref );

        ~MutantStack();

        MutantStack& operator=( const MutantStack& rhs );

        iterator begin( void );
        iterator  end( void );

    private :
        std::stack<T> stack;

};

#include "MutantStack_inl.hpp"

#endif