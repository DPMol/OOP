#include <stdlib.h>
#include <string.h>

#include "service.h"
#include "stdio.h"

int service_delete(char *id){
    if(!is_id(id))
        return 0;
    if(repo_delete(atoi(id)) == 1)
        return 1;
    return 2;
}


char* service_debug(){
    int end = repo_get_size();
    char *out = (char *) malloc(end*114);
    char scor[4];
    out[0] = 0;
    type_participant *participant;
    for(int i = 0; i < end; i++){
        participant = repo_get_by_id(i);
        strcat(out, participant->nume);
        strcat(out, " ");
        strcat(out, participant->prenume);
        strcat(out, " ");
        sprintf(scor,"%d", participant->scor);
        strcat(out, scor);
        strcat(out, "/100\n");
    }
    return out;
}

int service_modify(char *id, char *nume, char *prenume, char *scor){
    if(!(is_name(nume) && is_name(prenume) && is_score(scor) && is_id(id)))
        return 0;
    type_participant *participant = repo_get_by_id(atoi(id));
    if(participant == NULL)
        return 2;
    strcpy(participant->nume, nume);
    strcpy(participant->prenume, prenume);
    participant->scor = atoi(scor);
    return 1;
}

int service_add(char *nume, char *prenume, char *scor){
    if(!(is_name(nume) && is_name(prenume) && is_score(scor)))
        return 0;
    printf("%s, %s, %s\n", nume, prenume, scor);
    type_participant *participant = (type_participant *)malloc(sizeof(type_participant));
    strcpy(participant->nume, nume);
    strcpy(participant->prenume, prenume);
    participant->scor = atoi(scor);
    repo_add(participant);
    return 1;
}