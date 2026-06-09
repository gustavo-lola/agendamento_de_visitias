#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#define STATUS_ATIVO 1
#define STATUS_CANCELADO 2
#define STATUS_CONCLUIDO 3

typedef struct {
    int id;
    char usuario[100];
    char recurso[50];
    char data[11];
    char horario[6];
    int status;
} Agendamento;

Agendamento* criarAgendamento(
    int id,
    char usuario[100],
    char recurso[50],
    char data[11],
    char horario[6],
    int status
);

void atualizarStatus(
    Agendamento* agendamento,
    int novoStatus
);

void obterResumo(
    Agendamento* agendamento
);

#endif // AGENDAMENTO_H
