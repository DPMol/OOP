#include "repozitory.h"
#include "stdlib.h"

struct repo{
    void **list;
    int size;
    int capacity;

};

void repo_default_values(repo* array){
    type_participant * participant;

    participant = create_participant("Ciota", "Dragos", 17);
    repo_add(array, participant);

    participant = create_participant("Mircea", "Gabi", 69);
    repo_add(array, participant);

    participant = create_participant("Tzanca", "Uraganu", 50);
    repo_add(array, participant);

    participant = create_participant("Nematu", "Iuli", 100);
    repo_add(array, participant);

    participant = create_participant("Moldovan", "Denis-Angel", 10);
    repo_add(array, participant);
}

repo* repo_initialization(){
    repo *array = malloc(sizeof(repo));
    array->size = 0;
    array->capacity = 60;
    array->list = malloc(array->capacity* sizeof(type_participant*));
    repo_default_values(array);

    return array;
}

void repo_destructor(repo* array){
    for(int i = 0; i < array->size; i++)
        free(array->list[i]);
    free (array->list);
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
    if(id >= array->size)
        return 0;
    array->size--;
    destory_participant(array->list[id]);
    for(int i = id; i < array->size; i++){
        array->list[i] = array->list[i+1];}
    return 1;
}

void repo_add(repo* array, type_participant *participant){
    if(array->size >= array->capacity){
        repo_realloc(array, 2 * array->size);
    }
    array->list[array->size++] = participant;
}

type_participant * repo_get_by_id(repo* array, int id){
    if(id >= array->size)
        return NULL;
    return array->list[id];
}

int repo_get_size(repo* array){
    return array->size;
}
