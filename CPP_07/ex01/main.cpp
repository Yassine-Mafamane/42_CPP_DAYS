/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:23:23 by ymafaman          #+#    #+#             */
/*   Updated: 2024/12/20 17:02:17 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << " ";
  return;
}

#include <vector>

int main() {

    int tab[] = { 0, 1, 2, 3, 4 };
    Awesome tab2[5];
    std::vector<int> vec;

    vec.push_back(6);
    vec.push_back(9);

    std::cout << "Vector content : ";
    iter( vec, 2, &print<const int> );
    std::cout << std::endl;
    std::cout << "tab content : ";
    iter( tab, 5, print<int> );
    std::cout << std::endl;
    std::cout << "tab2 content : ";
    iter( tab2, 5, print<Awesome> );

  return 0;
}
