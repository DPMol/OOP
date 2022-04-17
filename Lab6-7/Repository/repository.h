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

    [[nodiscard]] long long find(int apartment) const;

    [[nodiscard]] const array<tenant>& get_list() const;

    void del(long long poz);

    tenant& get_position(long long poz);

};
