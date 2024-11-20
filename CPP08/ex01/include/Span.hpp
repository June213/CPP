/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:27:50 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/20 12:03:35 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span
{
	private:
		std::vector<int> _numbers;
		unsigned int _maxn;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const & src);
		Span & operator=(Span const & src);
		~Span();

		void addNumber(int n);
		void addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();

		class SpanFull : public std::exception
		{
			const char* what() const throw()
			{
				return ("Span is full.");
			}
		};
		
		class SpanNotFound : public std::exception
		{
			const char* what() const throw()
			{
				return ("Span not found.");
			}
		};
};

#endif