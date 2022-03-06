#include "validators.h"
#include <ctype.h>
#include <stdlib.h>
#include "string.h"
#include <stdio.h>

char name_connectors[] = "- '";

int is_id(char *string){
    int index = 0;
    while(string[index] != 0)
    {
        if(!isdigit(string[index]))
            return 0;
        index++;
    }
    int number = atoi(string);
    return 1;
}

int is_score(char *string){
    int index = 0;
    while(string[index] != '\0')
    {
        if(!isdigit(string[index]))
            return 0;
        index++;
    }
    int number = atoi(string);
    if(number > 100 || number < 10)
        return 0;
    return 1;
}

int is_name(char *string){
    if(strlen(string) > 50)
        return 0;
    int index = 0, i;
    while(string[index] != 0)
    {
        if(!isalpha(string[index])){
            for(i = 0; name_connectors[i] != '\0';i++)
                if(string[index] == name_connectors[i])
                    break;
            if(name_connectors[i] == '\0')
                return 0;
        }
        index++;
    }
    return 1;
}