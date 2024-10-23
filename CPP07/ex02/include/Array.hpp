/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:04:51 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/23 10:14:58 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T> class Array
{
	private:
		unsigned int n;
		T* array;
	public:
		Array() : n(0), array(new T[0]) {}
		
		Array(const unsigned int &n) : n(n), array(new T[n])
		{
			for (unsigned int i = 0; i < n; i++)
				array[i] = 0;
		}
		
		Array(const Array<T> &src) : n(src.n), array(new T[src.n])
		{
			for (unsigned int i = 0; i < n; i++)
				array[i] = src.array[i];
		}
		
		Array<T> &operator=(const Array<T> &src)
		{
			if (this != &src)
			{
				delete [] array;
				n = src.n;
				array = new T[n];
				for (unsigned int i = 0; i < n; i++)
					array[i] = src.array[i];
			}
			return (*this);
		}
		
		~Array()
		{
			delete [] this->array;
		}

		T& operator[](int i)
		{
			exception(static_cast<unsigned int>(i));
			return (this->array[i]);
		}
		
		unsigned int size() const
		{
			return (n);
		}
		
		void exception(unsigned int i) const
		{
			if (i >= n)
				throw std::out_of_range("Index out of range.");
		}
};

#endif