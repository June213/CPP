/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:29:37 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/22 09:43:03 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include "../include/Data.hpp"

int main()
{
	Data data;
	data.n = 42;
	

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << " Serialized ptr: " << raw << std::endl;

	Data *deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized ptr: " << deserialized << std::endl;

	if (deserialized == &data)
	{
		std::cout << "Data is the same\n";
		std::cout << "Data.n: " << deserialized->n << std::endl;
	}
	else
		std::cout << "Data is not the same\n";
	return 0;
}