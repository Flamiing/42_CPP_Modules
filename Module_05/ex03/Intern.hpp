/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:24:28 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/02 16:26:20 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& other);
		~Intern(void);
		
		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string formName, const std::string formTarget);
		AForm* newShrubberyCreationForm(const std::string target);
		AForm* newRobotomyRequestForm(const std::string target);
		AForm* newPresidentialPardonForm(const std::string target);
	private:	
};

#endif