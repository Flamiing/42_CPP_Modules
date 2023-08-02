/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:50:30 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/02 15:16:44 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat ivan("Ivan", 1);
	Bureaucrat carlos("Carlos", 45);
	Bureaucrat javi("Javi", 137);
	Bureaucrat loser("Loser", 150);

	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("Wall-E");
	PresidentialPardonForm pardon("Wawawiwa");
	
	std::cout << std::endl;

	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
	
	std::cout << std::endl;

	shrubbery.execute(ivan);
	robotomy.execute(ivan);
	pardon.execute(ivan);
	ivan.executeForm(shrubbery);
	ivan.executeForm(robotomy);
	ivan.executeForm(pardon);

	std::cout << std::endl;

	loser.signForm(shrubbery);
	javi.signForm(shrubbery);
	loser.executeForm(shrubbery);
	javi.executeForm(shrubbery);

	std::cout << std::endl;

	javi.signForm(robotomy);
	carlos.signForm(robotomy);
	javi.executeForm(robotomy);
	carlos.executeForm(robotomy);
	carlos.executeForm(robotomy);

	std::cout << std::endl;

	carlos.signForm(pardon);
	ivan.signForm(pardon);
	carlos.executeForm(pardon);
	ivan.executeForm(pardon);

	std::cout << std::endl;
	
	shrubbery.execute(loser);
	robotomy.execute(loser);
	pardon.execute(loser);

	std::cout << std::endl;

	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;

	std::cout << std::endl;

	return 0;
}