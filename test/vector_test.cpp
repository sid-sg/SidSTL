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
}