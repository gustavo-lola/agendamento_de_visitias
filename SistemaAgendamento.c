#include <stdio.h>
#include <stdlib.h>
#include "structs/agendamento.h"
#include "structs/Fila.h"
typedef struct {
    Fila filaAgendamentos;
    Fila filaEspera;
    int proximoId;
} SistemaAgendamento;

int main() {
    printf("Sistema de Agendamento iniciado!\n");
    return 0;
}