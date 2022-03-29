#include "tenant.h"

#include <utility>

tenant::tenant(int apartment, std::string owner, std::string type, int area)
:apartment(apartment), owner(std::move(owner)), type(std::move(type)), area(area)
{

}

int tenant::get_apartment() const{
    return apartment;
}

std::string tenant::get_owner(){
    return owner;
}

std::string tenant::get_type(){
    return type;
}

int tenant::get_area() const{
    return area;
}

void tenant::set_apartment(const int new_aparment){
    apartment = new_aparment;
}

void tenant::set_owner(const std::string& new_owner){
    owner = new_owner;
}

void tenant::set_type(const std::string& new_type){
    type = new_type;
}

void tenant::set_area(const int new_area){
    area =new_area;
}

bool tenant::operator != (const tenant& other) const{
    return !(this->area == other.area && this->apartment == other.apartment && this->type == other.type && this->owner == other.owner);
}

bool tenant::operator == (const tenant& other) const{
    return this->area == other.area && this->apartment == other.apartment && this->type == other.type && this->owner == other.owner;
}

std::string tenant::str(){
    return "Apartment: " + std::to_string(apartment) + ", Owner: " + owner + ", Type: " + type + ", Area: "+ std::to_string(area);
}