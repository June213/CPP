// falta el encabezado de 42

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() : _timeVec(0), _timeDeq(0) {}

PmergeMe::PmergeMe(char **argv) : _timeVec(0), _timeDeq(0)
{
   for (int i = 1; argv[i]; i++)
   {
        std::string str(argv[i]);
        if (str.find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("Invalid argument: contains characters other than digits");
        int num = std::atoi(str.c_str());
        _vec.push_back(num);
        _deq.push_back(num);
   }
}

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec), _deq(src._deq), _timeVec(src._timeVec), _timeDeq(src._timeDeq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        _vec = src._vec;
        _deq = src._deq;
        _timeVec = src._timeVec;
        _timeDeq = src._timeDeq;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeInsterSortVector(int begin, int end)
{
    if (end - begin > 5)
    {
        int middle = (begin + end) / 2;
        mergeInsterSortVector(begin, middle);
        mergeInsterSortVector(middle + 1, end);
        mergeVector(begin, middle, end);
    }
    else
        insertSortVector(begin, end);
    
}

void PmergeMe::mergeInsterSortDeque(int begin, int end)
{
    if (end - begin > 5)
    {
        int middle = (begin + end) / 2;
        mergeInsterSortDeque(begin, middle);
        mergeInsterSortDeque(middle + 1, end);
        mergeDeque(begin, middle, end);
    }
    else
        insertSortDeque(begin, end);
}

void PmergeMe::mergeVector(int begin, int middle, int end)
{
    std::vector<int> temp(end - begin + 1);

    int i = begin;
    int j = middle + 1;
    int k = 0;
    while (i <= middle && j <= end)
    {
        if (_vec[i] < _vec[j])
            temp[k++] = _vec[i++];
        else
            temp[k++] = _vec[j++];
    }
    while (i <= middle)
        temp[k++] = _vec[i++];
    while (j <= end)
        temp[k++] = _vec[j++];
    for (size_t i = 0; i < temp.size(); ++i)
        _vec[begin + i] = temp[i];
}

void PmergeMe::mergeDeque(int begin, int middle, int end)
{
    std::deque<int> temp(end - begin + 1);

    int i = begin;
    int j = middle + 1;
    int k = 0;
    while (i <= middle && j <= end)
    {
        if (_deq[i] < _deq[j])
            temp[k++] = _deq[i++];
        else
            temp[k++] = _deq[j++];
    }
    while (i <= middle)
        temp[k++] = _deq[i++];
    while (j <= end)
        temp[k++] = _deq[j++];
    for ( size_t i = 0; i < temp.size(); ++i)
        _deq[begin + i] = temp[i];
}

void PmergeMe::insertSortVector(int begin, int end)
{
    for (int i = begin + 1; i <= end; i++)
    {
        int key = _vec[i];
        int j = i - 1;
        while (j >= begin && _vec[j] > key)
        {
            _vec[j + 1] = _vec[j];
            j--;
        }
        _vec[j + 1] = key;
    }
}

void PmergeMe::insertSortDeque(int begin, int end)
{
    for (int i = begin + 1; i <= end; i++)
    {
        int key = _deq[i];
        int j = i - 1;
        while (j >= begin && _deq[j] > key)
        {
            _deq[j + 1] = _deq[j];
            j--;
        }
        _deq[j + 1] = key;
    }
}

void PmergeMe::sortAndMeasure()
{
    std::clock_t start = std::clock();
    mergeInsterSortVector(0, _vec.size() - 1);
    _timeVec = 1000000 * ((std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    start = std::clock();
    mergeInsterSortDeque(0, _deq.size() - 1);
    _timeDeq = 1000000 * ((std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
}

void PmergeMe::printResult()
{
    std::cout <<  "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout <<  _vec[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: " << _timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque: " << _timeDeq << " us" << std::endl;
}

void PmergeMe::printnumbers()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
}
