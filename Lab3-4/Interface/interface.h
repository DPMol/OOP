#pragma once

#include "../Service/service.h"

typedef struct interface interface;

interface* interface_initialization(service* srv);

void interface_destructor(interface* ui);

void interface_run(interface* ui);
