/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:58:38 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/09 02:59:42 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* CONSTRUCTORS /// DESTRUCTOR /// OPERATOR */
RPN::RPN(void) {}

RPN::RPN(const RPN& other) { (void)other; }

RPN::~RPN(void) {}

RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }

/* FUNCTIONS */
static bool error(void)
{
	std::cout << "Error" << std::endl;
	return false;
}

static bool isNumber(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

static bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

static bool invalidNumber(const std::string& expression, size_t& pos)
{
	if (pos > 0)
	{
		if (isNumber(expression[pos - 1]) && isNumber(expression[pos])
			&& expression[pos] != '1')
			return true;
		else if (isNumber(expression[pos - 1]) && isNumber(expression[pos])
					&& expression[pos - 1] == '1' && expression[pos] != '0')
			return true;
	}
	return false;
}

static bool parseExpression(const std::string& expression)
{
	size_t pos = 0;
	int spaceCount = 0;
	int	operandCount = 0;

	if (expression.empty())
		return false;
	while (pos < expression.length())
	{
		if (expression[pos] == ' ')
			spaceCount++;
		if (isOperator(expression[pos]))
			operandCount = 0;
		if (spaceCount > 1)
			return false;
		if (expression[pos] != ' ')
			spaceCount = 0;
		if (isNumber(expression[pos]))
			operandCount++;
		if (operandCount > 2)
			return false;
		if (invalidNumber(expression, pos))
			return false;
		if (pos == 0 && isOperator(expression[pos]))
			return false;
		if (pos == expression.length() - 1 && !isOperator(expression[pos]))
			return false;
		if (expression[pos] != ' ' && !isNumber(expression[pos])
			&& !isOperator(expression[pos]))
			return false;
		if (isOperator(expression[pos])
			&& (pos + 1) != expression.length()
			&& isOperator(expression[pos + 1]))
			return false;
		pos++;
	}
	return true;
}

static float evaluateExpression(const std::string& expression)
{
	std::stack<float> stack;
	std::istringstream iss(expression);
 	std::string token;
	float operands[2];

	 while (iss >> token)
	 {
		if (isNumber(token[0]))
			stack.push(std::atof(token.c_str()));
		else
		{
			operands[1] = stack.top();
			stack.pop();
			operands[0] = stack.top();
			stack.pop();
			if (isOperator(token[0]))
			{
				if (token == "+")
					stack.push(operands[0] + operands[1]);
				else if (token == "-")
					stack.push(operands[0] - operands[1]);
				else if (token == "*")
					stack.push(operands[0] * operands[1]);
				else if (token == "/")
					stack.push(operands[0] / operands[1]);
			}
		}
	 }
	 return stack.top();
}

bool RPN::reversePolishNotation(const std::string& expression, float& result)
{
	if (!parseExpression(expression))
		return error();
	
	result = evaluateExpression(expression);
	return true;
}