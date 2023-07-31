/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:56:37 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/29 21:51:38 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const std::string name, int requiredGradeSign, int requiredGradeExecute);
		Form(const Form& other);
		~Form(void);

		Form& operator=(const Form& other);
	
		const std::string getName(void) const;
		bool getSigned(void) const;
		int getRequiredGradeSign(void) const;
		int getRequiredGradeExecute(void) const;
		void beSigned(const Bureaucrat signer);

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
		bool _signed;
		const int _requiredGradeSign;
		const int _requiredGradeExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif