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

Reserva reservas[ RESERVAS]; // Array para armazenar as reservas
int totalReservas = 0; // Contador de reservas feitas

// Declaração das funções
void fazerReserva();
void listarReservas();
void totalPessoasPorDia();
void menu();
const char* diaSemana(int dia);

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
        printf("CPF: ");
        scanf(" %s", novaReserva.cpf); // Lê o CPF
        printf("Dia da reserva (1-Quinta, 2-Sexta, 3-Sábado, 4-Domingo): ");
        scanf("%d", &novaReserva.dia); // Lê o dia da reserva
        printf("Quantidade de pessoas: ");
        scanf("%d", &novaReserva.quantidadePessoas); // Lê a quantidade de pessoas

        reservas[totalReservas] = novaReserva; // Adiciona a reserva no array
        totalReservas++; // Incrementa o contador de reservas
        printf("Reserva feita com sucesso!\n");
    } else {
        printf("Limite de reservas atingido!\n");
    }
}

// Função para listar todas as reservas
void listarReservas() {
    if (totalReservas == 0) {
        printf("Nenhuma reserva cadastrada.\n");
        return;
    }
    int i;
    for (i = 0; i < totalReservas; i++) {
        printf("Reserva %d\n", i + 1);
        printf("Nome: %s\n", reservas[i].nome);
        printf("CPF: %s\n", reservas[i].cpf);
        printf("Dia: %s\n", diaSemana(reservas[i].dia)); // Mostra o dia da semana
        printf("Quantidade de pessoas: %d\n", reservas[i].quantidadePessoas);
        printf("-------------------------------\n");
    }
}

// Função para mostrar o total de pessoas por dia
void totalPessoasPorDia() {
    int dia;
    int totalPessoas = 0;
    printf("Informe o dia (1-Quinta, 2-Sexta, 3-Sábado, 4-Domingo): ");
    scanf("%d", &dia); // Lê o dia para a consulta

    int i;
    for (i = 0; i < totalReservas; i++) {
        if (reservas[i].dia == dia) {
            totalPessoas += reservas[i].quantidadePessoas; // Soma as pessoas reservadas no dia
        }
    }
    printf("Total de pessoas reservadas para o dia %s: %d\n", diaSemana(dia), totalPessoas);
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

// Função para converter o número do dia para o nome do dia da semana
const char* diaSemana(int dia) {
    switch (dia) {
        case 1: return "Quinta-feira";
        case 2: return "Sexta-feira";
        case 3: return "Sábado";
        case 4: return "Domingo";
        default: return "Dia inválido";
    }
}
