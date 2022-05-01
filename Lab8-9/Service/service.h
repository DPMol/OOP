#pragma once
#include "../Repository/repository.h"
#include "../Domain/tenant.h"
#include "../Cart/cart.h"
#include "string"
#include <fstream>
#include <memory>
#include <vector>
#include <../Exception/my_exception.h>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <map>
#include "../Undo/UndoClass.h"
#include "../AbstractRepo/AbstractRepo.h"


class service {
private:
    std::string extension = ".html";
    AbstractRepo& repo;
    cart temp_cart;

    std::vector<std::unique_ptr<doUndo>> undo_list;

public:
    explicit service(AbstractRepo& repo);

    ~service() = default;

    void add(int apartment, std::string& owner, std::string& type, int area);

    void del(int apartment);

    void modify(int apartment, int new_apartment, std::string& new_owner, std::string& new_type, int new_area);

    std::string show();

    std::string find(int apartment);

    std::string filter_type(std::string& type);

    std::string filter_area(int area);

    std::string sort_owner(bool reverse);

    std::string sort_area(bool reverse);

    std::string sort_apartment_area(bool reverse);

    void add_cart(int apartment);

    void empty_cart();

    void random_cart(int num);

    void export_cart(const std::string& file);

    void undo();
};