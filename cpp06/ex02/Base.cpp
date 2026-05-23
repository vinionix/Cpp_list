#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

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
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Pointer is A class: A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Pointer is B class: B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Pointer is C class: C" << std::endl;
    else
        std::cout << "This pointer does not a point to A, B or C." << std::endl;
}

void identify(Base& p){
    try{
        A a = dynamic_cast<A&>(p);
        std::cout << "Pointer is A class: A" << std::endl;
    }
    catch(const std::exception e){
    }
    try{
        B b = dynamic_cast<B&>(p);
        std::cout << "Pointer is B class: B" << std::endl;
    }
    catch(const std::exception e){
    }
    try{
        C c = dynamic_cast<C&>(p);
        std::cout << "Pointer is C class: C" << std::endl;
    }
    catch(const std::exception e){
        //std::cout << "This pointer does not a var to A, B or C." << std::endl;
    }
}
