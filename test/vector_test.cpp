#include "../headers/containers/vector.hpp"

#include <algorithm>
#include <iostream>
#include <ranges>

int main() {
    sid::vector<int> vec = {6, 7, 4, 3, 4, 6, 2, 8};
    vec.insert(vec.begin() + 3, 100);
    std::cout << vec << std::endl;
}