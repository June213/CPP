/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junesalaberria <junesalaberria@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:32:20 by junesalaber       #+#    #+#             */
/*   Updated: 2024/07/24 13:15:16 by junesalaber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

phonebook::phonebook(): contact_count(0), total_contacts(0) {}

bool	phonebook::getinput_setfield(std::string field, std::string &input)
{
	std:: cout << "Enter " << field << ": ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Field cannot be empty" << std::endl;
		return (false);
	}
	return (true);
}

void phonebook::add_contact()
{
	contact new_contact;
	std::string input;

	while (!getinput_setfield("First Name", input))
		;
	new_contact.set_first_name(input);
	while (!getinput_setfield("Last Name", input))
		;
	new_contact.set_last_name(input);
	while (!getinput_setfield("Nickname", input))
		;
	new_contact.set_nickname(input);
	while (!getinput_setfield("Phone Number", input))
		;
	new_contact.set_phone_number(input);
	while (!getinput_setfield("Darkest Secret", input))
		;
	new_contact.set_darkes_secret(input);
	contacts[contact_count] = new_contact;
	contact_count = (contact_count + 1) % 8;
	if (total_contacts < 8)
		total_contacts++;
}
std::string phonebook::adjust_text(std::string text) const
{
	if (text.length() > 10)
		return (text.substr(0, 9) + ".");
	return (text);
}

void phonebook::print_contact_row(int i, std::string fname, std::string lname, std::string nname)
{
	std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << adjust_text(fname) << "|"
				<< std::setw(10) << adjust_text(lname) << "|"
				<< std::setw(10) << adjust_text(nname) << std::endl;		
}

void phonebook::print_contact()
{
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "NickName" << std::endl;
	for (int i = 0; i < total_contacts; i++)
		print_contact_row(i, contacts[i].get_first_name(), contacts[i].get_last_name(), contacts[i].get_nickname());
}

void phonebook::display_contact(int i) const
{
	std::cout << "First Name: " << contacts[i].get_first_name() << std::endl;
	std::cout << "Last Name: " << contacts[i].get_last_name() << std::endl;
	std::cout << "NickName: " << contacts[i].get_nickname() << std::endl;
	std::cout << "Phone Number: " << contacts[i].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contacts[i].get_darkest_secret() << std::endl;
}

void phonebook::search_contact()
{
	int	index;
	
	print_contact();
	std::cout << "Enter index of the contact you want to display: ";
	std::cin >> index;
	if (index >= 0 && index < total_contacts)
		display_contact(index);
	else
		std::cout << "Invalid index" << std::endl;
	
}
