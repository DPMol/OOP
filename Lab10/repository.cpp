#include "repository.h"


void Repository::add(const tenant& t){
    list.push_back(t);
}

std::optional<std::vector<tenant>::const_iterator> Repository::find(const int apartment) const{
    auto out = std::find_if(list.begin(), list.end(), [&apartment](const tenant& a){return a.get_apartment() == apartment;});

    if(out == list.end()){
        return {};
    }
    return out;
}

const std::vector<tenant>& Repository::get_list() const{
    return list;
}

void Repository::del(const std::vector<tenant>::const_iterator poz) {
    list.erase(poz);
}


