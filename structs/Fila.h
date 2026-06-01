//
// Created by Gustavo on 01/06/26.
//

#ifndef AGENDAMENTO_DE_VISITIAS_FILA_H
#define AGENDAMENTO_DE_VISITIAS_FILA_H
#include "NoFila.h"

typedef struct {
    NoFila* fila;
    NoFila* proxima;
    int tamanho;
} Fila;

void inserirFila(Fila* f, NoFila* no);
Agendamento* removerFila(Fila* f, int id);
Agendamento* buscarFila(Fila* f, int id);
void listarFila(Fila* f);
int estaVaziaFila(Fila* f);

#endif //AGENDAMENTO_DE_VISITIAS_FILA_H
