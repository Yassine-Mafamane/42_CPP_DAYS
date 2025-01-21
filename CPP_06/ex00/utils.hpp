/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:12:46 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/21 16:41:46 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <limits.h>
#include <string>

#define NEG_FLOAT_INF "-inff"
#define POS_FLOAT_INF "+inff"
#define FLOAT_INF "inff"
#define NOT_A_FLOAT "nanf"
#define POS_NOT_A_FLOAT "+nanf"
#define NEG_NOT_A_FLOAT "-nanf"

#define NEG_DOUBLE_INF "-inf"
#define DOUBLE_INF "inf"
#define POS_DOUBLE_INF "+inf"
#define NOT_A_DOUBLE "nan"
#define POS_NOT_A_DOUBLE "+nan"
#define NEG_NOT_A_DOUBLE "-nan"

#define IMPOSSIBLE_CONVERTION "impossible"

#define NON_DISP "Non displayable"

std::string identify_type( const std::string& input );

#endif