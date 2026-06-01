#ifndef AGENDAMENTO_DE_VISITIAS_FILA_H
#define AGENDAMENTO_DE_VISITIAS_FILA_H
#include "NoFila.h"

typedef struct {
    NoFila* inicio;
    NoFila* fim;
    int tamanho;
} Fila;

void inserir(Fila* f, NoFila* no);
Agendamento* remover(Fila* f, int id);
Agendamento* buscar(Fila* f, int id);
void listarFila(Fila* f);
int estaVaziaFila(Fila* f);

#endif //AGENDAMENTO_DE_VISITIAS_FILA_H