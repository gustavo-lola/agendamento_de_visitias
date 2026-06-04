#ifndef PILHA_H
#define PILHA_H

#include "../agendamento/agendamento.h"

typedef struct NoPilha {
    Agendamento* agendamento;
    struct NoPilha* prox;
} NoPilha;

typedef struct {
    NoPilha* topo;
} Pilha;

Pilha* criarPilha();
void empilhar(Pilha* pilha, Agendamento* agendamento);
Agendamento* desempilhar(Pilha* pilha);
Agendamento* topoPilha(Pilha* pilha);
void listarPilha(Pilha* pilha);
void liberarPilha(Pilha* pilha);

#endif // PILHA_H
