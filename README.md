# Inventory Management CLI (C++)

🗓️ **December 2023**

A command-line inventory system written in C++, featuring:
- Product registration and stock updates
- Order logging
- File-based CSV persistence
- Singleton pattern for global config
- Strategy pattern for filtering and sorting
- Modular OOP structure for maintainability

## Build & Run

```bash
g++ -std=c++17 -o inventory main.cpp product.cpp inventory.cpp config.cpp sort_strategy.cpp
./inventory
```

## Files
- `products.csv`: Product database
- `orders.csv`: Order log
