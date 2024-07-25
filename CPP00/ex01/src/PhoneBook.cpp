/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:32:20 by junesalaber       #+#    #+#             */
/*   Updated: 2024/07/25 10:34:29 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(): contact_count(0), total_contacts(0) {}

bool	PhoneBook::getinput_setfield(std::string field, std::string &input)
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

void PhoneBook::add_contact()
{
	Contact new_contact;
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
std::string PhoneBook::adjust_text(std::string text) const
{
	if (text.length() > 10)
		return (text.substr(0, 9) + ".");
	return (text);
}

void PhoneBook::print_contact_row(int i, std::string fname, std::string lname, std::string nname)
{
	std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << adjust_text(fname) << "|"
				<< std::setw(10) << adjust_text(lname) << "|"
				<< std::setw(10) << adjust_text(nname) << std::endl;		
}

void PhoneBook::print_contact()
{
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "NickName" << std::endl;
	for (int i = 0; i < total_contacts; i++)
		print_contact_row(i, contacts[i].get_first_name(), contacts[i].get_last_name(), contacts[i].get_nickname());
}

void PhoneBook::display_contact(int i) const
{
	std::cout << "First Name: " << contacts[i].get_first_name() << std::endl;
	std::cout << "Last Name: " << contacts[i].get_last_name() << std::endl;
	std::cout << "NickName: " << contacts[i].get_nickname() << std::endl;
	std::cout << "Phone Number: " << contacts[i].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contacts[i].get_darkest_secret() << std::endl;
}

bool is_number(const std::string &s)
{
    std::size_t i = 0;

    if (s[i] == '-')
	{
        if (s.size() == 1)
		{
            return false;
        }
        ++i;
    }
    while (i < s.size())
	{
        if (!std::isdigit(s[i]))
            return false;
        ++i;
    }
    return true;
}

int string_to_int(const std::string &s)
{
    int number = 0;
    std::size_t i = 0;

    if (s[i] == '-')
        i = 1;
    while (i < s.size())
	{
        number = number * 10 + (s[i] - '0');
        ++i;
    }
    if (s[0] == '-')
        number = -number;
    return number;
}

void PhoneBook::search_contact()
{
	std::string	input;
	int			index;
	
	print_contact();
	while (1)
	{
		std::cout << "Enter index of the contact you want to display or BACK to exit: ";
		std::getline(std::cin, input);
		if (input == "BACK")
			break;
		if (is_number(input))
		{
			index = string_to_int(input);
			if (index >= 0 && index < total_contacts)
				display_contact(index);
			else
				std::cout << "Invalid index" << std::endl;
		}
		else
			std::cout << "Invalid input" << std::endl;
	}
	
}
