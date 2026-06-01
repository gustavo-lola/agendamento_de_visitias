//
// Created by Gustavo on 01/06/26.
//

#ifndef AGENDAMENTO_DE_VISITIAS_NOFILA_H
#define AGENDAMENTO_DE_VISITIAS_NOFILA_H
#include "agendamento.h"

typedef struct NoFila {
    //ponteiros o proximo e o direito e o ant seria o esquerdo veja que isso faz com que tenhamos a ideia de qual caixa esta na frente ou atras
    Agendamento* dados;
    struct NoFila* proximo;
    struct NoFila* anterior;
}NoFila;

void conectarProximo(NoFila* atual, NoFila* proximo);
void conectarAnteiror(NoFila* atual, NoFila* anterior);
Agendamento* ObeterDadosFila(NoFila* no);


#endif //AGENDAMENTO_DE_VISITIAS_NOFILA_H
