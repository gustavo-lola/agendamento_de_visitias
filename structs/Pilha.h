#ifndef AGENDAMENTO_DE_VISITIAS_PILHA_H
#define AGENDAMENTO_DE_VISITIAS_PILHA_H
#include "NoPilha.h"

typedef struct {
    NoPilha* topo;
    int tamanho;
} Pilha;

void empilhar(Pilha* p, NoPilha* no);
Agendamento* desempilhar(Pilha* p);
Agendamento* consultarTopo(Pilha* p);
void listarPilha(Pilha* p);
int estaVaziaPilha(Pilha* p);

#endif //AGENDAMENTO_DE_VISITIAS_PILHA_H