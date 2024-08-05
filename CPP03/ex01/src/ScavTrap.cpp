/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:13:39 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/05 10:34:34 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, false)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << getName() << " was created:" << std::endl;
	std::cout << _hitPoints << " hit points" << std::endl;
	std::cout << _energyPoints << " energy points" << std::endl;
	std::cout << _attackDamage << " attack damage" << std::endl;
	std::cout << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " was destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints -= 1;
		std::cout << "ScavTrap " << getName() << " attacks "
			<< target << ", causing " << _attackDamage 
			<< " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << getName() << " is out of energy points!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << getName() << " has entered in Gate keeper mode!" << std::endl;
}
