//
// Created by 12den on 21-Apr-22.
//

#include "newrepository.h"
#include <iostream>

void newrepository::add(const tenant &t) {
    if(rand() <= Prob*100)
        throw std::exception();
    list.insert({list.size(),t});
}

std::optional<std::map<int, tenant>::const_iterator> newrepository::find(int apartment) const {
    if(rand() <= Prob*100)
        throw std::exception();
    auto out = std::find_if(list.begin(), list.end(), [&apartment](const std::pair<int, tenant>& a){return a.second.get_apartment() == apartment;});

    if(out == list.end()){
        return {};
    }
    return out;
}

const std::map<int, tenant> &newrepository::get_list() const {
    if(rand() <= Prob*100)
        throw std::exception();
    return list;
}

void newrepository::del(std::map<int, tenant>::const_iterator poz) {
    if(rand() <= Prob*100)
        throw std::exception();
    list.erase(poz);
}

newrepository::newrepository(float prob){

    Prob = prob;
}

int newrepository::rand() const {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,100);
    auto a = dist6(rng);
    std::cout<<a;
    return a;
}
