//
// Created by Gustavo on 01/06/26.
//

#include "NoPilha.h"

void empilharProximo(NoPilha* atual , NoPilha* proximo) {
    if (atual != NULL) {
        atual -> proximo = proximo;
    }
}

Agendamento* obterAgendamento(NoPilha* atual) {
    if(no != NULL) {
        return no->dados;
    }
    return NULL;
}