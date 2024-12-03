
// falta el encabezado de 42

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
#include <chrono>
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