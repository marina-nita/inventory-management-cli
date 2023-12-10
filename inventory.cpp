#include "inventory.hpp"
#include "config.hpp"
#include "sort_strategy.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Inventory::loadProducts() {
    std::ifstream file(Config::getInstance().productsFile);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string name;
        int quantity;
        double price;
        if (std::getline(ss, name, ',') && ss >> quantity && ss.ignore() && ss >> price) {
            products.emplace_back(name, quantity, price);
        }
    }
}

void Inventory::saveProducts() {
    std::ofstream file(Config::getInstance().productsFile);
    for (const auto& p : products) {
        file << p.to_csv() << "\n";
    }
}

void Inventory::registerProduct() {
    std::string name;
    int quantity;
    double price;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    std::cout << "Enter price: ";
    std::cin >> price;
    products.emplace_back(name, quantity, price);
    saveProducts();
}

void Inventory::updateStock() {
    std::string name;
    int delta;
    std::cout << "Enter product name: ";
    std::cin >> name;
    std::cout << "Enter quantity change: ";
    std::cin >> delta;

    for (auto& p : products) {
        if (p.name == name) {
            p.quantity += delta;
            saveProducts();
            std::cout << "Updated successfully.\n";
            return;
        }
    }
    std::cout << "Product not found.\n";
}

void Inventory::listProducts() {
    SortStrategy* sorter = new AlphabeticalSort();
    sorter->sort(products);
    for (const auto& p : products) {
        std::cout << p.name << " - Qty: " << p.quantity << " - Price: $" << p.price << "\n";
    }
    delete sorter;
}

void Inventory::run() {
    loadProducts();
    int choice;
    do {
        std::cout << "\nInventory Menu:\n";
        std::cout << "1. Register Product\n";
        std::cout << "2. Update Stock\n";
        std::cout << "3. List Products\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: registerProduct(); break;
            case 2: updateStock(); break;
            case 3: listProducts(); break;
        }
    } while (choice != 0);
    saveProducts();
}
