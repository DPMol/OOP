#pragma once

#include "my_exception.h"

#include <utility>

my_exception::my_exception(std::string  msg):error(std::move(msg)) {}

std::string my_exception::get_error() {
    return error;
}
