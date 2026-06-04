#ifndef FILA_H
#define FILA_H

#include "../agendamento/agendamento.h"

typedef struct NoFila {
    Agendamento* agendamento;
    struct NoFila* prox;
} NoFila;

typedef struct {
    NoFila* inicio;
    NoFila* fim;
} Fila;

Fila* criarFila();
void inserirFila(Fila* fila, Agendamento* agendamento);
Agendamento* removerFila(Fila* fila, int id);
Agendamento* buscarFila(Fila* fila, int id);
void listarFila(Fila* fila);
void liberarFila(Fila* fila);

#endif // FILA_H
