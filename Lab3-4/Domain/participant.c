#include "participant.h"
#include "stdlib.h"
#include "string.h"

int settings_max_char = 50;


type_participant* create_participant(char* nume, char*prenume, int scor){
    type_participant* participant = malloc(sizeof(type_participant));

    participant->nume = malloc(settings_max_char + 1);
    strcpy(participant->nume, nume);

    participant->prenume = malloc(settings_max_char + 1);
    strcpy(participant->prenume, prenume);

    participant->scor = scor;

    return participant;
}

void destory_participant(type_participant* participant){
    free(participant->nume);
    free(participant->prenume);
    free(participant);
}