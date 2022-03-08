#ifndef LAB3_4_PARTICIPANT_H
#define LAB3_4_PARTICIPANT_H

struct type_participant;

typedef struct type_participant type_participant;

type_participant* create_participant(char* nume, char*prenume, int scor);

void destory_participant(type_participant* participant);

void set_nume(type_participant* participant, char* nume);

void set_prenume(type_participant* participant, char* prenume);

void set_scor(type_participant* participant, int scor);

const char* get_nume(type_participant* participant);

const char* get_prenume(type_participant* participant);

int get_scor(type_participant* participant);

#endif //LAB3_4_PARTICIPANT_H
