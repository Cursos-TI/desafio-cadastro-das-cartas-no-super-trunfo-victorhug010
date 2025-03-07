#include <stdio.h>
#include <string.h>

int main(){
    //  Variaveis
    char estadoC1, estadoC2;
    char codigoC1[4], codigoC2[4];
    char nomeDaCidadeC1[50], nomeDaCidadeC2[50];
    float areaC1, areaC2;
    float pibC1, pibC2;
    int qtdPontosTuristicosC1, qtdPontosTuristicosC2;
    int populacaoC1, populacaoC2;

    // Inserindo dados carta1
    printf("Digite os dados da carta 1 \n");

    printf("Digite Uma letra de 'A' a 'H' (representando um dos oito estados)\n");
    scanf(" %c", &estadoC1);

    printf("Digite a letra do estado seguida de um numero de 01 a 04.\n");
    scanf("%3s", codigoC1);

    printf("Digite o nome da cidade.\n");
    getchar();
    fgets(nomeDaCidadeC1, sizeof(nomeDaCidadeC1), stdin);
    nomeDaCidadeC1[strcspn(nomeDaCidadeC1, "\n")] = '\0';

    printf("Digite o numero de habitantes da cidade.\n");
    scanf("%d", &populacaoC1);

    printf("Digite a area da cidade em quilometros quadrados.\n");
    scanf("%f", &areaC1);

    printf("Digite o Produto Interno Bruto da cidade.\n");
    scanf("%f", &pibC1);

    printf("Digite a quantidade de pontos turisticos na cidade.\n");
    scanf("%d", &qtdPontosTuristicosC1);

    // Inserindo dados carta2
    printf("Digite os dados da carta 2 \n");

    printf("Digite Uma letra de 'A' a 'H' (representando um dos oito estados)\n");
    scanf(" %c", &estadoC2);

    printf("Digite a letra do estado seguida de um numero de 01 a 04.\n");
    scanf("%3s", codigoC2);

    printf("Digite o nome da cidade.\n");
    getchar();
    fgets(nomeDaCidadeC2, sizeof(nomeDaCidadeC2), stdin);
    nomeDaCidadeC2[strcspn(nomeDaCidadeC2, "\n")] = '\0';

    printf("Digite o numero de habitantes da cidade.\n");
    scanf("%d", &populacaoC2);

    printf("Digite a area da cidade em quilometros quadrados.\n");
    scanf("%f", &areaC2);

    printf("Digite o Produto Interno Bruto da cidade.\n");
    scanf("%f", &pibC2);

    printf("Digite a quantidade de pontos turisticos na cidade.\n");
    scanf("%d", &qtdPontosTuristicosC2);

    // Impressão dados carta1
    printf("Carta 1:\n");
    printf("Estado: %c\n", estadoC1);
    printf("Codigo: %s\n", codigoC1);
    printf("Nome da Cidade: %s\n", nomeDaCidadeC1);
    printf("Populacao: %d\n", populacaoC1);
    printf("Area: %f\n", areaC1);
    printf("PIB: %f\n", pibC1);
    printf("Numero de Pontos Turisticos: %d\n", qtdPontosTuristicosC1);

    // Impressão dados carta2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estadoC2);
    printf("Codigo: %s\n", codigoC2);
    printf("Nome da Cidade: %s\n", nomeDaCidadeC2);
    printf("Populacao: %d\n", populacaoC2);
    printf("Area: %f\n", areaC2);
    printf("PIB: %f\n", pibC2);
    printf("Numero de Pontos Turisticos: %d\n", qtdPontosTuristicosC2);
    return 0;
}
