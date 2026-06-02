//
// Created by Gustavo on 01/06/26.
//
#include "NoFila.h"

void conectarProximo(NoFila* atual, NoFila* proximo) {
    if (atual != NULL) {
        atual->proximo = proximo;
    }
}

void conectarAnterior(NoFila* atual, NoFila* anterior) {
    if(atual != NULL) {
        atual->anterior = anterior;
    }
}

Agendamento* obterDadosFila(NoFila* no) {
    if (no != NULL) {
        return no->dados;
    }
    return NULL;
}