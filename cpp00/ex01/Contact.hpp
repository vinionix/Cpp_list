#pragma once
#include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string second_name;
        std::string surname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        std::string& get_first_name();
        std::string& get_second_name();
        std::string& get_surname();
        std::string& get_phone_number();
        std::string& get_darkest_secret();
};
