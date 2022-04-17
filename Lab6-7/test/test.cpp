#include "test.h"

void test::run() {
    domain_test();
    service_test();
    repository_test();
}

void test::domain_test() {
    tenant t(1, "Alin", "big", 1);
    assert(t.get_apartment() == 1);
    assert(t.get_area() == 1);
    assert(t.get_owner() == "Alin");
    assert(t.get_type() == "big");

    t.set_type("Bomba");

    t.set_owner("Bomba");

    t.set_apartment(1);

    t.set_area(321);

    auto str = t.str();

    assert(t == t);

    assert((t != t) == 0);

}

void test::service_test() {
    repository repo;
    service srv(repo);
    std::string name = "alin", type = "big";

    srv.add(1, name, type, 1);


    try{
        srv.add(1, name, type, 1);
        assert(false);
    }
    catch(...){
    }

    srv.modify(1, 10, name, type, 1);

    try{
        srv.modify(103211, 10, name, type, 1);
        assert(false);
    }
    catch(...){
    }

    std::string s;

    s = srv.show();
    s.clear();

    s = srv.find(10);
    s.clear();

    srv.del( 10);

    try{
        srv.del( 10);
        assert(false);
    }
    catch(...){
    }
}

void test::repository_test() {
    tenant t(1, "Alin", "big", 1);
    repository repo;

    repo.add(t);

    auto i = repo.find(t.get_apartment());

    assert(i == 0);

    auto& l = repo.get_list();

    auto p = repo.get_position(0);
    auto temp = p.str();
    temp.clear();

    assert(p == t);
}