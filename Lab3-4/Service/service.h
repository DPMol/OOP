#ifndef LAB3_4_SERVICE_H
#define LAB3_4_SERVICE_H

#include "../Repozitory/repozitory.h"
#include "../Domain/participant.h"
#include "../Validators/validators.h"

int service_add(char *nume, char *prenume, char *scor);

int service_modify(char *id, char *nume, char *prenume, char *scor);

int service_delete(char *id);

char* service_debug();
#endif //LAB3_4_SERVICE_H
