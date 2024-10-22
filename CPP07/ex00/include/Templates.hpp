/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:35:56 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/22 11:39:09 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T min(T &a, T &b)
{
	return (a < b ? a : b);
}

template <typename T> T max(T &a, T &b)
{
	return (a > b ? a : b);
}