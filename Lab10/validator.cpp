#include "validator.h"

validator::validator()
{

}

int validator::validate_apartment(const std::string str)
{
    int ap;
    try{
        ap = std::stoi(str);
    }
    catch(...){
        throw my_exception("Apartment is not a number!");
    }
    if(ap<1){
        throw my_exception("Apartment should be bigger than 0!");
    }
    return ap;
}

std::string validator::validate_owner(const std::string str)
{
    if(str.empty())
        throw my_exception("Owner must not be empty");

    return str;
}

std::string validator::validate_type(const std::string str)
{
    if(str.empty())
        throw my_exception("Type must not be empty");

    return str;
}

int validator::validate_area(const std::string str)
{
    int ap;
    try{
        ap = std::stoi(str);
    }
    catch(...){
        throw my_exception("Area is not a number!");
    }
    if(ap<1){
        throw my_exception("Area should be bigger than 0!");
    }
    return ap;
}
