#include "service.h"
#include <iostream>
service::service(repository& repo):repo(repo) {}

void service::add(int apartment, std::string& owner, std::string& type, int area){
    if(repo.find(apartment) != -1)
        throw std::invalid_argument("ADD ERROR");

    tenant t(apartment, owner, type, area);
    repo.add(t);
}

void service::del(int apartment){

    auto poz = repo.find(apartment);

    if(poz == -1){
        throw std::invalid_argument("DELETE ERROR");
    }

    repo.del(poz);
}

std::string service::show() {
    std::string out;
    auto& list = repo.get_list();

//    for(auto i = 0; i<list.size(); i++)
//        out += (list[i].str() + "\n");

    for(auto& t : list){
        out += (t.str() + "\n");
    }

    return out;
}

void service::modify(int apartment, int new_apartment,
                     std::string &new_owner, std::string &new_type, int new_area) {

    auto poz = repo.find(apartment);

    if(poz == -1){
        throw std::invalid_argument("MODIFY ERROR");
    }

    auto& t2 = repo.get_position(poz);

    t2.set_apartment(new_apartment);
    t2.set_area(new_area);
    t2.set_owner(new_owner);
    t2.set_type(new_type);
}

std::string service::find(int apartment){
    std::string out;
    auto& list = repo.get_list();

    for(auto& t : list){
        if(t.get_apartment() == apartment){
            out += (t.str() + "\n");
        }
    }

    return out;
}

std::string service::filter_type(std::string& type){
    auto list = repo.get_list();
    list.filter([&type](const tenant& a){return a.get_type() == type;});

    if(list.empty()){
        return "";
    }

    std::string out;
    for(auto& t : list){
            out += (t.str() + "\n");
    }
    return out;
}

std::string service::filter_area(int area){

    auto list = repo.get_list();
    list.filter([&area](const tenant& a){return a.get_area() == area;});

    if(list.empty()){
        return "";
    }

    std::string out;
    for(auto& t : list){
        out += (t.str() + "\n");
    }
    return out;
}

std::string service::sort_owner(bool reverse) {
    auto list = repo.get_list();
    list.sort(reverse, [](const tenant& a, const tenant&b){return a.get_owner() < b.get_owner();});

    std::string out;
    for(auto& t : list){
        out += (t.str() + "\n");
    }
    return out;
}

std::string service::sort_area(bool reverse) {

    auto list = repo.get_list();
    list.sort(reverse, [](const tenant& a, const tenant&b){return a.get_area() < b.get_area();});

    std::string out;
    for(auto& t : list){
        out += (t.str() + "\n");
    }
    return out;
}

std::string service::sort_apartment_area(bool reverse) {

    auto list = repo.get_list();
    list.sort(reverse, [](const tenant& a, const tenant&b){if(a.get_apartment() == b.get_apartment()){return a.get_area() < b.get_area();}else {return a.get_apartment() < b.get_apartment();}});

    std::string out;
    for(auto& t : list){
        out += (t.str() + "\n");
    }
    return out;
}
