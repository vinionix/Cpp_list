#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>

class PmergeMe
{
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    double _vectorTime;
    double _dequeTime;

    static int parsePositiveInteger(const char *argument);
    static void printVector(const std::vector<int> &values);
    static void printDeque(const std::deque<int> &values);
    static void insertVector(std::vector<int> &values, int value);
    static void insertDeque(std::deque<int> &values, int value);
    static void sortVector(std::vector<int> &values);
    static void sortDeque(std::deque<int> &values);

public:
    PmergeMe();
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void process();
};

#endif
