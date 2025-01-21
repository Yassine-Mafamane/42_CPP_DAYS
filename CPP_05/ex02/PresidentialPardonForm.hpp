/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:24:10 by ymafaman          #+#    #+#             */
/*   Updated: 2024/09/20 15:15:42 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM


#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

public :

	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( const PresidentialPardonForm& ref );
	
	~PresidentialPardonForm();

	PresidentialPardonForm &operator = ( const PresidentialPardonForm& rhs );

	void	execute( Bureaucrat const & executor ) const;

};

#endif