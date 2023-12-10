#include "product.hpp"
#include <sstream>

std::string Product::to_csv() const {
    std::ostringstream oss;
    oss << name << "," << quantity << "," << price;
    return oss.str();
}
