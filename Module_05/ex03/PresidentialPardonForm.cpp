/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:12:56 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/02 14:36:58 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* CONSTRUCTORS /// DESTRUCTOR /// OPERATORS /// MEMBER FUNCTIONS */
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", "none", 25, 5)
{
	if (INFO == 1)
		std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", target, 25, 5)
{
	if (INFO == 1)
		std::cout << "PresidentialPardonForm default constructor with info" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	if (INFO == 1)
		std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (INFO == 1)
		std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (INFO == 1)
		std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	if (this != &other)
		*this = other;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!this->getSigned())
			throw AForm::NotSignedException();
		if (executor.getGrade() > this->getRequiredGradeExecute())
			throw AForm::GradeTooLowException();
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}