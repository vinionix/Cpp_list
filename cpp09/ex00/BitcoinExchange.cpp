#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _rates = other._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string BitcoinExchange::trim(const std::string &text)
{
    const std::string whitespace = " \t\r\n";
    const std::string::size_type first = text.find_first_not_of(whitespace);
    if (first == std::string::npos)
        return "";
    const std::string::size_type last = text.find_last_not_of(whitespace);
    return text.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (std::string::size_type i = 0; i < date.size(); ++i)
    {
        if (i != 4 && i != 7 && (date[i] < '0' || date[i] > '9'))
            return false;
    }
    const int year = std::atoi(date.substr(0, 4).c_str());
    const int month = std::atoi(date.substr(5, 2).c_str());
    const int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        daysInMonth[1] = 29;
    return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::parseNumber(const std::string &text, double &value)
{
    const std::string number = trim(text);
    if (number.empty())
        return false;
    std::string::size_type i = 0;
    if (number[i] == '+' || number[i] == '-')
        ++i;
    bool hasDigit = false;
    bool hasPoint = false;
    for (; i < number.size(); ++i)
    {
        if (number[i] >= '0' && number[i] <= '9')
            hasDigit = true;
        else if (number[i] == '.' && !hasPoint)
            hasPoint = true;
        else
            return false;
    }
    if (!hasDigit)
        return false;
    std::istringstream stream(number);
    stream >> value;
    return !stream.fail() && stream.eof();
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
        throw std::runtime_error("could not open database file.");
    std::string line;
    if (!std::getline(file, line) || trim(line) != "date,exchange_rate")
        throw std::runtime_error("invalid database header.");
    while (std::getline(file, line))
    {
        const std::string::size_type comma = line.find(',');
        if (comma == std::string::npos || line.find(',', comma + 1) != std::string::npos)
            throw std::runtime_error("invalid database line.");
        const std::string date = trim(line.substr(0, comma));
        double rate;
        if (!isValidDate(date) || !parseNumber(line.substr(comma + 1), rate) || rate < 0.0)
            throw std::runtime_error("invalid database line.");
        _rates[date] = rate;
    }
    if (_rates.empty())
        throw std::runtime_error("empty database.");
}

double BitcoinExchange::findRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
    if (it != _rates.end() && it->first == date)
        return it->second;
    if (it == _rates.begin())
        throw std::runtime_error("date precedes database.");
    --it;
    return it->second;
}

void BitcoinExchange::processInput(const std::string &filename) const
{
    std::ifstream file(filename.c_str());
    if (!file)
        throw std::runtime_error("could not open file.");
    std::string line;
    if (!std::getline(file, line) || trim(line) != "date | value")
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    while (std::getline(file, line))
    {
        const std::string::size_type separator = line.find('|');
        const std::string date = separator == std::string::npos ? "" : trim(line.substr(0, separator));
        double value;
        if (separator == std::string::npos || line.find('|', separator + 1) != std::string::npos
            || !isValidDate(date) || !parseNumber(line.substr(separator + 1), value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0.0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000.0)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        try
        {
            const double rate = findRate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
        catch (const std::exception &)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}
