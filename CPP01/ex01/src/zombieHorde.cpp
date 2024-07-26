/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:48:28 by jsalaber          #+#    #+#             */
/*   Updated: 2024/07/26 13:09:47 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie *zombieHorde(int N, const std::string &name)
{
	Zombie *horde;

	if (N <= 0)
		return (NULL);
	horde = new Zombie[N];
	for (int i = 0; i< N; i++)
		horde[i].setName(name);
	return (horde);
}