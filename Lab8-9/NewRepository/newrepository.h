#pragma once
#include "../AbstractRepo/AbstractRepo.h"
#include <random>

class newrepository: public AbstractRepo {
private:
    [[nodiscard]] int rand() const override;

public:
    explicit newrepository(float prob = 0.5);

    void add(const tenant& t) override;

    [[nodiscard]] std::optional<std::map<int, tenant>::const_iterator> find(int apartment) const override;

    [[nodiscard]] const std::map<int, tenant>& get_list() const override;

    void del(std::map<int, tenant>::const_iterator poz) override;
};
