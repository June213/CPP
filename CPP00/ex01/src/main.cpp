/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:52:07 by junesalaber       #+#    #+#             */
/*   Updated: 2024/07/25 10:20:32 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int	main()
{
	PhoneBook	pb;
	std::string	command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			pb.add_contact();
		else if (command == "SEARCH")
			pb.search_contact();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
