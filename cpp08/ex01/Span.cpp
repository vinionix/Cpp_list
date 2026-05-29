#include "Span.hpp"

Span::Span(unsigned int n) : N(n), currentSize(0){
    if (this->N == 0){
        throw std::runtime_error("Span cannot have a size of 0");
    }
    this->array = new int[this->N];
}

Span::Span(const Span& copy){
    if (this != &copy){
        this->N = copy.N;
        this->currentSize = copy.currentSize;
        this->array = new int[this->N];
        for (unsigned int i = 0; i < this->N; i++){
            this->array[i] = copy.array[i];
        }
    }
}

Span& Span::operator=(const Span& copy){
    if (this != &copy){
        this->N = copy.N;
        this->currentSize = copy.currentSize;
        delete[] this->array;
        this->array = new int[this->N];
        for (unsigned int i = 0; i < this->N; i++){
            this->array[i] = copy.array[i];
        }
    }
    return *this;
}

void Span::addNumber(int number){
    if (this->currentSize >= this->N){
        throw std::runtime_error("Span does not have enough space to add more numbers");
    }
    this->array[this->currentSize] = number;
    this->currentSize++;
}

void Span::organizeArray(Span* span){
    for (unsigned int i = 0; i < span -> currentSize - 1; i++){
        if (span->array[i] > span->array[i + 1]){
            int temp = span->array[i];
            span->array[i] = span->array[i + 1];
            span->array[i + 1] = temp;
            i = -1;
        }
    }
}

int Span::shortestSpan(){
    if (this->currentSize < 2){
        throw std::runtime_error("Span does not have enough numbers to find a span");
    }
    int minSpan = 2147483647;
    this->organizeArray(this);
    for (unsigned int i = 0; i < this->currentSize - 1; i++){
        for (unsigned int j = i + 1; j < this->currentSize; j++){
            if ((this->array[j] - this->array[i]) < minSpan){
                minSpan = this->array[j] - this->array[i];
            }
        }
    }
    return minSpan;
}

int Span::longestSpan(){
    if (this->currentSize < 2){
        throw std::runtime_error("Span does not have enough numbers to find a span");
    }
    int maxSpan = -2147483648;
    this->organizeArray(this);
    for (unsigned int i = 0; i < this->currentSize - 1; i++){
        for (unsigned int j = i + 1; j < this->currentSize; j++){
            if ((this->array[j] - this->array[i]) > maxSpan){
                maxSpan = this->array[j] - this->array[i];
            }
        }
    }
    return maxSpan;
}

void Span::addMultipleNumbers(int* begin, int* end){
    while (begin != end){
        if (this->currentSize >= this->N){
            throw std::runtime_error("Span does not have enough space to add more numbers");
        }
        this->addNumber(*begin);
        begin++;
    }
}

unsigned int Span::getN( void ){
    return this->N;
}

unsigned int Span::getCurrentSize( void ){
    return this->currentSize;
}

void Span::printSpan(Span* span){
    for (unsigned int i = 0; i < span->getCurrentSize(); i++){
        Span temp(*span);

        std::cout << temp.array[i] << " ";
    }
    std::cout << std::endl;
}

Span::~Span(){
    delete[] this->array;
}