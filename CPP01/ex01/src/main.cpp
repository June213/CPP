/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:54:19 by jsalaber          #+#    #+#             */
/*   Updated: 2024/07/26 13:06:04 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main()
{
	Zombie *horde;
	
	horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete [] horde;
}
