#ifndef AGENDAMENTO_DE_VISITIAS_FILA_H
#define AGENDAMENTO_DE_VISITIAS_FILA_H

#include "No.h"

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;

Fila* criarFila();
void inserirFila(Fila* fila, Agendamento* agendamento);
Agendamento* removerFila(Fila* fila, int id);
Agendamento* buscarFila(Fila* fila, int id);
void listarFila(Fila* fila);
int estaVaziaFila(Fila* fila);
void liberarFila(Fila* fila);

#endif // AGENDAMENTO_DE_VISITIAS_FILA_H
