/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:20:59 by jsalaber          #+#    #+#             */
/*   Updated: 2024/12/10 09:21:01 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "Usage: ./pmergeMe [num1] [num2] [num3] ..." << std::endl;
            return (1);
        }

        PmergeMe sort(argv);
        sort.printnumbers();
        sort.sortAndMeasure();
        sort.printResult();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}