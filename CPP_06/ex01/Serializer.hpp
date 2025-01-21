/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 03:32:50 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/21 17:21:59 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP


# include <iostream>
# include <string>
# include "DataStruct.hpp"

class Serializer{

public :

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private :

    Serializer( const Serializer& ref );

};


#endif