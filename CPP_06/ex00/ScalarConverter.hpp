/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 00:42:48 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/21 13:10:37 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include "utils.hpp"
#include "convert.hpp"

class ScalarConverter{

public :

    static  void    convert( const std::string& input );

private :

    ScalarConverter( const ScalarConverter& ref );

};



#endif