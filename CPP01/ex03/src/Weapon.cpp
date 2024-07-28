/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: june <june@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:36:33 by june              #+#    #+#             */
/*   Updated: 2024/07/28 12:23:07 by june             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type) {}

const std::string& Weapon::getType() const
{
    return (type);
}

void Weapon::setType(const std::string &type)
{
    this->type = type;
}
