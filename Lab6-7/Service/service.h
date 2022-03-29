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

    void del(int apartment, std::string& owner, std::string& type, int area);

    void modify(int apartment, std::string& owner, std::string& type, int area, int new_apartment, std::string& new_owner, std::string& new_type, int new_area);

    std::string show();

    std::string find(int apartment);
};