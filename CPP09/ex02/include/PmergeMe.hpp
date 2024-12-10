/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:20:47 by jsalaber          #+#    #+#             */
/*   Updated: 2024/12/10 09:52:08 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <sstream>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        double _timeVec;
        double _timeDeq;
        void mergeInsterSortVector(int begin, int end);
        void mergeInsterSortDeque(int begin, int end);
        void mergeVector(int begin, int middle, int end);
        void mergeDeque(int begin, int middle, int end);
        void insertSortVector(int begin, int end);
        void insertSortDeque(int begin, int end);
    public:
        PmergeMe();
        PmergeMe(char **argv);
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();
        void sortAndMeasure();
        void printResult();
        void printnumbers();
};

#endif