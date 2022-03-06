#include "Interface/interface.h"
#include "Repozitory/repozitory.h"

int main() {
    repo_initialization();
    interface_run();
    repo_destructor();
    return 0;
}
