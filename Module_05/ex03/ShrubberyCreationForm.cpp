/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:12:23 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/02 15:48:06 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* EXCEPTION */
const char* ShrubberyCreationForm::CannotOpenFileException::what(void) const throw()
{
	return "The file cannot be oppened";
}

/* SUPLEMENTARY FUNCTIONS */
static void fillWithTrees(std::ofstream& output)
{
	output << "               ,@@@@@@@," << std::endl;
	output << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	output << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	output << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	output << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	output << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	output << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	output << "       |o|        | |         | |" << std::endl;
	output << "       |.|        | |         | |" << std::endl;
	output << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
}

/* CONSTRUCTORS /// DESTRUCTOR /// OPERATORS /// MEMBER FUNCTIONS */
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", "none", 145, 137)
{
	if (INFO == 1)
		std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
	if (INFO == 1)
		std::cout << "ShrubberyCreationForm default constructor with info" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	if (INFO == 1)
		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (INFO == 1)
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (INFO == 1)
		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	if (this != &other)
		*this = other;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream output;
	
	try
	{
		if (!this->getSigned())
			throw AForm::NotSignedException();
		if (executor.getGrade() > this->getRequiredGradeExecute())
			throw AForm::GradeTooLowException();
		output.open(this->getTarget() + "_shrubbery", std::ios::out);
		if (!output.is_open())
			throw ShrubberyCreationForm::CannotOpenFileException();
		else
		{
			fillWithTrees(output);
			output.close();
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
