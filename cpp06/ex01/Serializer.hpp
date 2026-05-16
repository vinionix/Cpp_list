#pragma once

# include <stdint.h>

class Serializer{
    private:
        Serializer();
        ~Serializer();
    public:
        static uintptr_t serialize(int* ptr);
        static Data* deserialize(uintptr_t raw);
};