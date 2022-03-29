#include <stdlib.h>
#include <string.h>
#include "service.h"
#include "stdio.h"
#include "assert.h"

int plus(int a, int b){
    if(a<b){
        return 0;
    }
    return 1;
}

int minus(int a, int b){
    if(a<b){
        return 0;
    }
    return 1;
}

int nplus(const char *a, const char* b){
    if(strcmp(a,b) > 0){
        return 0;
    }
    return 1;
}

int nminus(const char* a, const char* b){
    if(strcmp(a,b) < 0){
        return 0;
    }
    return 1;
}

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
    int numar = strtol(id, NULL, 0);
    if(repo_delete(srv->repo, numar) == 1)
        return 1;
    return 2;
}

char* service_show(service* srv, char* scor){
    if(!is_score(scor))
        return NULL;

    type_participant *participant;
    int end = repo_get_size(srv->repo);

    int intscor = strtol(scor, NULL, 0);

    char *out = malloc(end * 300);
    out[0] = '\0';
    char cscor[1000];
    for(int i = 0; i < end; i++){

        participant = repo_get_by_id(srv->repo,i);

        if(get_scor(participant) >= intscor) {
            sprintf(cscor,"%d", get_id(participant));
            strcat(out, cscor);
            strcat(out, " ");
            strcat(out, get_nume(participant));
            strcat(out, " ");
            strcat(out, get_prenume(participant));

            strcat(out, " ");

            sprintf(cscor, "%d", get_scor(participant));

            strcat(out, cscor);
            strcat(out, "/100\n");

        }
    }
    return out;
}

int service_sort(service* srv, char* key, char* order){
    if(!(is_key(key) && is_order(order)))
        return 0;
    if(!strcmp(key, "scor")) {
        if (!strcmp(order, "+"))
            repo_scor_sort(srv->repo, &plus);
        else
            repo_scor_sort(srv->repo, &minus);
    }
    else{
        if (!strcmp(order, "+"))
            repo_nume_sort(srv->repo, &nplus);
        else
            repo_nume_sort(srv->repo, &nminus);
    }

    return 1;
}

char* service_debug(service* srv){
    int end = repo_get_size(srv->repo);
    char *out = (char *) malloc(end*224);
    char scor[4];
    out[0] = 0;
    type_participant *participant;
    for(int i = 0; i < end; i++){
        participant = repo_get_by_id(srv->repo,i);
        sprintf(scor,"%d", get_id(participant));
        strcat(out, scor);
        strcat(out, " ");
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
    int numar = strtol(id, NULL, 0);
    type_participant *participant = repo_get_by_id(srv->repo,numar);
    if(participant == NULL)
        return 2;
    numar = strtol(scor, NULL, 0);
    set_nume(participant, nume);
    set_prenume(participant, prenume);
    set_scor(participant, numar);
    return 1;
}

int service_add(service* srv, char *nume, char *prenume, char *scor){
    if(!(is_name(nume) && is_name(prenume) && is_score(scor)))
        return 0;
    int numar = strtol(scor, NULL, 0);
    type_participant *participant = create_participant(get_global_id(srv->repo),nume , prenume, numar);
    repo_add(srv->repo, participant);
    return 1;
}

void service_test(){
    repo* repo = repo_initialization();
    service* srv = service_initialization(repo);
    char* out = service_show(srv, "10");

    assert(strlen(out) != 0);
    free(out);
    out = service_debug(srv);
    free(out);

    assert(service_add(srv, "Oti" ,"Linux", "69") == 1);
    assert(service_add(srv, "Oti" ,"Linux", "sasenoua") == 0);

    assert(service_modify(srv,"1", "Oti" ,"Linux", "sasenoua") == 0);
    assert(service_modify(srv,"1", "Oti" ,"Linux", "26") == 1);
    assert(service_modify(srv,"100", "Oti" ,"Linux", "10") == 2);

    assert(service_sort(srv, "Gabi", "GABITZU") == 0);
    assert(service_sort(srv, "nume", "+"));
    assert(!service_sort(srv, "nume", "da"));
    assert(service_sort(srv, "nume", "-"));
    assert(!service_sort(srv, "scor", "da"));
    assert(service_sort(srv, "scor", "+"));
    assert(service_sort(srv, "scor", "-"));

    assert(service_delete(srv, "1"));

    assert(service_delete(srv, "100"));

    assert(!service_delete(srv, "a1"));

    assert(service_show(srv, "ab") == NULL);

    service_destructor(srv);
    repo_destructor(repo);
}