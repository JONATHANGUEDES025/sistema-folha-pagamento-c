#include <ctype.h>
#include <stdio.h>

#define LIMITE_HORAS_SEMANAIS 40.0
#define ADICIONAL_HORA_EXTRA 0.50
#define TAMANHO_NOME 100

/*
 * Le um valor numerico maior ou igual a zero.
 * O laco repete a solicitacao quando a entrada e invalida.
 */
double lerValorNaoNegativo(const char *mensagem) {
    double valor;
    int leituraValida;
    int caractere;

    do {
        printf("%s", mensagem);
        leituraValida = scanf("%lf", &valor);

        if (leituraValida != 1) {
            printf("Entrada invalida. Digite um numero maior ou igual a zero.\n");
        } else if (valor < 0.0) {
            printf("O valor nao pode ser negativo. Tente novamente.\n");
        }

        while ((caractere = getchar()) != '\n' && caractere != EOF) {
            /* Limpa os caracteres restantes da linha de entrada. */
        }
    } while (leituraValida != 1 || valor < 0.0);

    return valor;
}

/*
 * Calcula o salario semanal e informa, por referencia, as parcelas do calculo.
 * Horas acima de 40 sao remuneradas com o valor da hora acrescido de 50%.
 */
double calcularSalario(double horasTrabalhadas,
                       double valorHora,
                       double *horasExtras,
                       double *salarioHorasNormais,
                       double *pagamentoHorasExtras) {
    double horasNormais = horasTrabalhadas;

    *horasExtras = 0.0;

    if (horasTrabalhadas > LIMITE_HORAS_SEMANAIS) {
        horasNormais = LIMITE_HORAS_SEMANAIS;
        *horasExtras = horasTrabalhadas - LIMITE_HORAS_SEMANAIS;
    }

    *salarioHorasNormais = horasNormais * valorHora;
    *pagamentoHorasExtras = *horasExtras * valorHora
                           * (1.0 + ADICIONAL_HORA_EXTRA);

    return *salarioHorasNormais + *pagamentoHorasExtras;
}

/* Exibe os dados do funcionario e o detalhamento do salario calculado. */
void exibirResultado(const char *nome,
                     double horasTrabalhadas,
                     double valorHora,
                     double horasExtras,
                     double salarioHorasNormais,
                     double pagamentoHorasExtras,
                     double salarioTotal) {
    printf("\n--- RESULTADO DA FOLHA SEMANAL ---\n");
    printf("Funcionario: %s\n", nome);
    printf("Horas trabalhadas: %.2f\n", horasTrabalhadas);
    printf("Valor da hora: R$ %.2f\n", valorHora);
    printf("Horas extras: %.2f\n", horasExtras);
    printf("Salario pelas horas normais: R$ %.2f\n", salarioHorasNormais);
    printf("Pagamento das horas extras: R$ %.2f\n", pagamentoHorasExtras);
    printf("SALARIO TOTAL: R$ %.2f\n", salarioTotal);
}

int main(void) {
    char nome[TAMANHO_NOME];
    char continuar;

    do {
        double horasTrabalhadas;
        double valorHora;
        double horasExtras;
        double salarioHorasNormais;
        double pagamentoHorasExtras;
        double salarioTotal;

        printf("=== SISTEMA DE FOLHA DE PAGAMENTO ===\n");
        printf("Nome do funcionario: ");
        scanf(" %99[^\n]", nome);

        horasTrabalhadas = lerValorNaoNegativo("Horas trabalhadas na semana: ");
        valorHora = lerValorNaoNegativo("Valor da hora (R$): ");

        salarioTotal = calcularSalario(horasTrabalhadas,
                                       valorHora,
                                       &horasExtras,
                                       &salarioHorasNormais,
                                       &pagamentoHorasExtras);

        exibirResultado(nome,
                        horasTrabalhadas,
                        valorHora,
                        horasExtras,
                        salarioHorasNormais,
                        pagamentoHorasExtras,
                        salarioTotal);

        printf("\nDeseja calcular outro funcionario? (S/N): ");
        scanf(" %c", &continuar);
        continuar = (char)toupper((unsigned char)continuar);
        printf("\n");
    } while (continuar == 'S');

    printf("Programa encerrado.\n");
    return 0;
}
