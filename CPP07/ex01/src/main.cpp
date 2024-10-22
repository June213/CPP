/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:51:26 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/22 12:02:28 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Iter.hpp"

int main( void )
{
	int a[] = {1, 2, 3, 4, 5};
	int *p = &a[0];
	iter(p, 5, print<int>);

	std::string b[] = {"one", "two", "three", "four", "five"};
	std::string *q = &b[0];
	iter(q, 5, print<std::string>);
	return 0;
}
