/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:22:06 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 15:08:30 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM
# define SHRUBBERY_CREATION_FORM

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{

public :

	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm& ref );
	
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator = ( const ShrubberyCreationForm& rhs );

	void	execute( Bureaucrat const & executor ) const;

};



#endif