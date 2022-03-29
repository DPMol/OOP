#include "repository.h"

void repository::add(const tenant& t){
    list.push_back(t);
}

long long repository::find(const tenant& t) {
    auto temp = list.search(t);
    return temp;
}

void repository::del(const long long poz) {
    list.pop(poz);
}

const array<tenant>& repository::get_list(){
    return (const array<tenant>&) list;
}

tenant* repository::get_position(long long poz){
    return &list[poz];
}
