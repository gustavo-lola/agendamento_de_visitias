#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}

void inserirFila(Fila* fila, Agendamento* agendamento) {
    if (fila == NULL || agendamento == NULL) {
        return;
    }
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    if (novo == NULL) {
        return;
    }
    novo->agendamento = agendamento;
    novo->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

Agendamento* removerFila(Fila* fila, int id) {
    if (fila == NULL || fila->inicio == NULL) {
        return NULL;
    }

    NoFila* atual = fila->inicio;
    NoFila* anterior = NULL;

    while (atual != NULL) {
        if (atual->agendamento != NULL && atual->agendamento->id == id) {
            Agendamento* agendamento = atual->agendamento;

            if (anterior == NULL) {
                // Removendo do inicio
                fila->inicio = atual->prox;
                if (fila->inicio == NULL) {
                    fila->fim = NULL;
                }
            } else {
                // Removendo do meio ou fim
                anterior->prox = atual->prox;
                if (atual == fila->fim) {
                    fila->fim = anterior;
                }
            }

            free(atual);
            return agendamento;
        }
        anterior = atual;
        atual = atual->prox;
    }

    return NULL;
}

Agendamento* buscarFila(Fila* fila, int id) {
    if (fila == NULL) {
        return NULL;
    }
    NoFila* atual = fila->inicio;
    while (atual != NULL) {
        if (atual->agendamento != NULL && atual->agendamento->id == id) {
            return atual->agendamento;
        }
        atual = atual->prox;
    }
    return NULL;
}

void listarFila(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL) {
        printf("Nenhum agendamento cadastrado.\n");
        return;
    }
    NoFila* atual = fila->inicio;
    while (atual != NULL) {
        if (atual->agendamento != NULL) {
            obterResumo(atual->agendamento);
            printf("---------------------------\n");
        }
        atual = atual->prox;
    }
}

void liberarFila(Fila* fila) {
    if (fila == NULL) {
        return;
    }
    NoFila* atual = fila->inicio;
    while (atual != NULL) {
        NoFila* temp = atual;
        atual = atual->prox;
        if (temp->agendamento != NULL) {
            free(temp->agendamento);
        }
        free(temp);
    }
    free(fila);
}
