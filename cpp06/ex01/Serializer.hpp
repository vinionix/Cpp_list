#pragma once

class Serializer{
    private:
        Serializer();
        ~Serializer();
    public:
        uintptr_t serialize(int* ptr);
};