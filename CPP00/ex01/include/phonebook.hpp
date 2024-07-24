/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junesalaberria <junesalaberria@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:32:28 by junesalaber       #+#    #+#             */
/*   Updated: 2024/07/24 12:58:09 by junesalaber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "contact.hpp"
#include <iomanip>
#include <string>

class phonebook
{
	private:
		contact contacts[8];
		int	contact_count;
		int total_contacts;
		bool 		getinput_setfield(std::string field, std::string &input);
		std::string adjust_text(std::string text) const;
		void		print_contact_row(int i, std::string fname, std::string lname, std::string nname);
		void		print_contact();
	public:
		phonebook();
		void add_contact();
		void search_contact();
		void display_contact(int i) const;
};

#endif