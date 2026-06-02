#ifndef AGENDAMENTO_DE_VISITIAS_NOPILHA_H
#define AGENDAMENTO_DE_VISITIAS_NOPILHA_H
#include "agendamento.h"

typedef struct NoPilha {
    Agendamento* dados;
    struct NoPilha* proximo;
} NoPilha;

void empilharProximo(NoPilha* atual, NoPilha* proximo);
Agendamento* obterDadosPilha(NoPilha* no);

#endif //AGENDAMENTO_DE_VISITIAS_NOPILHA_H