#include <stdio.h>
#include <string.h>
#include <locale.h>

#define RESERVAS 100 // Define o número máximo de reservas

// Estrutura para armazenar os dados de uma reserva
typedef struct {
    char nome[50];
    char cpf[12];
    int dia;
    int quantidadePessoas;
} Reserva;

Reserva reservas[RESERVAS]; // Array para armazenar as reservas
int totalReservas = 0; // Contador de reservas feitas

// Declaração das funções
void fazerReserva();
void listarReservas();
void totalPessoasPorDia();
void menu();

int main() {
    setlocale(LC_ALL, "Portuguese"); // Ajusta a localidade para Português
    menu(); // Chama o menu principal
    return 0;
}

// Função para fazer uma nova reserva
void fazerReserva() {
    if (totalReservas < RESERVAS) {
        Reserva novaReserva;
        printf("Nome do responsável: ");
        scanf(" %[^\n]", novaReserva.nome); // Lê o nome do responsável
        fflush(stdin);
        printf("CPF: ");
        scanf(" %s", novaReserva.cpf); // Lê o CPF
        fflush(stdin);
        printf("Dia da reserva (1-Quinta, 2-Sexta, 3-Sábado, 4-Domingo): ");
        scanf("%d", &novaReserva.dia); // Lê o dia da reserva
        fflush(stdin);
        printf("Quantidade de pessoas: ");
        scanf("%d", &novaReserva.quantidadePessoas); // Lê a quantidade de pessoas
        fflush(stdin);

        reservas[totalReservas] = novaReserva; // Adiciona a reserva no array
        totalReservas++; // Incrementa o contador de reservas
        printf("Reserva feita com sucesso!\n");
        system("pause");
        system("cls");
    } else {
        printf("Limite de reservas atingido!\n");
        system("pause");
        system("cls");
    }
}

// Função para listar todas as reservas
void listarReservas() {
    if (totalReservas == 0) {
        printf("Nenhuma reserva cadastrada.\n");
        system("pause");
        system("cls");
        return;
    }
    int i;
    for (i = 0; i < totalReservas; i++) {
        printf("Nome: %s\n", reservas[i].nome);
        printf("CPF: %s\n", reservas[i].cpf);
        printf("Dia: %d\n", reservas[i].dia);
        printf("Número de Pessoas: %d\n", reservas[i].quantidadePessoas);
        printf("===============================\n");
    }
    system("pause");
    system("cls");
}

// Função para mostrar o total de pessoas por dia
void totalPessoasPorDia() {
    int dia;
    int totalPessoas = 0;
    printf("Informe o dia (1-Quinta, 2-Sexta, 3-Sábado, 4-Domingo): ");
    scanf("%d", &dia); // Lê o dia para a consulta
    fflush(stdin);

    int i;
    for (i = 0; i < totalReservas; i++) {
        if (reservas[i].dia == dia) {
            totalPessoas += reservas[i].quantidadePessoas; // Soma as pessoas reservadas no dia
        }
    }
    printf("Total de pessoas reservadas para o dia %d: %d\n", dia, totalPessoas);
    system("pause");
    system("cls");
}

// Função para exibir o menu e escolher opções
void menu() {
    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Fazer Reserva\n");
        printf("2. Listar Reservas\n");
        printf("3. Total de Pessoas por Dia\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário
        fflush(stdin);
        switch (opcao) {
            case 1:
                fazerReserva();
                break;
            case 2:
                listarReservas();
                break;
            case 3:
                totalPessoasPorDia();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);
}
