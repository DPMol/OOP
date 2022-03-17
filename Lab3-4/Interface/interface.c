#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

struct interface{
    service* srv;
};

interface* interface_initialization(service* srv){
    //functie de initializare a obiectului de interfata
    interface* ui = malloc(sizeof(interface));
    ui->srv = srv;
    return ui;
}

void interface_destructor(interface* ui){
    //strica obicectul de interfata
    free(ui);
}

char command_sep[] = " ";

void interface_delete(service* srv){
    //functie de stergere a unui obiect
    char *id;
    id = strtok(NULL, command_sep);

    if(id == NULL){
        printf("Too few arguments were given\n");
    }
    else if(strtok(NULL, command_sep) != NULL){
        printf("Too many arguments were give\n");
    }
    else{
        int p = service_delete(srv, id);
        if(p == 1){
            printf("Delete was successful\n");
        }
        else if(p == 2){
            printf("No participant with given id was found\n");
        }
        else{
            printf("One or more arguments were incorrect\n");
        }
    }

}

void interface_modify(service* srv){
    //noo i doent wanna write no more
    char *id, *nume, *prenume, *scor;
    id = strtok(NULL, command_sep);
    nume = strtok(NULL, command_sep);
    prenume = strtok(NULL, command_sep);
    scor = strtok(NULL, command_sep);

    if(id == NULL || nume == NULL || prenume == NULL || scor == NULL){
        printf("Too few arguments were given\n");
    }
    else if(strtok(NULL, command_sep) != NULL){
        printf("Too many arguments were give\n");
    }
    else{
        int p = service_modify(srv, id, nume, prenume, scor);
        if(p == 1){
            printf("Modify was successful\n");
        }
        else if(p == 2){
            printf("No participant with given id was found\n");
        }
        else{
        printf("One or more arguments were incorrect\n");
        }
    }
}

void interface_filter(service* srv){
    char *scor;
    scor = strtok(NULL, command_sep);
    if(scor == NULL){
        printf("Too few arguments were given\n");
    }
    else if(strtok(NULL, command_sep) != NULL){
        printf("Too many arguments were give\n");
    }
    else{
        char* out = service_show(srv, scor);
        if(out == NULL)
            printf("One or more arguments were incorrect\n");
        else if(strlen(out) == 0)
            printf("No students were found\n");
        else{
            printf("%s", out);
            free(out);
        }
    }
}

void interface_add(service* srv){
    char *nume, *prenume, *scor;
    nume = strtok(NULL, command_sep);
    prenume = strtok(NULL, command_sep);
    scor = strtok(NULL, command_sep);

    if(nume == NULL || prenume == NULL || scor == NULL){
        printf("Too few arguments were given\n");
    }
    else if(strtok(NULL, command_sep) != NULL){
        printf("Too many arguments were give\n");
    }
    else if(service_add(srv, nume, prenume, scor)){
        printf("Add was successful\n");
    }
    else{
        printf("One or more arguments were incorrect\n");
    }
}

void interface_debug(service* srv){
    char *string;
    string = service_debug(srv);
    printf("%s", string);
    free(string);
}

void interface_sort(service* srv){
    char *key, *order ;
    key = strtok(NULL, command_sep);
    order = strtok(NULL, command_sep);

    if(key == NULL || order == NULL){
        printf("Too few arguments were given\n");
    }
    else if(strtok(NULL, command_sep) != NULL){
        printf("Too many arguments were give\n");
    }
    else if(service_sort(srv, key, order)){
        printf("Sort was successful\n");
    }
    else{
        printf("One or more arguments were incorrect\n");
    }
}

short int get_command(interface* ui){
    char input[1000];
    printf("Command:");
    gets(input);
    char *command = strtok(input, command_sep);
    if(!strcmp(command, "exit")){
        return 0;
    }
    else if(!strcmp(command, "add")){
        interface_add(ui->srv);
    }
    else if(!strcmp(command, "modify")){
        interface_modify(ui->srv);
    }
    else if(!strcmp(command, "debug")){
        interface_debug(ui->srv);
    }
    else if(!strcmp(command, "delete")){
        interface_delete(ui->srv);
    }
    else if(!strcmp(command, "filter")){
        interface_filter(ui->srv);
    }
    else if(!strcmp(command, "sort")){
        interface_sort(ui->srv);
    }
    else
        printf("Command doesn't exist\n");
    return 1;
}

void interface_run(interface* ui){
    short int Run = 1;
    while(Run){
        Run = get_command(ui);
    }
}


