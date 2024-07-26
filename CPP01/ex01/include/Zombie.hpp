/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:28:58 by jsalaber          #+#    #+#             */
/*   Updated: 2024/07/26 13:08:31 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		Zombie(std::string &name);
		~Zombie (void);
		void announce (void);
		void setName(std::string name);
};

Zombie *zombieHorde(int N, const std::string &name);

#endif
