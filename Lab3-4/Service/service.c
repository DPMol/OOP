#include <stdlib.h>
#include <string.h>
#include "service.h"
#include "stdio.h"

struct service{
    repo* repo;
};

service* service_initialization(repo* repo){
    service* srv = malloc(sizeof(service));
    srv->repo = repo;
    return srv;
}

void service_destructor(service *srv){
    free(srv);
}

int service_delete(service* srv, char *id){
    if(!is_id(id))
        return 0;
    if(repo_delete(srv->repo, atoi(id)) == 1)
        return 1;
    return 2;
}


char* service_debug(service* srv){
    int end = repo_get_size(srv->repo);
    char *out = (char *) malloc(end*224);
    char scor[4];
    out[0] = 0;
    type_participant *participant;
    for(int i = 0; i < end; i++){
        participant = repo_get_by_id(srv->repo,i);
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

int service_modify(service* srv, char *id, char *nume, char *prenume, char *scor){
    if(!(is_name(nume) && is_name(prenume) && is_score(scor) && is_id(id)))
        return 0;
    type_participant *participant = repo_get_by_id(srv->repo,atoi(id));
    if(participant == NULL)
        return 2;

    set_nume(participant, nume);
    set_prenume(participant, prenume);
    set_scor(participant, atoi(scor));
    return 1;
}

int service_add(service* srv, char *nume, char *prenume, char *scor){
    if(!(is_name(nume) && is_name(prenume) && is_score(scor)))
        return 0;
    type_participant *participant = create_participant(nume, prenume, atoi(scor));
    repo_add(srv->repo, participant);
    return 1;
}