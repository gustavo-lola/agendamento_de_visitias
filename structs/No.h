#ifndef AGENDAMENTO_DE_VISITIAS_NO_H
#define AGENDAMENTO_DE_VISITIAS_NO_H

#include "../modules/agendamento/agendamento.h"

typedef struct No {
    Agendamento* dados;
    struct No* proximo;
    struct No* anterior;
} No;

#endif // AGENDAMENTO_DE_VISITIAS_NO_H
