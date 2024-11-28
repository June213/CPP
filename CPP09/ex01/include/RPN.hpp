/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:40:55 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/28 11:26:49 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <exception>
#include <cctype> // isspace isdigit
#include <cstdlib> // atoi

class RPN
{
	private:
		std::stack<int> _stack;
		bool isOperator(char c);
		int performOperation(int a, int b, char op);
		void pushStack(int n);
		int topStack();
		void clearStack();
	
	public:
		RPN();
		RPN(RPN const &src);
		RPN &operator=(RPN const &src);
		~RPN();
		int evaluate(const std::string &expr);
};

#endif