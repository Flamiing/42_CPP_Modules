/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:58:15 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/09 01:10:24 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <stack>

class RPN
{
	public:
		static bool reversePolishNotation(const std::string& expression, float& result);
	private:
		RPN(void);
		RPN(const RPN& other);
		~RPN(void);
		
		RPN& operator=(const RPN& other);
};

#endif