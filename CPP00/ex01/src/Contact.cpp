/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:32:14 by junesalaber       #+#    #+#             */
/*   Updated: 2024/07/25 10:16:01 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

void Contact::set_first_name(const std::string &fname)
{
	first_name = fname;
}

void Contact::set_last_name(const std::string &lname)
{
	last_name = lname;
}

void Contact::set_nickname(const std::string &nname)
{
	nickname = nname;
}

void Contact::set_phone_number(const std::string &pnumber)
{
	phone_number = pnumber;
}

void Contact::set_darkes_secret(const std::string &dsecret)
{
	darkest_secret = dsecret;
}

std::string Contact::get_first_name() const
{
	return (first_name);
}

std::string Contact::get_last_name() const
{
	return (last_name);
}

std::string Contact::get_nickname() const
{
	return (nickname);
}

std::string Contact::get_phone_number() const
{
	return (phone_number);
}

std::string Contact::get_darkest_secret() const
{
	return (darkest_secret);
}
