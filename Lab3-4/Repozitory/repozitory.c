#include "repozitory.h"
#include "stdlib.h"
#include "string.h"

typedef struct{
    type_participant **list;
    int size;
    int capacity;

}repo;

repo array;

void repo_default_values(){
    type_participant *participant = (type_participant *)malloc(sizeof(type_participant));
    strcpy(participant->nume, "Ciota");
    strcpy(participant->prenume, "Dragos");
    participant->scor = 17;

    repo_add(participant);

    participant = (type_participant *)malloc(sizeof(type_participant));
    strcpy(participant->nume, "Mircea");
    strcpy(participant->prenume, "Gabi");
    participant->scor = 69;

    repo_add(participant);

    participant = (type_participant *)malloc(sizeof(type_participant));
    strcpy(participant->nume, "Tzanca");
    strcpy(participant->prenume, "Uraganu");
    participant->scor = 99;

    repo_add(participant);

    participant = (type_participant *)malloc(sizeof(type_participant));
    strcpy(participant->nume, "Ciorba");
    strcpy(participant->prenume, "Sandu");
    participant->scor = 45;

    repo_add(participant);

    participant = (type_participant *)malloc(sizeof(type_participant));
    strcpy(participant->nume, "Moldovan");
    strcpy(participant->prenume, "Denis-Angel");
    participant->scor = 10;

    repo_add(participant);
}

void repo_initialization(){
    array.size = 0;
    array.capacity = 20;
    array.list = (type_participant **)malloc(sizeof(type_participant*));
    repo_default_values();
}

void repo_destructor(){
    for(int i = 0; i < array.size; i++)
        free(array.list[i]);
    free (array.list);
}

void repo_realloc(int newcapacity){
    type_participant **newlist = (type_participant **)malloc(sizeof(type_participant*));
    for(int i = 0; i < array.size; i++){
        newlist[i] = array.list[i];
    }
    free(array.list);
    array.list = newlist;
    array.capacity = newcapacity;
}

int repo_delete(int id){
    if(id >= array.size)
        return 0;
    array.size--;
    free(array.list[id]);
    for(int i = id; i < array.size; i++){
        array.list[i] = array.list[i+1];}
    return 1;
}

void repo_add(type_participant *participant){
    if(array.size >= array.capacity){
        repo_realloc(2 * array.size);
    }
    array.list[array.size++] = participant;
}

type_participant * repo_get_by_id(int id){
    if(id >= array.size)
        return NULL;
    return array.list[id];
}

int repo_get_size(){
    return array.size;
}
