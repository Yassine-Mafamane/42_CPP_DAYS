/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:01:19 by ymafaman          #+#    #+#             */
/*   Updated: 2024/08/17 10:18:41 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM
# define ROBOTOMY_REQUEST_FORM

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

public :

	RobotomyRequestForm( std::string name, std::string target );
	RobotomyRequestForm( const RobotomyRequestForm& ref );

	~RobotomyRequestForm();

	RobotomyRequestForm &operator = ( const RobotomyRequestForm& rhs );

	void	execute( Bureaucrat const & executor ) const;

};


#endif