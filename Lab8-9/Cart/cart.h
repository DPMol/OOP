#pragma once
//#include "D:/Programming n shit/Utilities/dynamic_array.h"
#include "../dynamic_array.h"
#include "../Domain/tenant.h"
#include <functional>
#include <vector>
#include <algorithm>
#include <optional>

class cart {
private:
    std::vector<tenant> list;

public:
    void add(const tenant& t);

    [[nodiscard]] const std::vector<tenant>& get_list() const;

    void empty();
};
