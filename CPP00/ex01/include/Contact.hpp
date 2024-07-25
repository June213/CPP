/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:32:10 by junesalaber       #+#    #+#             */
/*   Updated: 2024/07/25 10:15:34 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void set_first_name(const std::string &fname);
		void set_last_name(const std::string &lname);
		void set_nickname(const std::string &nname);
		void set_phone_number(const std::string &pnumber);
		void set_darkes_secret(const std::string &dsecret);
		
		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_phone_number() const;
		std::string get_darkest_secret() const;	
};

#endif