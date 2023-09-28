/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:56:37 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/02 12:16:48 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

# ifndef INFO
# 	define INFO 0
# endif

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(const std::string name, int requiredGradeSign, int requiredGradeExecute);
		AForm(const std::string name, std::string target, int requiredGradeSign, int requiredGradeExecute);
		AForm(const AForm& other);
		virtual ~AForm(void);

		AForm& operator=(const AForm& other);
	
		const std::string getName(void) const;
		bool getSigned(void) const;
		int getRequiredGradeSign(void) const;
		int getRequiredGradeExecute(void) const;
		void beSigned(const Bureaucrat signer);
		virtual void execute(Bureaucrat const & executor) const = 0;
		const std::string getTarget(void) const;

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
		class NotSignedException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
	private:
		const std::string _name;
		const std::string _target;
		bool _signed;
		const int _requiredGradeSign;
		const int _requiredGradeExecute;
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif