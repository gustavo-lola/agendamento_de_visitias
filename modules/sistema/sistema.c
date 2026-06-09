#include "sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SistemaAgendamento* inicializarSistema() {
    SistemaAgendamento* sistema = (SistemaAgendamento*)malloc(sizeof(SistemaAgendamento));
    if (sistema != NULL) {
        sistema->agendamentos = criarFila();
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
    if (!verificarDisponibilidade(sistema, recurso, data)) {
        return -1;
    }

    Agendamento* novo = criarAgendamento(id, usuario, recurso, data, horario, STATUS_ATIVO);
    if (novo == NULL) {
        return -1;
    }

    inserirFila(sistema->agendamentos, novo);
    sistema->proximoId++;
    return id;
}

int cancelarAgendamento(SistemaAgendamento* sistema, int id) {
    if (sistema == NULL) {
        return 0;
    }

    Agendamento* ag = buscarFila(sistema->agendamentos, id);
    if (ag == NULL) {
        return 0;
    }

    atualizarStatus(ag, STATUS_CANCELADO);
    moverParaHistorico(sistema, id);

    return 1;
}

void moverParaHistorico(SistemaAgendamento* sistema, int id) {
    if (sistema == NULL) {
        return;
    }

    Agendamento* ag = removerFila(sistema->agendamentos, id);
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
    liberarPilha(sistema->historico);
    free(sistema);
}
