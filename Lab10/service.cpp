#include "service.h"

service::service(Repository& repo): repo(repo) {}

void service::add(int apartment, std::string& owner, std::string& type, int area){

    auto temp = repo.find(apartment);
    if(temp.has_value()){
        throw my_exception("Apartment already exists");
    }
    tenant t(apartment, owner, type, area);
    repo.add(t);

    undo_list.push_back(std::make_unique<UndoAdd>(repo, apartment));
}

void service::del(int apartment){
    auto element = repo.find(apartment);
    if(!element.has_value()){
        throw my_exception("Apartment doesn't exist");
    }
    undo_list.push_back(std::make_unique<UndoDel>(repo, *element.value()));
    repo.del(element.value());
}

std::vector<tenant> service::get_list() {

    return repo.get_list();
}

std::vector<tenant> service::get_list(std::string field, int reverse)
{
    auto list = repo.get_list();
    if(field.empty()){
        return list;
    }
    if(field == "Apartment"){
        std::sort(list.begin(), list.end(), [](const tenant& a,const tenant& b){return a.get_apartment()<b.get_apartment();});
    }else if(field == "Type"){
        std::sort(list.begin(), list.end(), [](const tenant& a,const tenant& b){return a.get_type()<b.get_type();});
    }else if(field == "Owner"){
        std::sort(list.begin(), list.end(), [](const tenant& a,const tenant& b){return a.get_owner()<b.get_owner();});
    }else if(field == "Area"){
        std::sort(list.begin(), list.end(), [](const tenant& a,const tenant& b){return a.get_area()<b.get_area();});
    }

    if(reverse){
        std::reverse(list.begin(), list.end());
    }
    return list;
}

void service::modify(int apartment, int new_apartment,
                     std::string &new_owner, std::string &new_type, int new_area) {

    auto element = repo.find(apartment);
    if(!element.has_value()){
        throw my_exception("Apartment doesn't exist");
    }

    tenant t(new_apartment, new_owner, new_type, new_area);


    undo_list.push_back(std::make_unique<UndoMod>(repo, new_apartment, *element.value()));
    repo.del(element.value());
    repo.add(t);

}


void service::undo() {
    if(undo_list.empty()){
        throw my_exception("Kinda empty bro");
    }

    undo_list.back()->undo();
    undo_list.pop_back();
}
