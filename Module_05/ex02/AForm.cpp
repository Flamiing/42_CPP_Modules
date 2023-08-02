/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:56:42 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/29 20:12:23 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* EXCEPTION */
const char* AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade is higher than expected!";
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade is lower than expected!";
}

const char* AForm::NotSignedException::what(void) const throw()
{
	return "The form is not signed";
}

/* CONSTRUCTORS /// DESTRUCTOR /// OPERATORS /// MEMBER FUNCTIONS */
AForm::AForm(void) : _name("unknown"), _target("none"), _signed(false), _requiredGradeSign(1), _requiredGradeExecute(1)
{
	if (INFO == 1)
		std::cout << "AForm default constructor called with info" << std::endl;
}

AForm::AForm(const std::string name, const int requiredGradeSign, const int requiredGradeExecute) : 
_name(name), _target("none"), _signed(false), _requiredGradeSign(requiredGradeSign), _requiredGradeExecute(requiredGradeExecute)
{
	if (INFO == 1)
		std::cout << "AForm copy constructor called" << std::endl;
	try
	{
		if (requiredGradeSign < 1)
			throw AForm::GradeTooHighException();
		else if (requiredGradeSign > 150)
			throw AForm::GradeTooLowException();
		if (requiredGradeExecute < 1)
			throw AForm::GradeTooHighException();
		else if (requiredGradeExecute > 150)
			throw AForm::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

AForm::AForm(const std::string name, std::string target, const int requiredGradeSign, const int requiredGradeExecute) : 
_name(name), _target(target), _signed(false), _requiredGradeSign(requiredGradeSign), _requiredGradeExecute(requiredGradeExecute)
{
	if (INFO == 1)
		std::cout << "AForm copy constructor called" << std::endl;
	try
	{
		if (requiredGradeSign < 1)
			throw AForm::GradeTooHighException();
		else if (requiredGradeSign > 150)
			throw AForm::GradeTooLowException();
		if (requiredGradeExecute < 1)
			throw AForm::GradeTooHighException();
		else if (requiredGradeExecute > 150)
			throw AForm::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

AForm::AForm(const AForm& other) : _name(other._name), _target(other._target),
_signed(other._signed), _requiredGradeSign(other._requiredGradeSign), _requiredGradeExecute(other._requiredGradeExecute)
{
	if (INFO == 1)
		std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
	if (INFO == 1)
		std::cout << "AForm destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (INFO == 1)
		std::cout << "AForm constructor with name and grade called" << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

const std::string AForm::getName(void) const
{
	return this->_name;
}

const std::string AForm::getTarget(void) const
{
	return this->_target;
}

bool AForm::getSigned(void) const
{
	return this->_signed;
}

int AForm::getRequiredGradeSign(void) const
{
	return this->_requiredGradeSign;
}

int AForm::getRequiredGradeExecute(void) const
{
	return this->_requiredGradeExecute;
}

void AForm::beSigned(const Bureaucrat signer)
{
	try
	{
		if (signer.getGrade() <= this->getRequiredGradeSign())
			this->_signed = true;
		else
			throw AForm::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm) 
{
    out << "The AForm " << AForm.getName() << ", with " << AForm.getTarget()
			<< " as target, requieres a grade " << AForm.getRequiredGradeSign()
			<< " to sign, a grade " << AForm.getRequiredGradeExecute() << " to execute and is ";
	if (AForm.getSigned())
		out << "signed";
	else
		out << "not signed";
    return out;
}