#pragma once
#include <string>

class Product {
public:
    std::string name;
    int quantity;
    double price;

    Product(const std::string& n, int q, double p)
        : name(n), quantity(q), price(p) {}

    std::string to_csv() const;
};
