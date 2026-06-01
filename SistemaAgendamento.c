//
// Created by Gustavo on 01/06/26.
//
#include <stdio.h>
#include <stdlib.h>
#include "structs/agendamento.h"
#include "structs/Fila.h"
typedef struct {
    Fila filaAgenamento;
    Fila filaEspera;
    Pilha pilhaHistorico;
    int proximoId;
} SistemaAgendamento;

int main() {
    printf("Sistema de Agenamento iniciado!");

    return 0;
}