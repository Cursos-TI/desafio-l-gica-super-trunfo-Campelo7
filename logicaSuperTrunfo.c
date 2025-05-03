#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
struct Carta {
    char estado[30];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta c) {
    printf("Cidade: %s (%s)\n", c.cidade, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", c.pibPerCapita);
    printf("-----------------------------\n");
}

int main() {
    // Declaração das cartas
    struct Carta carta1 = {
        "SP", "001", "São Paulo",
        12300000, 1521.11, 699.28, 20
    };

    struct Carta carta2 = {
        "RJ", "002", "Rio de Janeiro",
        6000000, 1200.27, 364.28, 15
    };

    // Cálculos dos valores derivados
    carta1.densidadePopulacional = calcularDensidadePopulacional(carta1.populacao, carta1.area);
    carta1.pibPerCapita = calcularPIBPerCapita(carta1.pib, carta1.populacao);

    carta2.densidadePopulacional = calcularDensidadePopulacional(carta2.populacao, carta2.area);
    carta2.pibPerCapita = calcularPIBPerCapita(carta2.pib, carta2.populacao);

    // Exibe os dados das duas cartas
    printf("===== Cartas Cadastradas =====\n\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Escolha do atributo para comparação: PIB per capita
    printf("===== Comparação de Cartas (Atributo: PIB per capita) =====\n\n");
    printf("Carta 1 - %s: R$ %.2f\n", carta1.cidade, carta1.pibPerCapita);
    printf("Carta 2 - %s: R$ %.2f\n", carta2.cidade, carta2.pibPerCapita);

    // Comparação com estrutura de decisão
    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
