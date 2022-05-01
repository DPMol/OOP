#pragma once
#include "../Domain/tenant.h"
#include <functional>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <optional>

class AbstractRepo {
protected:
    std::map<int, tenant> list;
    float Prob;

    [[nodiscard]] virtual int rand() const = 0 ;

public:
    virtual void add(const tenant& t) = 0;

    [[nodiscard]] virtual std::optional<std::map<int, tenant>::const_iterator> find(int apartment) const = 0;

    [[nodiscard]] virtual const std::map<int, tenant>& get_list() const = 0;

    virtual void del(std::map<int, tenant>::const_iterator poz) = 0;
};

