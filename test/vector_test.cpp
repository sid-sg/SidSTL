#include "../headers/containers/vector.hpp"

#include <iostream>
#include <algorithm>
#include <ranges>

int main() {
    sid::vector<int> vec = {1, 2, 3, 4, 5};
    sid::vector<int> vec2(5, 10);
    swap(vec, vec2);
    std::cout << "vec: " << vec << "\n";
    std::cout << "vec2: " << vec2 << "\n";
}