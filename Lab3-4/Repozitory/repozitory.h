#pragma once

#include "../Domain/participant.h"

typedef struct repo repo;

repo* repo_initialization();

void repo_destructor(repo* array);

void repo_nume_sort(repo* array, int(*cmp)(const char*, const char*));

/*
void repo_scor_sort_increasing(repo* array);

void repo_scor_sort_decreasing(repo* array);

void repo_name_sort_increasing(repo* array);

void repo_name_sort_decreasing(repo* array);
*/

void repo_add(repo* array, type_participant *participant);

int repo_delete(repo* array, int id);

int repo_get_size(repo* array);

void repo_scor_sort(repo* array, int(*cmp)(const int, int));

type_participant * repo_get_by_id(repo* array, int id);

void repo_test();

