//
// Created by Gustavo on 01/06/26.
//
#include "../structs/Pilha.h"
#include <stdio.h>
#include <stdlib.h>

void empilhar(Pilha* p, NoPilha* no) {
    if (p == NULL || no == NULL) return;

    no->proximo = p->topo;
    p->topo = no;
    p->tamanho++;
}

Agendamento* desempilhar(Pilha* p) {
    if (p == NULL || p->topo == NULL) return NULL;

    NoPilha* noRemovido = p->topo;
    Agendamento* dados = noRemovido->dados;

    p->topo = noRemovido->proximo;
    free(noRemovido);
    p->tamanho--;

    return dados;
}

Agendamento* consultarTopo(Pilha* p) {
    if (p == NULL || p->topo == NULL) return NULL;
    return p->topo->dados;
}

void listarPilha(Pilha* p) {
    if (p == NULL || p->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    }

    NoPilha* atual = p->topo;
    printf("Historico (total: %d)\n", p->tamanho);
    while (atual != NULL) {
        if (atual->dados != NULL) {
            printf("[ID: %d | Nome: %s]\n", atual->dados->id, atual->dados->nome);
        }
        atual = atual->proximo;
    }
}

int estaVaziaPilha(Pilha* p) {
    if (p == NULL || p->topo == NULL) return 1;
    return 0;
}