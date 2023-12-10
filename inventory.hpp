#pragma once
#include <vector>
#include "product.hpp"

class Inventory {
public:
    void run();
private:
    std::vector<Product> products;
    void loadProducts();
    void saveProducts();
    void registerProduct();
    void updateStock();
    void listProducts();
};
