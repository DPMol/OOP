#pragma once
#include "../Domain/tenant.h"
#include <functional>
#include <vector>
#include <algorithm>
#include <optional>

class repository {
private:
    std::vector<tenant> list;

public:
    void add(const tenant& t);

    [[nodiscard]] std::optional<std::vector<tenant>::const_iterator> find(int apartment) const;

    [[nodiscard]] const std::vector<tenant>& get_list() const;

    void del(std::vector<tenant>::const_iterator poz);
};
