/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:56:42 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/29 20:12:23 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is higher than expected!";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is lower than expected!";
}

Form::Form(void) : _name("unknown"), _signed(false), _requiredGradeSign(1), _requiredGradeExecute(1)
{
	if (INFO == 1)
		std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int requiredGradeSign, const int requiredGradeExecute) : 
_name(name), _signed(false), _requiredGradeSign(requiredGradeSign), _requiredGradeExecute(requiredGradeExecute)
{
	if (INFO == 1)
		std::cout << "Form copy constructor called" << std::endl;
	try
	{
		if (requiredGradeSign < 1)
			throw Form::GradeTooHighException();
		else if (requiredGradeSign > 150)
			throw Form::GradeTooLowException();
		if (requiredGradeExecute < 1)
			throw Form::GradeTooHighException();
		else if (requiredGradeExecute > 150)
			throw Form::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _requiredGradeSign(other._requiredGradeSign), _requiredGradeExecute(other._requiredGradeExecute)
{
	if (INFO == 1)
		std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void)
{
	if (INFO == 1)
		std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (INFO == 1)
		std::cout << "Form constructor with name and grade called" << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

const std::string Form::getName(void) const
{
	return this->_name;
}

bool Form::getSigned(void) const
{
	return this->_signed;
}

int Form::getRequiredGradeSign(void) const
{
	return this->_requiredGradeSign;
}

int Form::getRequiredGradeExecute(void) const
{
	return this->_requiredGradeExecute;
}

void Form::beSigned(const Bureaucrat signer)
{
	try
	{
		if (signer.getGrade() <= this->getRequiredGradeSign())
			this->_signed = true;
		else
			throw Form::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Form& form) 
{
    out << "The Form " << form.getName() << " requieres a grade " << form.getRequiredGradeSign()
			<< " to sign, a grade " << form.getRequiredGradeExecute() << " to execute and is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
    return out;
}