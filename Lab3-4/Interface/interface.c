#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

char command_sep[] = " ";

void interface_add(){
    char *nume, *prenume, *scor;
    nume = strtok(NULL, command_sep);
    prenume = strtok(NULL, command_sep);
    scor = strtok(NULL, command_sep);

    if(nume == NULL || prenume == NULL || scor == NULL){
        printf("Too few arguments were given");
    }
    else if(strtok(NULL, command_sep) != NULL){
        printf("Too many arguments were give");
    }
    else if(serivice_add(nume, prenume, scor)){
        printf("Add was successful");
    }
    else{
        printf("One or more arguments were incorrect");
    }
}

short int get_command(){
    char *input = (char *)malloc(500);
    printf("Command:");
    scanf("%s", input);
    char *command = strtok(input, command_sep);
    if(!strcmp(command, "exit")){
        return 0;
    }
    else if(!strcmp(command, "add")){
        interface_add();
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


