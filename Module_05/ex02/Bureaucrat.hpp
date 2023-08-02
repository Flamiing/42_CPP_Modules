/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:50:29 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/02 15:14:08 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);
		
		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm& form);
		void executeForm(AForm const & form);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif