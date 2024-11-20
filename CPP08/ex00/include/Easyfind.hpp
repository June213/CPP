/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:13:51 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/20 10:15:51 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class ValueNotFound : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Value not found in container.");
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw ValueNotFound();
	return (it);
}

#endif
