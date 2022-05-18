#pragma once
#include <string>
#include "my_exception.h"

class validator
{
public:
    validator();

    static int validate_apartment(const std::string str);
    static std::string validate_owner(const std::string str);
    static std::string validate_type(const std::string str);
    static int validate_area(const std::string str);


};
