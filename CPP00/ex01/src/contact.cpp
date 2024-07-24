/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junesalaberria <junesalaberria@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:32:14 by junesalaber       #+#    #+#             */
/*   Updated: 2024/07/24 13:15:30 by junesalaber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"

void contact::set_first_name(const std::string &fname)
{
	first_name = fname;
}

void contact::set_last_name(const std::string &lname)
{
	last_name = lname;
}

void contact::set_nickname(const std::string &nname)
{
	nickname = nname;
}

void contact::set_phone_number(const std::string &pnumber)
{
	phone_number = pnumber;
}

void contact::set_darkes_secret(const std::string &dsecret)
{
	darkest_secret = dsecret;
}

std::string contact::get_first_name() const
{
	return (first_name);
}

std::string contact::get_last_name() const
{
	return (last_name);
}

std::string contact::get_nickname() const
{
	return (nickname);
}

std::string contact::get_phone_number() const
{
	return (phone_number);
}

std::string contact::get_darkest_secret() const
{
	return (darkest_secret);
}
