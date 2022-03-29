#pragma once
#include <string>
#include "../Service/service.h"
#include <iostream>
#include "D:/Programming n shit/Utilities/dynamic_array.h"

class interface{
private:
    service srv;

public:
    explicit interface(service& srv);

    ~interface() = default;

    void run();

private:
    static void menu();

    void add(array<std::string>& arg);

    void del(array<std::string>& arg);

    void show(array<std::string>& arg);

    void modify(array<std::string>& arg);

    void find(array<std::string>& arg);
};