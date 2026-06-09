#ifndef SISTEMA_H
#define SISTEMA_H

#include "../agendamento/agendamento.h"
#include "../../structs/Fila.h"
#include "../../structs/Pilha.h"

typedef struct {
    Fila* agendamentos;
    Pilha* historico;
    int proximoId;
} SistemaAgendamento;

SistemaAgendamento* inicializarSistema();

int verificarDisponibilidade(
    SistemaAgendamento* sistema,
    char* recurso,
    char* data
);

int fazerAgendamento(
    SistemaAgendamento* sistema,
    char* usuario,
    char* recurso,
    char* data,
    char* horario
);

int cancelarAgendamento(
    SistemaAgendamento* sistema,
    int id
);

void moverParaHistorico(
    SistemaAgendamento* sistema,
    int id
);

void exibirAgendamentos(
    SistemaAgendamento* sistema
);

void exibirHistorico(
    SistemaAgendamento* sistema
);

void liberarSistema(
    SistemaAgendamento* sistema
);

#endif // SISTEMA_H
