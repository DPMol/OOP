#pragma once
#include "repository.h"
#include "tenant.h"
#include "string"
#include <fstream>
#include <memory>
#include <vector>
#include "my_exception.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <map>
#include "undoclass.h"



class service {
private:
    std::string extension = ".html";
    Repository& repo;

    std::vector<std::unique_ptr<doUndo>> undo_list;

public:
    explicit service(Repository& repo);

    ~service() = default;

    void add(int apartment, std::string& owner, std::string& type, int area);

    void del(int apartment);

    void modify(int apartment, int new_apartment, std::string& new_owner, std::string& new_type, int new_area);

    std::vector<tenant> get_list();

    std::vector<tenant> get_list(std::string, int);

    void undo();
};
