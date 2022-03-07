#ifndef LAB3_4_PARTICIPANT_H
#define LAB3_4_PARTICIPANT_H

typedef struct {
    char *nume, *prenume;
    int scor;
}type_participant;

type_participant* create_participant(char* nume, char*prenume, int scor);

void destory_participant(type_participant* participant);

#endif //LAB3_4_PARTICIPANT_H
