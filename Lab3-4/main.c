#include "Interface/interface.h"
#include "Repozitory/repozitory.h"
#include "Service/service.h"
#include "Validators/validators.h"
#include "Domain/participant.h"

int main() {
    repo_test();
    valid_test();
    domain_test();
    service_test();

    repo* repo = repo_initialization();
    service* srv = service_initialization(repo);
    interface* ui = interface_initialization(srv);

    interface_run(ui);

    repo_destructor(repo);
    service_destructor(srv);
    interface_destructor(ui);
    //bye bye
    return 0;
}