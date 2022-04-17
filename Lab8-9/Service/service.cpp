#include <fstream>
#include "service.h"

service::service(repository& repo):repo(repo) {}

void service::add(int apartment, std::string& owner, std::string& type, int area){

    auto temp = repo.find(apartment);
    if(temp.has_value()){
        throw std::exception();
    }
    tenant t(apartment, owner, type, area);
    repo.add(t);
}

void service::del(int apartment){
    auto element = repo.find(apartment);
    if(!element.has_value()){
        throw std::exception();
    }

    repo.del(element.value());
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

    auto element = repo.find(apartment);
    if(!element.has_value()){
        throw std::exception();
    }

    tenant t(new_apartment, new_owner, new_type, new_area);

    repo.del(element.value());
    repo.add(t);
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
    const auto& list = repo.get_list();

    std::string out;
    for(auto& t : list){
        if(t.get_type() == type)
            out += (t.str() + "\n");
    }
    return out;
}

std::string service::filter_area(int area){

    const auto& list = repo.get_list();

    std::string out;
    for(auto& t : list){
        if(t.get_area() == area)
            out += (t.str() + "\n");
    }
    return out;
}

std::string service::sort_owner(bool reverse) {
    auto list = repo.get_list();
    if(reverse){
        std::sort(list.rbegin(), list.rend(),
                  [](const tenant &a, const tenant &b) { return a.get_owner() < b.get_owner(); });

    }
    else {
        std::sort(list.begin(), list.end(),
                  [](const tenant &a, const tenant &b) { return a.get_owner() < b.get_owner(); });
    }
    std::string out;
    for(auto& t : list){
        out += (t.str() + "\n");
    }
    return out;
}

std::string service::sort_area(bool reverse) {

    auto list = repo.get_list();
    if(reverse){
        std::sort(list.rbegin(), list.rend(),
                  [](const tenant &a, const tenant &b) { return a.get_area() < b.get_area(); });

    }
    else {
        std::sort(list.begin(), list.end(),
                  [](const tenant &a, const tenant &b) { return a.get_area() < b.get_area(); });
    }
    std::string out;
    for(auto& t : list){
        out += (t.str() + "\n");
    }
    return out;
}

std::string service::sort_apartment_area(bool reverse) {

    auto list = repo.get_list();
    if(reverse){
        std::sort(list.rbegin(), list.rend(),
                  [](const tenant& a, const tenant&b){if(a.get_apartment() == b.get_apartment()){return a.get_area() < b.get_area();}else {return a.get_apartment() < b.get_apartment();}});
    }
    else {
        std::sort(list.begin(), list.end(),
                  [](const tenant &a, const tenant &b) { return a.get_owner() < b.get_owner(); });
    }
    std::string out;
    for(auto& t : list){
        out += (t.str() + "\n");
    }
    return out;
}

void service::add_cart(int apartment) {

    auto el = repo.find(apartment);

    if(!el.has_value()){
        throw my_exception("Not found");
    }

    const auto& temp_list = temp_cart.get_list();

    auto temp = std::find(temp_list.begin(), temp_list.end(), *el.value());

    if(temp != temp_list.end()){
        throw my_exception("Already exists");
    }

    temp_cart.add(*el.value());
}

void service::empty_cart() {
    temp_cart.empty();
}

void service::random_cart(int num) {
    const auto &list = repo.get_list();
    const auto &cart_list = temp_cart.get_list();


    std::vector<tenant> temp_list;

    for(const auto& el: list){
        if(std::find(cart_list.begin(), cart_list.end(), el) == cart_list.end()){
            temp_list.push_back(el);
        }
    }

    if(temp_list.empty()){
        throw my_exception("No tenants");
    }

    if(temp_list.size() < num){
        for(const auto& el: temp_list){
            temp_cart.add(el);
        }
        throw my_exception("Too few");
    }
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();

    while(num > 0){
        std::shuffle(temp_list.begin(), temp_list.end(), std::default_random_engine(seed));
        temp_cart.add(temp_list.back());
        temp_list.pop_back();
        num--;
    }
}

void service::export_cart(const std::string& file) {
    auto list = temp_cart.get_list();

    std::ofstream out;
    out.open("./" + file + extension);

    for(const auto& el: list){
        out<<el.str()<<std::endl;
    }

    out.close();
}
