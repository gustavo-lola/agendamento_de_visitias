#include "Pilha.h"
#include "../modules/agendamento/agendamento.h"
#include <stdio.h>
#include <stdlib.h>

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }
    return pilha;
}

void empilhar(Pilha* p, Agendamento* ag) {
    if (p == NULL || ag == NULL) return;

    No* no = (No*)malloc(sizeof(No));
    if (no == NULL) return;

    no->dados = ag;
    no->proximo = p->topo;
    no->anterior = NULL;

    p->topo = no;
    p->tamanho++;
}

Agendamento* desempilhar(Pilha* p) {
    if (p == NULL || p->topo == NULL) return NULL;

    No* noRemovido = p->topo;
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

int estaVaziaPilha(Pilha* p) {
    return (p == NULL || p->topo == NULL);
}

void listarPilha(Pilha* p) {
    if (p == NULL || p->topo == NULL) {
        printf("Historico vazio\n");
        return;
    }

    No* atual = p->topo;
    printf("Historico (total: %d)\n", p->tamanho);
    printf("---------------------------\n");

    while (atual != NULL) {
        if (atual->dados != NULL) {
            printf("[ID: %d | Nome: %s]\n", atual->dados->id, atual->dados->usuario);
            printf("---------------------------\n");
        }
        atual = atual->proximo;
    }
}

void liberarPilha(Pilha* p) {
    if (p == NULL) return;

    No* atual = p->topo;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;

        if (temp->dados != NULL) {
            free(temp->dados);
        }
        free(temp);
    }
    free(p);
}
