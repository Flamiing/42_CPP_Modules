/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:50:27 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/29 17:45:47 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is higher than expected!";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is lower than expected!";
}

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(150)
{
	if (INFO == 1)
		std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (INFO == 1)
		std::cout << "Bureaucrat constructor with name and grade called" << std::endl;
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade = grade;
	}
	catch (std::exception & e)
	{
		this->_grade = 150;
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	if (INFO == 1)
		std::cout << "Bureaucrat copy constructor called" << std::endl;
	try
	{
		if (other._grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (other._grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade = other._grade;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(void)
{
	if (INFO == 1)
		std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (INFO == 1)
		std::cout << "Bureaucrat copy assingment operator called" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

const std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) 
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
