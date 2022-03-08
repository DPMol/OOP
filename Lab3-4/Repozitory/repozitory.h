#ifndef LAB3_4_REPOZITORY_H
#define LAB3_4_REPOZITORY_H
#include "../Domain/participant.h"


void repo_initialization();

void repo_destructor();

void repo_add(type_participant *participant);

int repo_delete(int id);

int repo_get_size();

type_participant * repo_get_by_id(int id);

#endif //LAB3_4_REPOZITORY_H


