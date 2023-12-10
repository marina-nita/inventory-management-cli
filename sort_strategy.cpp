#include "sort_strategy.hpp"
#include <algorithm>

void AlphabeticalSort::sort(std::vector<Product>& products) {
    std::sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.name < b.name;
    });
}
