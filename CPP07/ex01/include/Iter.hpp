/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:47:32 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/22 12:02:18 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T> void print(T &value)
{
	std::cout << value << std::endl;
}

template <typename T, typename F> void iter(T *array, int length, F function)
{
	for (int i = 0; i < length; i++)
		function(array[i]);
}
