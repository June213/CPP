/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:05:39 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/04 11:33:02 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main() {
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

    return 0;
}



