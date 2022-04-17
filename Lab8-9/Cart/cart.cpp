//
// Created by 12den on 10-Apr-22.
//

#include "cart.h"

void cart::add(const tenant &t) {
    list.push_back(t);
}

const std::vector<tenant> &cart::get_list() const {
    return list;
}

void cart::empty() {
    list.clear();
}
