#include <iostream>
#include "Repository/repository.h"
#include "Service/service.h"
#include "Interface/interface.h"

int main() {
    repository repo;
    service srv(repo);
    interface ui(srv);
    ui.run();
    return 0;
}
