/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataStruct.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:20:54 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/21 17:21:35 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_HPP
# define DATA_STRUCT_HPP

#include <string>

typedef struct Data 
{
    int         raw;
    std::string str;
    float       f;
} Data ;

#endif