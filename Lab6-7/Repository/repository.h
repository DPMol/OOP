#pragma once
//#include "D:/Programming n shit/Utilities/dynamic_array.h"
#include "../dynamic_array.h"
#include "../Domain/tenant.h"
#include <functional>


class repository {
private:
    array<tenant> list;

public:
    void add(const tenant& t);

    void del(long long poz);

    long long find(const tenant& t);

    const array<tenant>& get_list();

    tenant* get_position(long long poz);

};
