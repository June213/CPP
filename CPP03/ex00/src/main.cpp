/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:05:39 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/04 10:07:12 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main()
{
    ClapTrap Pedro("Pedro");
    ClapTrap Maria("Maria");

    Pedro.setAttackDamage(3);
    Maria.setAttackDamage(4);

    Pedro.attack("Maria");
    Maria.takeDamage(Pedro.getAttackDamage());
    Maria.beRepaired(3);
    Maria.attack("Pedro");
    Pedro.takeDamage(Maria.getAttackDamage());
    Pedro.beRepaired(3);

    return 0;
}

