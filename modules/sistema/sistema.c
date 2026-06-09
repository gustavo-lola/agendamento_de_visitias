#include "sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SistemaAgendamento* inicializarSistema() {
    SistemaAgendamento* sistema = (SistemaAgendamento*)malloc(sizeof(SistemaAgendamento));
    if (sistema != NULL) {
        sistema->agendamentos = criarFila();
        sistema->filaEspera = criarFila();
        sistema->historico = criarPilha();
        sistema->proximoId = 1;
    }
    return sistema;
}

int verificarDisponibilidade(SistemaAgendamento* sistema, char* recurso, char* data) {
    if (sistema == NULL || sistema->agendamentos == NULL) {
        return 0;
    }
    No* atual = sistema->agendamentos->inicio;
    while (atual != NULL) {
        if (atual->dados != NULL && atual->dados->status == STATUS_ATIVO) {
            if (strcmp(atual->dados->recurso, recurso) == 0 &&
                strcmp(atual->dados->data, data) == 0) {
                return 0;
            }
        }
        atual = atual->proximo;
    }
    return 1;
}

int fazerAgendamento(
    SistemaAgendamento* sistema,
    char* usuario,
    char* recurso,
    char* data,
    char* horario
) {
    if (sistema == NULL) {
        return -1;
    }

    int id = sistema->proximoId;
    int disponivel = verificarDisponibilidade(sistema, recurso, data);
    int status = disponivel ? STATUS_ATIVO : STATUS_ESPERA;

    Agendamento* novo = criarAgendamento(id, usuario, recurso, data, horario, status);
    if (novo == NULL) {
        return -1;
    }

    if (disponivel) {
        inserirFila(sistema->agendamentos, novo);
    } else {
        inserirFila(sistema->filaEspera, novo);
    }

    sistema->proximoId++;
    return id;
}

int cancelarAgendamento(SistemaAgendamento* sistema, int id) {
    if (sistema == NULL) {
        return 0;
    }

    Agendamento* ag = buscarFila(sistema->agendamentos, id);
    int deFilaEspera = 0;
    if (ag == NULL) {
        ag = buscarFila(sistema->filaEspera, id);
        deFilaEspera = 1;
    }

    if (ag == NULL) {
        return 0;
    }

    // Alterar status
    atualizarStatus(ag, STATUS_CANCELADO);

    // Mover para historico e remover da fila correspondente
    moverParaHistorico(sistema, id);

    // Se removeu um agendamento ativo, tenta promover o primeiro da fila de espera
    if (!deFilaEspera) {
        promoverFilaEspera(sistema);
    }

    return 1;
}

void promoverFilaEspera(SistemaAgendamento* sistema) {
    if (sistema == NULL || sistema->filaEspera == NULL || sistema->filaEspera->inicio == NULL) {
        return;
    }

    // Verifica o primeiro item da fila de espera (FIFO)
    No* primeiroNo = sistema->filaEspera->inicio;
    Agendamento* ag = primeiroNo->dados;

    if (ag != NULL) {
        // Verifica se o recurso ficou disponível
        if (verificarDisponibilidade(sistema, ag->recurso, ag->data)) {
            removerFila(sistema->filaEspera, ag->id);
            atualizarStatus(ag, STATUS_ATIVO);
            inserirFila(sistema->agendamentos, ag);
            printf("Fila de Espera: Agendamento ID %d promovido para ATIVO (Recurso %s liberado).\n", ag->id, ag->recurso);
        }
    }
}

void moverParaHistorico(SistemaAgendamento* sistema, int id) {
    if (sistema == NULL) {
        return;
    }

    // Tenta remover da fila de ativos
    Agendamento* ag = removerFila(sistema->agendamentos, id);
    if (ag == NULL) {
        ag = removerFila(sistema->filaEspera, id);
    }

    if (ag != NULL) {
        empilhar(sistema->historico, ag);
    }
}

void exibirAgendamentos(SistemaAgendamento* sistema) {
    if (sistema == NULL) {
        return;
    }
    printf("\n--- Agendamentos Ativos ---\n");
    listarFila(sistema->agendamentos);
}

void exibirFilaEspera(SistemaAgendamento* sistema) {
    if (sistema == NULL) {
        return;
    }
    printf("\n--- Fila de Espera ---\n");
    listarFila(sistema->filaEspera);
}

void exibirHistorico(SistemaAgendamento* sistema) {
    if (sistema == NULL) {
        return;
    }
    printf("\n--- Histórico de Agendamentos ---\n");
    listarPilha(sistema->historico);
}

void liberarSistema(SistemaAgendamento* sistema) {
    if (sistema == NULL) {
        return;
    }
    liberarFila(sistema->agendamentos);
    liberarFila(sistema->filaEspera);
    liberarPilha(sistema->historico);
    free(sistema);
}
