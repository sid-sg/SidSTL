#include "../headers/containers/vector.hpp"

#include <iostream>

int main() {
    sid::vector<int> vec;
    sid::vector<int> vec2(10, -1);
    vec.push_back(10);
    vec.push_back(20);

    std::cout << "Vector 1: " << vec << std::endl;
    std::cout << "Vector 2: " << vec2 << std::endl;

    vec2 = vec;

    std::cout << "Vector 1: " << vec << std::endl;
    std::cout << "Vector 2: " << vec2 << std::endl;

    sid::vector<int> vec3 = {1, 2, 3, 4, 5};
    vec3.push_back(6);
    std::cout << "Vector 3: " << vec3 << std::endl;
    std::cout << "Size of Vector 3: " << vec3.size() << std::endl;
    std::cout << "Capacity of Vector 3: " << vec3.capacity() << std::endl;
    vec3.reserve(20);
    std::cout << "Size of Vector 3: " << vec3.size() << std::endl;
    std::cout << "Capacity of Vector 3: " << vec3.capacity() << std::endl;

    vec3.clear();
    std::cout << "Size of Vector 3: " << vec3.size() << std::endl;
    std::cout << "Capacity of Vector 3: " << vec3.capacity() << std::endl;

    vec3.resize(10, 3);
    std::cout << "Vector 3: " << vec3 << std::endl;
    std::cout << "Size of Vector 3 after resize: " << vec3.size()<< std::endl;
    std::cout << "Capacity of Vector 3 after resize: " << vec3.capacity() << std::endl;

    vec3.resize(5);
    std::cout << "Vector 3: " << vec3 << std::endl;
    std::cout << "Size of Vector 3 after resize: " << vec3.size()<< std::endl;
    std::cout << "Capacity of Vector 3 after resize: " << vec3.capacity() << std::endl;

    vec3.swap(vec2);
    std::cout << "Vector 3 after swap: " << vec3 << std::endl;
    std::cout << "Vector 2 after swap: " << vec2 << std::endl;

    std::cout << "vector 2: " << std::endl;
    for(auto&e:vec2){
        std::cout << e << " ";
    }
    std::cout << std::endl;

    auto it = vec2.begin();
    std::cout << "First element using iterator: " << *it << std::endl;

}