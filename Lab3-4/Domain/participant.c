#include "participant.h"
#include "stdlib.h"
#include "string.h"

struct type_participant{
    char *nume, *prenume;
    int scor;
};

type_participant* create_participant(char* nume, char*prenume, int scor){
    type_participant* participant = malloc(sizeof(type_participant));

    participant->nume = malloc(strlen(nume) + 1);
    strcpy(participant->nume, nume);

    participant->prenume = malloc(strlen(prenume) + 1);
    strcpy(participant->prenume, prenume);

    participant->scor = scor;

    return participant;
}

void destory_participant(type_participant* participant){
    free(participant->nume);
    free(participant->prenume);
    free(participant);
}

void set_nume(type_participant* participant, char* nume){
    free(participant->nume);

    participant->nume = malloc(strlen(nume) + 1);
    strcpy(participant->nume, nume);
}

void set_prenume(type_participant* participant, char* prenume){
    free(participant->prenume);

    participant->prenume = malloc(strlen(prenume) + 1);
    strcpy(participant->prenume, prenume);
}

void set_scor(type_participant* participant, int scor){
    participant->scor = scor;
}

const char* get_nume(type_participant* participant){
    return participant->nume;
}

const char* get_prenume(type_participant* participant){
    return participant->prenume;
}

int get_scor(type_participant* participant){
    return participant->scor;
}