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
    char *out = (char *) malloc(end*224);
    char scor[4];
    out[0] = 0;
    type_participant *participant;
    for(int i = 0; i < end; i++){
        participant = repo_get_by_id(i);
        strcat(out, get_nume(participant));
        strcat(out, " ");
        strcat(out, get_prenume(participant));
        strcat(out, " ");
        sprintf(scor,"%d", get_scor(participant));
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

    set_nume(participant, nume);
    set_prenume(participant, prenume);
    set_scor(participant, atoi(scor));
    return 1;
}

int service_add(char *nume, char *prenume, char *scor){
    if(!(is_name(nume) && is_name(prenume) && is_score(scor)))
        return 0;
    type_participant *participant = create_participant(nume, prenume, atoi(scor));
    repo_add(participant);
    return 1;
}