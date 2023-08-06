/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:07:19 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/06 17:30:29 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <iterator>

class Span
{
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span& other);
		~Span(void);
		
		Span& operator=(const Span& other);

		const std::vector<int> getVector(void) const;
		void addNumber(int newNum);
		int longestSpan(void);
		int shortestSpan(void);
		void addMoreNumbers(const unsigned int n, int start);

		class MaxNumIntegersReached : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class ImpossibleSpan : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
	private:
		std::vector<int> _vec;
		unsigned int _max;
};

#endif