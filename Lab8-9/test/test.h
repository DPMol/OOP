#pragma once

#include <cassert>
#include "../Domain/tenant.h"
#include "../Repository/repository.h"
#include "../Service/service.h"
#include "../NewRepository/newrepository.h"

class test{
public:
    static void run();

private:
    static void domain_test();

    static void service_test();

    static void repository_test();
};
