#pragma once
#include <string>
#include "../Service/service.h"
#include <iostream>
//#include "D:/Programming n shit/Utilities/dynamic_array.h"
#include "../dynamic_array.h"

class interface{
private:
    service srv;

public:
    explicit interface(service& srv);

    ~interface() = default;

    void run();

private:
    static void menu();

    void add();

    void del();

    void show();

    void modify();

    void find();

    void filter();

    void sort();
};

