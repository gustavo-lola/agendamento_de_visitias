#include "agendamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Agendamento* criarAgendamento(
    int id,
    char usuario[100],
    char recurso[50],
    char data[11],
    char horario[6],
    int status
) {
    Agendamento* novo = (Agendamento*)malloc(sizeof(Agendamento));
    if (novo == NULL) {
        return NULL;
    }
    novo->id = id;
    
    strncpy(novo->usuario, usuario, sizeof(novo->usuario) - 1);
    novo->usuario[sizeof(novo->usuario) - 1] = '\0';
    
    strncpy(novo->recurso, recurso, sizeof(novo->recurso) - 1);
    novo->recurso[sizeof(novo->recurso) - 1] = '\0';
    
    strncpy(novo->data, data, sizeof(novo->data) - 1);
    novo->data[sizeof(novo->data) - 1] = '\0';
    
    strncpy(novo->horario, horario, sizeof(novo->horario) - 1);
    novo->horario[sizeof(novo->horario) - 1] = '\0';
    
    novo->status = status;
    return novo;
}

void atualizarStatus(Agendamento* agendamento, int novoStatus) {
    if (agendamento != NULL) {
        agendamento->status = novoStatus;
    }
}

void obterResumo(Agendamento* agendamento) {
    if (agendamento == NULL) {
        return;
    }
    printf("ID: %d\n", agendamento->id);
    printf("Usuário: %s\n", agendamento->usuario);
    printf("Recurso: %s\n", agendamento->recurso);
    printf("Data: %s\n", agendamento->data);
    printf("Horário: %s\n", agendamento->horario);
    
    printf("Status: ");
    switch (agendamento->status) {
        case STATUS_ATIVO:
            printf("Ativo\n");
            break;
        case STATUS_CANCELADO:
            printf("Cancelado\n");
            break;
        case STATUS_CONCLUIDO:
            printf("Concluído\n");
            break;
        default:
            printf("Desconhecido\n");
            break;
    }
}
