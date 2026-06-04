#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha->topo = NULL;
    }
    return pilha;
}

void empilhar(Pilha* pilha, Agendamento* agendamento) {
    if (pilha == NULL || agendamento == NULL) {
        return;
    }
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    if (novo == NULL) {
        return;
    }
    novo->agendamento = agendamento;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

Agendamento* desempilhar(Pilha* pilha) {
    if (pilha == NULL || pilha->topo == NULL) {
        return NULL;
    }
    NoPilha* temp = pilha->topo;
    Agendamento* agendamento = temp->agendamento;
    pilha->topo = temp->prox;
    free(temp);
    return agendamento;
}

Agendamento* topoPilha(Pilha* pilha) {
    if (pilha == NULL || pilha->topo == NULL) {
        return NULL;
    }
    return pilha->topo->agendamento;
}

void listarPilha(Pilha* pilha) {
    if (pilha == NULL || pilha->topo == NULL) {
        printf("Histórico vazio.\n");
        return;
    }
    NoPilha* atual = pilha->topo;
    while (atual != NULL) {
        if (atual->agendamento != NULL) {
            obterResumo(atual->agendamento);
            printf("---------------------------\n");
        }
        atual = atual->prox;
    }
}

void liberarPilha(Pilha* pilha) {
    if (pilha == NULL) {
        return;
    }
    NoPilha* atual = pilha->topo;
    while (atual != NULL) {
        NoPilha* temp = atual;
        atual = atual->prox;
        if (temp->agendamento != NULL) {
            free(temp->agendamento);
        }
        free(temp);
    }
    free(pilha);
}
