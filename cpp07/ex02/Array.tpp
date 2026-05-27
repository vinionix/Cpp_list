template <typename T>
Array<T>::Array(){
    this->length = 0;
    this->array = new T[this->length];
}

template <typename T>
Array<T>::Array(unsigned int n) {
    this->length = n;
    this->array = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T>& copy) {
    if (this != &copy) {
        this->length = copy.length;
        this->array = new T[this->length];
        for (unsigned int i = 0; i < this->length; i++) {
            this->array[i] = copy.array[i];
        }
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] this->array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& copy) {
    if (this != &copy) {
        delete[] this->array;
        this->length = copy.length;
        this->array = new T[this->length];
        for (unsigned int i = 0; i < this->length; i++) {
            this->array[i] = copy.array[i];
        }
    }
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= this->length) {
        throw std::out_of_range("Index out of range");
    }
    return this->array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return this->length;
}