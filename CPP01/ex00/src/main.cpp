/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:39:00 by jsalaber          #+#    #+#             */
/*   Updated: 2024/07/26 12:16:20 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main()
{
	Zombie	*new_zombie;

	new_zombie = newZombie("Pedro");
	new_zombie->announce();
	delete new_zombie;
	randomChump("Maria");
	return (0);
}
