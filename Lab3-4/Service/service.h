#pragma once

#include "../Repozitory/repozitory.h"
#include "../Domain/participant.h"
#include "../Validators/validators.h"

typedef struct service service;

service * service_initialization(repo* repo);

int service_sort(service* srv, char* key, char* order);

char* service_show(service* srv, char* scor);

void service_destructor(service *srv);

int service_add(service* srv, char *nume, char *prenume, char *scor);

int service_modify(service* srv, char *id, char *nume, char *prenume, char *scor);

int service_delete(service* srv, char *id);

char* service_debug(service* srv);

void service_test();