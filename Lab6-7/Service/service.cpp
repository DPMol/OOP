#include "service.h"
#include <iostream>
service::service(repository& repo):repo(repo) {}

void service::add(int apartment, std::string& owner, std::string& type, int area){
    tenant t(apartment, owner, type, area);

    if(repo.find(t) != -1)
        throw std::exception();

    repo.add(t);
}

void service::del(int apartment, std::string& owner, std::string& type, int area){
    tenant t(apartment, owner, type, area);

    auto temp = repo.find(t);

    if(temp == -1)
        throw std::exception();

    repo.del(temp);
}

std::string service::show() {
    std::string out;
    auto list = repo.get_list();

    for(auto t : list){
        out += (t.str() + "\n");
    }

    return out;
}

void service::modify(int apartment, std::string &owner, std::string &type, int area, int new_apartment,
                     std::string &new_owner, std::string &new_type, int new_area) {
    tenant t(apartment, owner, type, area);

    auto temp = repo.find(t);

    if(temp == -1)
        throw std::exception();

    auto t2 = repo.get_position(temp);

    t2->set_apartment(new_apartment);
    t2->set_area(new_area);
    t2->set_owner(new_owner);
    t2->set_type(new_type);
}

std::string service::find(int apartment){
    std::string out;
    auto list = repo.get_list();

    for(auto t : list){
        if(t.get_apartment() == apartment)
            out += (t.str() + "\n");
    }

    return out;
}