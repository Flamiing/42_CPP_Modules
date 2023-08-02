/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:24:15 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/02 16:56:27 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	if (INFO == 1)
		std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	if (INFO == 1)
		std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern::~Intern(void)
{
	if (INFO == 1)
		std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	if (INFO == 1)
		std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
	return *this;
}

AForm* Intern::newShrubberyCreationForm(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::newRobotomyRequestForm(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::newPresidentialPardonForm(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string formName, const std::string formTarget)
{
	int option = -1;
	
	AForm* (Intern::*formOptions[])(const std::string) =
	{
		&Intern::newShrubberyCreationForm,
		&Intern::newRobotomyRequestForm,
		&Intern::newPresidentialPardonForm
	};
	
	const std::string formNames[] =
	{
		"shrubbery creation",
		"robotomy request", 
		"presidential pardon"
	};
	
	while (option < 3 && !formName.empty() && formName != formNames[option])
		option++;
	switch (option)
	{
		case -1:
			std::cerr << "Form not found, intern could not create it" << std::endl;
			return (NULL);
		case 3:
			std::cerr << "Form not found, intern could not create it" << std::endl;
			return (NULL);
		default:
			std::cout << "Intern creates " << formNames[option] << std::endl;
			if (formTarget.empty())
				return ((this->*formOptions[option])("none"));
			return ((this->*formOptions[option])(formTarget));
	}
}