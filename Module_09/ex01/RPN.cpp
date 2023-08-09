/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:58:38 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/09 02:19:56 by alaaouam         ###   ########.fr       */
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

	if (expression.empty())
		return false;
	while (pos < expression.length())
	{
		if (expression[pos] == ' ')
			spaceCount++;
		if (spaceCount > 1)
			return false;
		if (expression[pos] != ' ')
			spaceCount = 0;
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

static float sum(const float *operands, const size_t size)
{
	float result;
	size_t pos = 0;
	
	while (pos < size)
	{
		if (pos == 0)
			result = operands[pos];
		else
			result = result + operands[pos];
		pos++;
	}
	return result;
}

static float subtract(const float *operands, const size_t size)
{
	float result;
	size_t pos = 0;
	
	while (pos < size)
	{
		if (pos == 0)
			result = operands[pos];
		else
			result = result - operands[pos];
		pos++;
	}
	return result;
}

static float multiply(const float *operands, const size_t size)
{
	float result;
	size_t pos = 0;
	
	while (pos < size)
	{
		if (pos == 0)
			result = operands[pos];
		else
			result = result * operands[pos];
		pos++;
	}
	return result;
}

static float divide(const float *operands, const size_t size)
{
	float result;
	size_t pos = 0;
	
	while (pos < size)
	{
		if (pos == 0)
			result = operands[pos];
		else
			result = result / operands[pos];
		pos++;
	}
	return result;
}

static float evaluateExpression(const std::string& expression)
{
	std::stack<float> stack;
	std::istringstream iss(expression);
 	std::string token;
	size_t operandCount = 0;
	ssize_t pos;
	float *operands;

	 while (iss >> token)
	 {
		if (isNumber(token[0]))
			stack.push(std::atof(token.c_str()));
		else
		{
			operandCount = stack.size();
			operands = new float[operandCount];
			pos = operandCount - 1;
			while (pos >= 0)
			{
				operands[pos] = stack.top();
				stack.pop();
				pos--;
			}
			if (isOperator(token[0]))
			{
				if (token == "+")
					stack.push(sum(operands, operandCount));
				else if (token == "-")
					stack.push(subtract(operands, operandCount));
				else if (token == "*")
					stack.push(multiply(operands, operandCount));
				else if (token == "/")
					stack.push(divide(operands, operandCount));
				operandCount = 0;
				delete[] operands;
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