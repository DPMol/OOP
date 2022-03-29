#include "repozitory.h"
#include "stdlib.h"
#include <assert.h>
#include <stdio.h>
struct repo{
    void **list;
    int size;
    int capacity;
    int globalId;
};

void repo_default_values(repo* array){
    type_participant * participant;

    participant = create_participant(get_global_id(array),"Ciota", "Dragos", 17);
    repo_add(array, participant);

    participant = create_participant(get_global_id(array),"Mircea", "Gabi", 69);
    repo_add(array, participant);

    participant = create_participant(get_global_id(array),"Tzanca", "Uraganu", 50);
    repo_add(array, participant);

    participant = create_participant(get_global_id(array),"Neamtu", "Iuli", 99);
    repo_add(array, participant);

    participant = create_participant(get_global_id(array),"Moldovan", "Denis-Angel", 10);
    repo_add(array, participant);


}

repo* repo_initialization(){
    repo *array = malloc(sizeof(repo));
    array->globalId = 0;
    array->size = 0;
    array->capacity = 2;
    array->list = malloc(array->capacity* sizeof(type_participant*));
    repo_default_values(array);

    return array;
}

void repo_destructor(repo* array){
    for(int i = 0; i < array->size; i++){
        destroy_participant(array->list[i]);}
    free (array->list);
    free(array);
}

void repo_realloc(repo* array, int newcapacity){
    void **newlist = malloc(newcapacity* sizeof(type_participant*));
    for(int i = 0; i < array->size; i++){
        newlist[i] = array->list[i];
    }
    free(array->list);
    array->list = newlist;
    array->capacity = newcapacity;
}

int repo_delete(repo* array, int id){
    int i = 0;
    while(get_id(array->list[i]) != id && i < array->size){
        i++;
    }
    if(i >= array->size)
        return 0;
    array->size--;
    destroy_participant(array->list[i]);
    for(; i < array->size; i++){
        array->list[i] = array->list[i+1];
    }
    return 1;
}

int get_global_id(repo* array){
    return array->globalId;
}

void repo_add(repo* array, type_participant *participant){
    if(array->size >= array->capacity){
        repo_realloc(array, 2 * array->size);
    }
    array->globalId++;
    array->list[array->size++] = participant;
}

type_participant * repo_get_by_id(repo* array, int id){
    for(int i = 0; i< array->size; i++)
        if(get_id(array->list[i])==id)
            return array->list[i];
    return NULL;
}

int repo_get_size(repo* array){
    return array->size;
}
/*
void repo_scor_sort_increasing(repo* array){
    type_participant* temp;
    for(int i = 0; i < array->size; i++)
        for(int j = 0; j< array->size; j++)
            if(get_scor(array->list[i]) < get_scor(array->list[j])){
                temp = array->list[i];
                array->list[i] = array->list[j];
                array->list[j] = temp;
            }
}

void repo_scor_sort_decreasing(repo* array){
    type_participant* temp;
    for(int i = 0; i < array->size; i++)
        for(int j = 0; j< array->size; j++)
            if(get_scor(array->list[i]) > get_scor(array->list[j])){
                temp = array->list[i];
                array->list[i] = array->list[j];
                array->list[j] = temp;
            }
}

void repo_name_sort_increasing(repo* array){
    type_participant* temp;
    for(int i = 0; i < array->size; i++)
        for(int j = 0; j< array->size; j++)
            if(strcmp(get_nume(array->list[i]), get_nume(array->list[j])) < 0){
                temp = array->list[i];
                array->list[i] = array->list[j];
                array->list[j] = temp;
            }
}

void repo_name_sort_decreasing(repo* array){
    type_participant* temp;
    for(int i = 0; i < array->size; i++)
        for(int j = 0; j< array->size; j++)
            if(strcmp(get_nume(array->list[i]), get_nume(array->list[j])) > 0){
                temp = array->list[i];
                array->list[i] = array->list[j];
                array->list[j] = temp;
            }
}
*/

void repo_scor_sort(repo* array, int(*cmp)(const int, const int)){
    type_participant* temp;
    for(int i = 0; i < array->size; i++)
        for(int j = 0; j< array->size; j++)
            if(cmp(get_scor(array->list[i]), get_scor(array->list[j]))){
                temp = array->list[i];
                array->list[i] = array->list[j];
                array->list[j] = temp;
            }
}

void repo_nume_sort(repo* array, int(*cmp)(const char*, const char*)){
    type_participant* temp;
    for(int i = 0; i < array->size; i++)
        for(int j = 0; j< array->size; j++)
            if(cmp(get_nume(array->list[i]), get_nume(array->list[j]))){
                temp = array->list[i];
                array->list[i] = array->list[j];
                array->list[j] = temp;
            }
}

void repo_test(){
    repo *repo = NULL;
    repo = repo_initialization();

    assert(repo != NULL);
    assert(repo_get_size(repo) == 5);
    type_participant* participant = repo_get_by_id(repo, 0);

    assert(get_scor(participant) == 17);

    repo_add(repo, participant);
    assert(repo_get_size(repo) == 6);

    repo_delete(repo, 0);
    assert(repo_get_size(repo) == 5);

    repo_realloc(repo, 100);
    assert(repo->capacity == 100);

    /*
    repo_scor_sort_increasing(repo);
    assert(repo_get_by_id(repo, 1) == participant);

    repo_scor_sort_decreasing(repo);
    assert(repo_get_by_id(repo, 3) == participant);

    repo_name_sort_decreasing(repo);
    assert(repo_get_by_id(repo, 0) == participant);

    repo_name_sort_increasing(repo);
    assert(repo_get_by_id(repo, 4) == participant);
     */
    repo->size--;

    repo_destructor(repo);
}