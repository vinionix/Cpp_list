template <typename T>
void easyFind(T* param1, int find){
    for (typename T::size_type i = 0; i < param1->size(); i++){
        if (param1->at(i) == find){
            std::cout << "Value found at index: " << i << std::endl;
            return;
        }
    }
    throw std::runtime_error("Value not found");
}