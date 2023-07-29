/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:50:30 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/29 17:49:43 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat tom("Tom", 150);
	Bureaucrat carla("Carla", 1);
	Bureaucrat ivan("Ivan", 43);
	Bureaucrat albert("Albert", 151);
	Bureaucrat john("John", 0);
	Bureaucrat carlaCopy(carla);
	Bureaucrat tomCopy = tom;

	tomCopy.decrementGrade();
	carlaCopy.incrementGrade();

	std::cout << carlaCopy.getName() << " has a grade of " << carlaCopy.getGrade() << std::endl;
	std::cout << tomCopy.getName() << " has a grade of " << tomCopy.getGrade() << std::endl;
	
	std::cout << ivan << std::endl;
	ivan.decrementGrade();
	std::cout << ivan << std::endl;
	ivan.incrementGrade();
	std::cout << ivan << std::endl;
	
	return 0;
}