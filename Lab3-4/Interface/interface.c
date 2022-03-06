#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

char command_sep[] = " ";

void interface_delete(){
    char *id;
    id = strtok(NULL, command_sep);

    if(id == NULL){
        printf("Too few arguments were given\n");
    }
    else if(strtok(NULL, command_sep) != NULL){
        printf("Too many arguments were give\n");
    }
    else{
        int p = service_delete(id);
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

void interface_modify(){
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
        int p = service_modify(id, nume, prenume, scor);
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

void interface_add(){
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
    else if(service_add(nume, prenume, scor)){
        printf("Add was successful\n");
    }
    else{
        printf("One or more arguments were incorrect\n");
    }
}

void interface_debug(){
    char *string;
    string = service_debug();
    printf("%s", string);
    free(string);
}

short int get_command(){
    char *input = (char *)malloc(500);
    printf("Command:");
    gets(input);
    char *command = strtok(input, command_sep);
    if(!strcmp(command, "exit")){
        return 0;
    }
    else if(!strcmp(command, "add")){
        interface_add();
    }
    else if(!strcmp(command, "modify")){
        interface_modify();
    }
    else if(!strcmp(command, "debug")){
        interface_debug();
    }
    else if(!strcmp(command, "delete")){
        interface_delete();
    }
    free(command);
    return 1;
}

void interface_run(){
    short int Run = 1;
    while(Run){
        Run = get_command();
    }
}


