/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:00:08 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/22 09:55:47 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << "Top: " << mstack.top() << std::endl;
mstack.pop();
std::cout << "Size after pop: " << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);
std::cout << "MutantStack: ";
for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	std::cout << *it << " ";
std::cout << std::endl;
std::cout << "MutantStack size: " << mstack.size() << std::endl;
std::cout << "Stack copy" << std::endl;
std::stack<int> s(mstack);
std::cout << "Copied Stack size: " << s.size() << std::endl;
std::cout << "Coppied Stack top: " << s.top() << std::endl;

std::cout << "Constant mstack: " ;
const MutantStack<int> mstack_const(mstack);
for (MutantStack<int>::const_iterator it = mstack_const.begin(); it != mstack_const.end(); ++it)
    std::cout << *it << " ";
std::cout << std::endl;

return 0;
}