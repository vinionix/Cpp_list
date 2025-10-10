#pragma once
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int index;
        int added_contacts;
        Contact contact[8];
    public:
        PhoneBook();
        void search();
        void add();
};
