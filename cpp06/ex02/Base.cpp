#include "Base.hpp"

Base::~Base(){};

Base* generate(void){
    static int seedUsed = 0;
    if (seedUsed == 0)
    {
        std::srand(std::time(0));
        seedUsed = 1;
    }
    int index = std::rand() % 3;

    if (index == 0)
        return (new A());
    else if (index == 1)
        return (new B());
    return (new C());
}

void identify(Base* p){
    
}

void identify(Base& p){

}
