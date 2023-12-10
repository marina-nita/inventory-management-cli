#pragma once
#include <vector>
#include "product.hpp"

class SortStrategy {
public:
    virtual void sort(std::vector<Product>& products) = 0;
    virtual ~SortStrategy() = default;
};

class AlphabeticalSort : public SortStrategy {
public:
    void sort(std::vector<Product>& products) override;
};
