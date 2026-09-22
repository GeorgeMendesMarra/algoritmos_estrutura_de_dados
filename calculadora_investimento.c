#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

void configurarConsole(void) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}

void limparTela(void) {
    system(LIMPAR_TELA);
}

void pausar(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void imprimirLinha(void) {
    printf("+----------+------------------+------------------+------------------+\n");
}

/* Simula rendimento simples: juros calculados sempre sobre o valor inicial (capital),
   ou seja, os juros de cada periodo nao sao reinvestidos (nao compostos). */
void simularRendimentoSimples(double capital, double taxaMensal, int meses) {
    double jurosPorMes = capital * (taxaMensal / 100.0);
    double totalJuros = 0.0;
    double saldo = capital;

    limparTela();
    printf("===========================================================\n");
    printf("           SIMULACAO DE RENDIMENTO SIMPLES\n");
    printf("===========================================================\n");
    printf("Capital inicial : R$ %.2f\n", capital);
    printf("Taxa mensal     : %.2f%%\n", taxaMensal);
    printf("Periodo         : %d meses\n", meses);
    printf("-----------------------------------------------------------\n\n");

    imprimirLinha();
    printf("|   Mes    |   Juros do mes   |   Total de juros |   Saldo total    |\n");
    imprimirLinha();

    for (int mes = 1; mes <= meses; mes++) {
        totalJuros += jurosPorMes;
        saldo = capital + totalJuros;
        printf("| %8d | R$ %13.2f | R$ %13.2f | R$ %13.2f |\n",
               mes, jurosPorMes, totalJuros, saldo);
    }
    imprimirLinha();

    printf("\n----------------------- RESUMO FINAL -----------------------\n");
    printf("Capital investido       : R$ %.2f\n", capital);
    printf("Total de juros recebidos: R$ %.2f\n", totalJuros);
    printf("Montante final          : R$ %.2f\n", saldo);
    printf("Rentabilidade total     : %.2f%%\n", (totalJuros / capital) * 100.0);
    printf("-------------------------------------------------------------\n");
}

int lerDouble(const char *mensagem, double *valor) {
    printf("%s", mensagem);
    if (scanf("%lf", valor) != 1) {
        while (getchar() != '\n'); /* limpa buffer em caso de erro */
        return 0;
    }
    while (getchar() != '\n'); /* consome o restante da linha (inclui \n) */
    return 1;
}

int lerInt(const char *mensagem, int *valor) {
    printf("%s", mensagem);
    if (scanf("%d", valor) != 1) {
        while (getchar() != '\n');
        return 0;
    }
    while (getchar() != '\n');
    return 1;
}

void exibirMenu(void) {
    limparTela();
    printf("===========================================================\n");
    printf("     CALCULADORA DE SIMULACAO DE INVESTIMENTO (SIMPLES)\n");
    printf("===========================================================\n");
    printf("[1] Nova simulacao\n");
    printf("[2] Sair\n");
    printf("-----------------------------------------------------------\n");
}

int main(void) {
    configurarConsole();
    int opcao;

    do {
        exibirMenu();
        if (!lerInt("Escolha uma opcao: ", &opcao)) {
            printf("\nEntrada invalida!\n");
            pausar();
            continue;
        }

        if (opcao == 1) {
            double capital, taxa;
            int meses;

            limparTela();
            printf("===========================================================\n");
            printf("                    NOVA SIMULACAO\n");
            printf("===========================================================\n");

            if (!lerDouble("Valor do capital inicial (R$): ", &capital) || capital <= 0) {
                printf("\nValor invalido! O capital deve ser maior que zero.\n");
                pausar();
                continue;
            }

            if (!lerDouble("Taxa de juros mensal (%): ", &taxa) || taxa < 0) {
                printf("\nValor invalido! A taxa nao pode ser negativa.\n");
                pausar();
                continue;
            }

            if (!lerInt("Periodo de investimento (em meses): ", &meses) || meses <= 0) {
                printf("\nValor invalido! O periodo deve ser maior que zero.\n");
                pausar();
                continue;
            }

            simularRendimentoSimples(capital, taxa, meses);
            pausar();

        } else if (opcao == 2) {
            printf("\nEncerrando o programa. Ate mais!\n");
        } else {
            printf("\nOpcao invalida! Tente novamente.\n");
            pausar();
        }

    } while (opcao != 2);

    return 0;
}
