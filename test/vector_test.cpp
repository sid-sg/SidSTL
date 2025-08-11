#include "../headers/containers/vector.hpp"
#include <iostream>

int main(){
    sid::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    
    std::cout<< "Size: " << vec.size() << std::endl;
    std::cout<< "Capacity: " << vec.capacity() << std::endl;
    std::cout<< "Is empty: " << (vec.empty() ? "Yes" : "No") << std::endl;
    std::cout<< "Elements: " << vec << std::endl;

    vec.pop_back();
    std::cout<< "Size after pop_back: " << vec.size() << std::endl;
    std::cout<< "Elements: " << vec << std::endl;

    vec.pop_back();
    std::cout<< "Elements: " << vec << std::endl;
    std::cout<< "Is empty: " << (vec.empty() ? "Yes" : "No") << std::endl;
}