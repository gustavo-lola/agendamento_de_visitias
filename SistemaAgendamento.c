#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/sistema/sistema.h"

void lerLinha(char* buffer, int tamanho) {
    fgets(buffer, tamanho, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

void menuPrincipal() {
    SistemaAgendamento* sistema = inicializarSistema();
    if (sistema == NULL) {
        printf("Erro ao inicializar o sistema.\n");
        return;
    }

    int opcao = -1;
    char buffer[100];

    while (opcao != 0) {
        printf("\n---------------------------------\n");
        printf("   SISTEMA DE AGENDAMENTOS\n");
        printf("---------------------------------\n");
        printf("1 - Fazer agendamento\n");
        printf("2 - Cancelar agendamento\n");
        printf("3 - Listar agendamentos ativos\n");
        printf("4 - Listar histórico\n");
        printf("0 - Sair\n");
        printf("Opção: ");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            opcao = atoi(buffer);
        } else {
            opcao = 0;
        }

        switch (opcao) {
            case 1: {
                char usuario[100];
                char recurso[100];
                char data[100];
                char horario[100];

                printf("\n--- Novo Agendamento ---\n");
                printf("Nome do usuário: ");
                lerLinha(usuario, sizeof(usuario));
                printf("Recurso: ");
                lerLinha(recurso, sizeof(recurso));
                printf("Data (DD/MM/AAAA): ");
                lerLinha(data, sizeof(data));
                printf("Horário (HH:MM): ");
                lerLinha(horario, sizeof(horario));

                int id = fazerAgendamento(sistema, usuario, recurso, data, horario);
                if (id != -1) {
                    printf("Sucesso! Agendamento ATIVO criado com ID: %d\n", id);
                } else {
                    printf("Erro: recurso indisponível ou falha ao realizar agendamento.\n");
                }
                break;
            }
            case 2: {
                int id;
                printf("\n--- Cancelar Agendamento ---\n");
                printf("Digite o ID do agendamento a cancelar: ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                    id = atoi(buffer);
                    if (cancelarAgendamento(sistema, id)) {
                        printf("Agendamento %d cancelado e movido para o histórico.\n", id);
                    } else {
                        printf("Erro: Agendamento com ID %d não encontrado.\n", id);
                    }
                }
                break;
            }
            case 3:
                exibirAgendamentos(sistema);
                break;
            case 4:
                exibirHistorico(sistema);
                break;
            case 0:
                printf("\nEncerrando o sistema e limpando memória...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }
    }

    liberarSistema(sistema);
}

int main() {
    menuPrincipal();
    return 0;
}
