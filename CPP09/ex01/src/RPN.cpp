/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:44:01 by jsalaber          #+#    #+#             */
/*   Updated: 2024/12/10 09:50:06 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN &RPN::operator=(RPN const &src)
{
	if (this != &src)
		_stack = src._stack;
	return (*this);
}

RPN::~RPN(void) {}

bool RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

int RPN::performOperation(int a, int b, char op)
{
	switch (op)
	{
		case '+' : return (a + b);
		case '-' : return (a - b);
		case '*' : return (a * b);
		case '/' :
			if (b == 0)
				throw std::runtime_error("Error: Division by zero");
			return (a / b);
		default : throw std::runtime_error("Error: Invalid operator");
	}
}

int RPN::evaluate(const std::string &expr)
{
	clearStack();
	for (size_t i = 0; i < expr.length(); ++i)
	{
		char c = expr[i];
		if (std::isspace(c))
			continue ;
		if (std::isdigit(c))
			pushStack(c - '0');
		else if (isOperator(c))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: Not enough operands");
			int b = topStack();
			_stack.pop();
			int a = topStack();
			_stack.pop();
			pushStack(performOperation(a, b, c));
		}
		else
			throw std::runtime_error("Error: Invalid character");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: Not enough operators to combine all operands.");
	return topStack();
}

void RPN::pushStack(int n)
{
	_stack.push(n);
}

int RPN::topStack(void)
{
	if (_stack.empty())
		throw std::runtime_error("Error: Empty stack");
	return (_stack.top());
}

void RPN::clearStack(void)
{
	while (!_stack.empty())
		_stack.pop();
}
