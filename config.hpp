#pragma once
#include <string>

class Config {
public:
    std::string productsFile = "products.csv";
    std::string ordersFile = "orders.csv";

    static Config& getInstance() {
        static Config instance;
        return instance;
    }

private:
    Config() {}
    Config(const Config&) = delete;
    void operator=(const Config&) = delete;
};
