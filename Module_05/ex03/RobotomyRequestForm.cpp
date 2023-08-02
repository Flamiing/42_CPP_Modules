/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:12:43 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/02 14:37:01 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* CONSTRUCTORS /// DESTRUCTOR /// OPERATORS /// MEMBER FUNCTIONS */
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", "none", 72, 45)
{
	if (INFO == 1)
		std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
	if (INFO == 1)
		std::cout << "RobotomyRequestForm default constructor with info" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	if (INFO == 1)
		std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (INFO == 1)
		std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (INFO == 1)
		std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	if (this != &other)
		*this = other;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static int count = 0;

	try
	{
		if (!this->getSigned())
			throw AForm::NotSignedException();
		if (executor.getGrade() > this->getRequiredGradeExecute())
			throw AForm::GradeTooLowException();
		std::cout << "* OBNOXIOUS DRILLING NOISES *" << std::endl;
		if (count % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized" << std::endl;
		else
			std::cout << this->getTarget() << " failed to be robotomized" << std::endl;
		count++;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}