/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:06:40 by ymafaman          #+#    #+#             */
/*   Updated: 2024/12/09 22:04:57 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>

int is_a_single_char( const std::string& input )
{      
    if ((input.length() == 1) && (input[0] < '0' || input[0] > '9'))
        return (1);

    return (0);
}

bool is_an_int( const std::string& input )
{
    size_t i = 0;

    if (input[0] == '-' || input[i] == '+')
        i++;

    for ( ; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]))
            return (false);
    }

    return (true);
}

bool    is_a_float( const std::string& input )
{
    size_t period_pos;
    size_t f_pos;
    
    period_pos = input.find('.');
    f_pos = input.find('f');

    if (input == NEG_FLOAT_INF || input == FLOAT_INF || input == NOT_A_FLOAT || input == NEG_NOT_A_FLOAT || input == POS_NOT_A_FLOAT || input == POS_FLOAT_INF)
        return (true);

    if ((f_pos != input.length() - 1) || (input.find('f', f_pos + 1) != std::string::npos) || (input[f_pos - 1] == '.') || (period_pos == 0) || (input.find('.', period_pos + 1) != std::string::npos))
    {
        return (false);
    }

    size_t i = 0;
        
    if (input[0] == '-' || input[0] == '+')
        i++;
    
    for ( ; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
            return (false);
    }

    return (true);
}

bool    is_a_double( const std::string& input )
{
    size_t period_pos;

    if (input == NEG_DOUBLE_INF || input == DOUBLE_INF || input == NOT_A_DOUBLE 
        || input == POS_DOUBLE_INF || input == POS_NOT_A_DOUBLE || input == NEG_NOT_A_DOUBLE)
            return (true);

    period_pos = input.find('.');

    if ((period_pos == 0) || (period_pos == input.length() - 1) || (input.find('.', period_pos + 1) != std::string::npos))
    {
        return (false);
    }

    size_t i = 0;

    if (input[0] == '-' || input[0] == '+')
        i++;

    for ( ; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]) && input[i] != '.')
            return (false);
    }

    return (true);
}


std::string identify_type( const std::string& input )
{
    if (is_a_single_char(input))
        return ("Char");
    else if (is_an_int(input))
        return ("Int");
    else if (is_a_float(input))
        return ("Float");
    else if (is_a_double(input))
        return ("Double");
    else
        return ("Wrong type");
}
