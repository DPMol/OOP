//
// Created by 12den on 14-Apr-22.
//

#include "my_exception.h"

#include <utility>

my_exception::my_exception(std::string  msg):error(std::move(msg)) {}

std::string my_exception::get_error() {
    return error;
}
