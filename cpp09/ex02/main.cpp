#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        PmergeMe sorter(argc, argv);
        sorter.process();
    }
    catch (const std::exception &)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
