//
// Created by Gustavo on 01/06/26.
//
#include "../structs/Fila.h"
#include <stdio.h>
#include <stdlib.h>

void inserir(Fila* f, NoFila* no) {
    if (f == NULL || no == NULL) return;

    no->proximo = NULL;
    no->anterior = NULL;

    if (f->inicio == NULL) {
        f->inicio = no;
        f->fim = no;
    } else {
        f->fim->proximo = no;
        no->anterior = f->fim;
        f->fim = no;
    }
    f->tamanho++;
}

Agendamento* remover(Fila* f, int id) {
    if (f == NULL || f->inicio == NULL) return NULL;

    NoFila* atual = f->inicio;

    while (atual != NULL) {
        if (atual->dados != NULL && atual->dados->id == id) {
            Agendamento* dadosRetorno = atual->dados;

            if (atual == f->inicio && atual == f->fim) {
                f->inicio = NULL;
                f->fim = NULL;
            }

            else if (atual == f->inicio) {
                f->inicio = atual->proximo;
                f->inicio->anterior = NULL;
            }

            else if (atual == f->fim) {
                f->fim = atual->anterior;
                f->fim->proximo = NULL;
            }
            else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }

            free(atual);
            f->tamanho--;
            return dadosRetorno;
        }
        atual = atual->proximo;
    }
    return NULL;
}

Agendamento* buscar(Fila* f, int id) {
    if (f == NULL) return NULL;

    NoFila* atual = f->inicio;
    while (atual != NULL) {
        if (atual->dados != NULL && atual->dados->id == id) {
            return atual->dados;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void listarFila(Fila* f) {
    if (f == NULL || f->inicio == NULL) {
        printf("Fila Vazia \n");
        return;
    }

    NoFila* atual = f->inicio;
    printf("Elementos da Fila (total: %d) \n", f->tamanho);
    while (atual != NULL) {
        if (atual->dados != NULL) {
            printf("[ID: %d | Nome: %s]\n", atual->dados->id, atual->dados->nome);
        }
        atual = atual->proximo;
    }
}

int estaVaziaFila(Fila* f) {
    if (f == NULL || f->inicio == NULL) {
        return 1;
    }
    return 0;
}