#include "RPN.hpp"
#include <climits>
#include <sstream>
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(const RPN &other) : _values(other._values)
{
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _values = other._values;
    return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string &token)
{
    return token.size() == 1 && (token[0] == '+' || token[0] == '-'
        || token[0] == '*' || token[0] == '/');
}

void RPN::applyOperator(char operation)
{
    if (_values.size() < 2)
        throw std::runtime_error("invalid expression");
    const int right = _values.top();
    _values.pop();
    const int left = _values.top();
    _values.pop();
    if (operation == '/' && right == 0)
        throw std::runtime_error("division by zero");
    long result;
    if (operation == '+')
        result = static_cast<long>(left) + right;
    else if (operation == '-')
        result = static_cast<long>(left) - right;
    else if (operation == '*')
        result = static_cast<long>(left) * right;
    else
        result = left / right;
    if (result < INT_MIN || result > INT_MAX)
        throw std::runtime_error("integer overflow");
    _values.push(static_cast<int>(result));
}

int RPN::evaluate(const std::string &expression)
{
    while (!_values.empty())
        _values.pop();
    std::istringstream input(expression);
    std::string token;
    while (input >> token)
    {
        if (token.size() == 1 && token[0] >= '0' && token[0] <= '9')
            _values.push(token[0] - '0');
        else if (isOperator(token))
            applyOperator(token[0]);
        else
            throw std::runtime_error("invalid token");
    }
    if (_values.size() != 1)
        throw std::runtime_error("invalid expression");
    return _values.top();
}
