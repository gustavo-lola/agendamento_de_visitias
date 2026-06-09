#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->tamanho = 0;
    }
    return fila;
}

void inserirFila(Fila* fila, Agendamento* agendamento) {
    if (fila == NULL || agendamento == NULL) {
        return;
    }

    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        return;
    }

    novo->dados = agendamento;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        novo->anterior = fila->fim;
        fila->fim = novo;
    }
    fila->tamanho++;
}


Agendamento* removerFila(Fila* fila, int id) {
    if (fila == NULL || fila->inicio == NULL) {
        return NULL;
    }

    No* atual = fila->inicio;

    while (atual != NULL) {
        if (atual->dados != NULL && atual->dados->id == id) {
            Agendamento* agendamentoRetorno = atual->dados;

            if (atual == fila->inicio && atual == fila->fim) {
                fila->inicio = NULL;
                fila->fim = NULL;
            }
            else if (atual == fila->inicio) {
                fila->inicio = atual->proximo;
                fila->inicio->anterior = NULL;
            }
            else if (atual == fila->fim) {
                fila->fim = atual->anterior;
                fila->fim->proximo = NULL;
            }
            else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }

            free(atual);
            fila->tamanho--;
            return agendamentoRetorno;
        }

        atual = atual->proximo;
    }

    return NULL;
}

Agendamento* buscarFila(Fila* fila, int id) {
    if (fila == NULL) {
        return NULL;
    }
    No* atual = fila->inicio;
    while (atual != NULL) {
        if (atual->dados != NULL && atual->dados->id == id) {
            return atual->dados;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void listarFila(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL) {
        printf("Nenhum agendamento cadastrado.\n");
        return;
    }
    No* atual = fila->inicio;
    printf("Elementos da Fila (total: %d):\n", fila->tamanho);
    printf("---------------------------\n");
    while (atual != NULL) {
        if (atual->dados != NULL) {
            obterResumo(atual->dados);
            printf("---------------------------\n");
        }
        atual = atual->proximo;
    }
}

int estaVaziaFila(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL) {
        return 1;
    }
    return 0;
}

void liberarFila(Fila* fila) {
    if (fila == NULL) {
        return;
    }
    No* atual = fila->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        if (temp->dados != NULL) {
            free(temp->dados);
        }
        free(temp);
    }
    free(fila);
}
