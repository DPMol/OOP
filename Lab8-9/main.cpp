#include "Repository/repository.h"
#include "NewRepository/newrepository.h"
#include "Service/service.h"
#include "Interface/interface.h"
#include "test/test.h"

int main() {
    //test::run();
    newrepository repo;
    service srv(repo);
    interface ui(srv);
    ui.run();
    return 0;
}
