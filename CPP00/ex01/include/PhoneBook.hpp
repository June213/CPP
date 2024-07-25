/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:32:28 by junesalaber       #+#    #+#             */
/*   Updated: 2024/07/25 10:26:41 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include <iomanip>
#include <string>

class PhoneBook
{
	private:
		Contact contacts[8];
		int	contact_count;
		int total_contacts;
		bool 		getinput_setfield(std::string field, std::string &input);
		std::string adjust_text(std::string text) const;
		void		print_contact_row(int i, std::string fname, std::string lname, std::string nname);
		void		print_contact();
	public:
		PhoneBook();
		void add_contact();
		void search_contact();
		void display_contact(int i) const;
};

bool	is_number(const std::string &s);
int		string_to_int(const std::string &s);

#endif