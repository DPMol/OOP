#include <stdlib.h>
#include <string.h>
#include "service.h"
#include "stdio.h"
#include "assert.h"


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

char* service_show(service* srv, char* scor){
    if(!is_score(scor))
        return NULL;

    type_participant *participant;
    int end = repo_get_size(srv->repo);

    int intscor = atoi(scor);

    char *out = malloc(end * 300);
    out[0] = '\0';
    char cscor[4];
    for(int i = 0; i < end; i++){

        participant = repo_get_by_id(srv->repo,i);

        if(get_scor(participant) >= intscor) {
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
            repo_scor_sort_increasing(srv->repo);
        else
            repo_scor_sort_decreasing(srv->repo);
    }
    else{
        if (!strcmp(order, "+"))
            repo_name_sort_increasing(srv->repo);
        else
            repo_name_sort_decreasing(srv->repo);
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

void service_test(){
    repo* repo = repo_initialization();
    service* srv = service_initialization(repo);
    char* out = service_show(srv, "10");

    assert(strlen(out) != 0);
    free(out);
    out = service_debug(srv);
    assert(!strcmp(out, "Ciota Dragos 17/100\n"
                                       "Mircea Gabi 69/100\n"
                                       "Tzanca Uraganu 50/100\n"
                                       "Neamtu Iuli 99/100\n"
                                       "Moldovan Denis-Angel 10/100\n"));

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