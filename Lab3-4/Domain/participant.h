#pragma once

struct type_participant;

typedef struct type_participant type_participant;

type_participant* create_participant(int id, char* nume, char *prenume, int scor);

void destroy_participant(type_participant* participant);

void set_nume(type_participant* participant, char* nume);

void set_prenume(type_participant* participant, char* prenume);

void set_scor(type_participant* participant, int scor);

int get_id(type_participant* participant);

const char* get_nume(type_participant* participant);

const char* get_prenume(type_participant* participant);

int get_scor(type_participant* participant);

void domain_test();