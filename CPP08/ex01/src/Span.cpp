/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:33:51 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/20 12:09:09 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span() : _maxn(0){}

Span::Span(unsigned int n) : _maxn(n){}

Span::Span(Span const & src)
{
	_numbers = src._numbers;
	_maxn = src._maxn;
}

Span &Span::operator=(Span const & src)
{
	if (this != &src)
	{
		this->_numbers = src._numbers;
		this->_maxn = src._maxn;
	}
	return (*this);
}

Span::~Span(){}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxn)
		throw SpanFull();
	_numbers.push_back(n);
}

void Span::addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _maxn)
		throw SpanFull();
	_numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw SpanNotFound();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw SpanNotFound();
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}
