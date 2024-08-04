/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:42:22 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/04 12:27:50 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, false)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << getName() << " created:" << std::endl;
	std::cout << getName() << " has " << _attackDamage << " attack damage" << std::endl;
	std::cout << getName() << " has " <<_energyPoints << " energy points" << std::endl;
	std::cout << getName() << " has " << _hitPoints << " hit points" << std::endl;
	std::cout << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " destructed" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints -= 1;
		std::cout << "FragTrap " << getName() << " attacks "
			<< target << ", causing " << _attackDamage 
			<< " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << getName() << " is out of energy points!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " wants to high five!" << std::endl;
}