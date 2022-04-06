#include "Repository/repository.h"
#include "Service/service.h"
#include "Interface/interface.h"
#include "test/test.h"

int main() {
    test::run();
    repository repo;
    service srv(repo);
    interface ui(srv);
    ui.run();
    return 0;
}
