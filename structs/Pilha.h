#ifndef AGENDAMENTO_DE_VISITIAS_PILHA_H
#define AGENDAMENTO_DE_VISITIAS_PILHA_H

#include "No.h"

typedef struct {
    No* topo;
    int tamanho;
} Pilha;

Pilha* criarPilha();
void empilhar(Pilha* p, Agendamento* ag);
Agendamento* desempilhar(Pilha* p);
Agendamento* consultarTopo(Pilha* p);
void listarPilha(Pilha* p);
int estaVaziaPilha(Pilha* p);
void liberarPilha(Pilha* p);

#endif // AGENDAMENTO_DE_VISITIAS_PILHA_H
