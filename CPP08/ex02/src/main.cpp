/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:00:08 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/21 11:14:48 by jsalaber         ###   ########.fr       */
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
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::cout << "MutantStack size: " << mstack.size() << std::endl;
std::stack<int> s(mstack);
std::cout << "Copied Stack size: " << s.size() << std::endl;
std::cout << "Coppied Stack top: " << s.top() << std::endl;
return 0;
}