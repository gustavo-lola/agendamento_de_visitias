//
// Created by Gustavo on 01/06/26.
//
#include "NoFila.h"

void conectarProximo(NoFila* atual, NoFila* proximo) {
    if (atual != NULL) {
        autal->proximo = proximo;
    }
}

void conectarAnterior(NoFila* atual, NoFila* anterior) {
    if(atual != NULL) {
        atual->anterior = anterior;
    }
}

agendamento* obterDadosFila(NoFila* no) {
    if (no != Null) {
        return no->dados;
    }
    return NULL;
}