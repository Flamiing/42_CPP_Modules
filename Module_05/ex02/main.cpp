/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:50:30 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/02 14:52:41 by alaaouam         ###   ########.fr       */
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

	shrubbery.execute(ivan);
	robotomy.execute(ivan);
	pardon.execute(ivan);

	std::cout << std::endl;

	loser.signForm(shrubbery);
	javi.signForm(shrubbery);
	shrubbery.execute(loser);
	shrubbery.execute(javi);

	std::cout << std::endl;

	javi.signForm(robotomy);
	carlos.signForm(robotomy);
	robotomy.execute(javi);
	robotomy.execute(carlos);
	robotomy.execute(carlos);

	std::cout << std::endl;

	carlos.signForm(pardon);
	ivan.signForm(pardon);
	pardon.execute(carlos);
	pardon.execute(ivan);

	std::cout << std::endl;

	return 0;
}