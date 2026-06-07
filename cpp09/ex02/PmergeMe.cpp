#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <sys/time.h>

namespace
{
    double elapsedMicroseconds(const timeval &start, const timeval &end)
    {
        return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    }
}

PmergeMe::PmergeMe() : _vectorTime(0.0), _dequeTime(0.0)
{
}

PmergeMe::PmergeMe(int argc, char **argv) : _vectorTime(0.0), _dequeTime(0.0)
{
    if (argc < 2)
        throw std::runtime_error("missing sequence");
    for (int i = 1; i < argc; ++i)
    {
        const int value = parsePositiveInteger(argv[i]);
        _vectorData.push_back(value);
        _dequeData.push_back(value);
    }
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vectorData(other._vectorData),
    _dequeData(other._dequeData), _vectorTime(other._vectorTime), _dequeTime(other._dequeTime)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

int PmergeMe::parsePositiveInteger(const char *argument)
{
    if (argument == NULL || argument[0] == '\0')
        throw std::runtime_error("invalid integer");
    for (int i = 0; argument[i] != '\0'; ++i)
    {
        if (argument[i] < '0' || argument[i] > '9')
            throw std::runtime_error("invalid integer");
    }
    char *end = NULL;
    const long value = std::strtol(argument, &end, 10);
    if (*end != '\0' || value <= 0 || value > INT_MAX)
        throw std::runtime_error("invalid integer");
    return static_cast<int>(value);
}

void PmergeMe::printVector(const std::vector<int> &values)
{
    for (std::vector<int>::const_iterator it = values.begin(); it != values.end(); ++it)
        std::cout << (it == values.begin() ? "" : " ") << *it;
    std::cout << std::endl;
}

void PmergeMe::printDeque(const std::deque<int> &values)
{
    for (std::deque<int>::const_iterator it = values.begin(); it != values.end(); ++it)
        std::cout << (it == values.begin() ? "" : " ") << *it;
    std::cout << std::endl;
}

void PmergeMe::insertVector(std::vector<int> &values, int value)
{
    std::vector<int>::iterator first = values.begin();
    std::vector<int>::iterator last = values.end();
    while (first < last)
    {
        std::vector<int>::iterator middle = first + (last - first) / 2;
        if (*middle < value)
            first = middle + 1;
        else
            last = middle;
    }
    values.insert(first, value);
}

void PmergeMe::insertDeque(std::deque<int> &values, int value)
{
    std::deque<int>::iterator first = values.begin();
    std::deque<int>::iterator last = values.end();
    while (first < last)
    {
        std::deque<int>::iterator middle = first + (last - first) / 2;
        if (*middle < value)
            first = middle + 1;
        else
            last = middle;
    }
    values.insert(first, value);
}

void PmergeMe::sortVector(std::vector<int> &values)
{
    if (values.size() < 2)
        return;
    std::vector<int> mainChain;
    std::vector<int> pending;
    for (std::vector<int>::size_type i = 0; i + 1 < values.size(); i += 2)
    {
        if (values[i] < values[i + 1])
        {
            pending.push_back(values[i]);
            mainChain.push_back(values[i + 1]);
        }
        else
        {
            pending.push_back(values[i + 1]);
            mainChain.push_back(values[i]);
        }
    }
    if (values.size() % 2 != 0)
        pending.push_back(values.back());
    sortVector(mainChain);
    if (!pending.empty())
        insertVector(mainChain, pending[0]);
    std::vector<int>::size_type previousBoundary = 1;
    std::vector<int>::size_type previousJacobsthal = 1;
    std::vector<int>::size_type jacobsthal = 3;
    while (previousBoundary < pending.size())
    {
        const std::vector<int>::size_type boundary = jacobsthal < pending.size() ? jacobsthal : pending.size();
        for (std::vector<int>::size_type i = boundary; i > previousBoundary; --i)
            insertVector(mainChain, pending[i - 1]);
        previousBoundary = boundary;
        const std::vector<int>::size_type next = jacobsthal + 2 * previousJacobsthal;
        previousJacobsthal = jacobsthal;
        jacobsthal = next;
    }
    values.swap(mainChain);
}

void PmergeMe::sortDeque(std::deque<int> &values)
{
    if (values.size() < 2)
        return;
    std::deque<int> mainChain;
    std::deque<int> pending;
    for (std::deque<int>::size_type i = 0; i + 1 < values.size(); i += 2)
    {
        if (values[i] < values[i + 1])
        {
            pending.push_back(values[i]);
            mainChain.push_back(values[i + 1]);
        }
        else
        {
            pending.push_back(values[i + 1]);
            mainChain.push_back(values[i]);
        }
    }
    if (values.size() % 2 != 0)
        pending.push_back(values.back());
    sortDeque(mainChain);
    if (!pending.empty())
        insertDeque(mainChain, pending[0]);
    std::deque<int>::size_type previousBoundary = 1;
    std::deque<int>::size_type previousJacobsthal = 1;
    std::deque<int>::size_type jacobsthal = 3;
    while (previousBoundary < pending.size())
    {
        const std::deque<int>::size_type boundary = jacobsthal < pending.size() ? jacobsthal : pending.size();
        for (std::deque<int>::size_type i = boundary; i > previousBoundary; --i)
            insertDeque(mainChain, pending[i - 1]);
        previousBoundary = boundary;
        const std::deque<int>::size_type next = jacobsthal + 2 * previousJacobsthal;
        previousJacobsthal = jacobsthal;
        jacobsthal = next;
    }
    values.swap(mainChain);
}

void PmergeMe::process()
{
    std::cout << "Before: ";
    printVector(_vectorData);

    timeval start;
    timeval end;
    gettimeofday(&start, NULL);
    std::vector<int> sortedVector(_vectorData);
    sortVector(sortedVector);
    gettimeofday(&end, NULL);
    _vectorTime = elapsedMicroseconds(start, end);

    gettimeofday(&start, NULL);
    std::deque<int> sortedDeque(_dequeData);
    sortDeque(sortedDeque);
    gettimeofday(&end, NULL);
    _dequeTime = elapsedMicroseconds(start, end);

    if (sortedVector.size() != sortedDeque.size())
        throw std::runtime_error("container results differ");
    for (std::vector<int>::size_type i = 0; i < sortedVector.size(); ++i)
    {
        if (sortedVector[i] != sortedDeque[i])
            throw std::runtime_error("container results differ");
    }
    std::cout << "After: ";
    printVector(sortedVector);
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Time to process a range of " << sortedVector.size()
        << " elements with std::vector : " << _vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << sortedDeque.size()
        << " elements with std::deque : " << _dequeTime << " us" << std::endl;
}
