#pragma once
#include "../Repository/repository.h"
#include "../Domain/tenant.h"
#include "string"

class service {
private:
    repository repo;

public:
    explicit service(repository& repo);

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
};