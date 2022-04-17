#pragma once
#include <string>
#include "../Service/service.h"
#include <iostream>
//#include "D:/Programming n shit/Utilities/dynamic_array.h"
#include "../dynamic_array.h"
#include "../Exception/my_exception.h"
#include <sstream>
#include <optional>

class interface{
private:
    service srv;

public:
    explicit interface(service& srv);

    ~interface() = default;

    void run();

private:
    void bash();
    
    static void menu();

    void add(std::istringstream* in = nullptr);

    void del(std::istringstream* in = nullptr);

    void show();

    void modify(std::istringstream* in = nullptr);

    void find(std::istringstream* in = nullptr);

    void filter(std::istringstream* in = nullptr);

    void sort(std::istringstream* in = nullptr);

    void cart(std::istringstream* in = nullptr);

    void add_cart(std::istringstream* in = nullptr);

    void empty_cart();

    void random_cart(std::istringstream* in = nullptr);

    void export_cart(std::istringstream* in = nullptr);

    static void menu_cart();
};

