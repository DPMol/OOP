#pragma once
#include <exception>
#include <string>

class my_exception : public std::exception {
private:
    std::string error;

public:
    explicit my_exception(std::string  msg);

    std::string get_error();
};

