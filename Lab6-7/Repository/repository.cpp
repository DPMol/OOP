#include "repository.h"

#include <utility>

void repository::add(const tenant& t){
    list.push_back(t);
}

long long repository::find(const int apartment) const{
    auto iterator = list.begin();
    while(iterator < list.end() && iterator->get_apartment() != apartment) {
        iterator++;
    }

    if(iterator == list.end()){
        return -1;
    }

    return iterator - list.begin();
}

const array<tenant>& repository::get_list() const{
    return list;
}

void repository::del(const long long poz) {
    list.pop(poz);
}

tenant& repository::get_position(long long poz){
    return list[poz];
}

