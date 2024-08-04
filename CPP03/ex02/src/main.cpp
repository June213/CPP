/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:05:39 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/04 12:22:01 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main() {
    // Creación de instancias de ClapTrap
    ClapTrap Pedro("Pedro", true);
    ClapTrap Maria("Maria", true);

    Pedro.setAttackDamage(5);
    Maria.setAttackDamage(3);

    Pedro.attack("Maria");
    Maria.takeDamage(Pedro.getAttackDamage());
    Maria.beRepaired(10);
    Maria.attack("Pedro");
    Pedro.takeDamage(Maria.getAttackDamage());
    Pedro.beRepaired(5);
    std::cout << std::endl;

    ScavTrap Luis("Luis");
    Luis.setAttackDamage(20);
    Luis.attack("Pedro");
    Pedro.takeDamage(Luis.getAttackDamage());
    Luis.guardGate();
    std::cout << std::endl;


    FragTrap Alex("Alex");
    Alex.setAttackDamage(30);
    Alex.attack("Pedro");
    Pedro.takeDamage(Alex.getAttackDamage());
    Alex.highFivesGuys();

    return 0;
}
