/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:05:33 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/04 11:33:55 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name, bool print)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " was created:" << std::endl;
	if (print)
	{
		std::cout << _hitPoints << " hit points" << std::endl;
		std::cout << _energyPoints << " energy points" << std::endl;
		std::cout << _attackDamage << " attack damage" << std::endl;
		std::cout << std::endl;
	}
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " was destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints -= 1;
		std::cout << "Clap Trap " << _name << " attacks "
			<< target << ", causing " << _attackDamage 
			<< " points of damage!" << std::endl;
	}
	else
		std::cout << "Clap Trap " << _name << "is out of energy points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "Clap Trap " << _name << " is dead!" << std::endl;
		return ;
	}
	else 
		_hitPoints -= amount;
	std::cout << "Clap Trap " << _name << " takes " << amount << " points of damage!" << std::endl;
	std::cout << "Clap Trap " << _name << " has " << _hitPoints << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints -= 1;
		_hitPoints += amount;
		std::cout << "Clap Trap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
		std::cout << "Clap Trap " << _name << " has " << _hitPoints << " hit points!" << std::endl;
	}
	else
		std::cout << "Clap Trap " << _name << "is out of energy points!" << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (_name);
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	_attackDamage = amount;
}
