#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// Struct pra nao precisar ficar criando variavel nova de cada carta criada
typedef struct {
    int id;
    char estado;
    char codigo[4];
    char nomeDaCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int qtdPontosTuristicos;
    float densidade;
    float pibPerCapta;
    float superPoder;
} Carta;
// func pra criar nova carta
Carta* dadosNovaCarta(int id) {
    // alocando memoria pro dado do tipo Carta pra variavel carta
    Carta* dados = (Carta*)malloc(sizeof(Carta));

    printf("Digite os dados da carta %d \n", id);
    dados-> id = id;

    printf("Digite Uma letra de 'A' a 'H' (representando um dos oito estados)\n");
    scanf(" %c", &dados->estado);

    printf("Digite a letra do estado seguida de um numero de 01 a 04.\n");
    scanf("%3s", dados->codigo);

    printf("Digite o nome da cidade.\n");
    getchar();
    fgets(dados->nomeDaCidade, sizeof(dados->nomeDaCidade), stdin);
    dados->nomeDaCidade[strcspn(dados->nomeDaCidade, "\n")] = '\0';

    printf("Digite o numero de habitantes da cidade.\n");
    scanf("%lu", &dados->populacao);

    printf("Digite a area da cidade em quilometros quadrados.\n");
    scanf("%f", &dados->area);

    printf("Digite o Produto Interno Bruto da cidade.\n");
    scanf("%f", &dados->pib);

    printf("Digite a quantidade de pontos turisticos na cidade.\n");
    scanf("%d", &dados->qtdPontosTuristicos);

    dados->densidade = 0.0;
    dados->pibPerCapta = 0.0;
    dados->superPoder = 0.0;

    return dados;
}
// func pra atribuir os valores passados na func dadosNovaCarta e retornar a carta e seus valores
Carta* novaCarta(Carta *dados) {
    // alocando memoria pro dado do tipo Carta pra variavel carta
    Carta *carta = (Carta*)malloc(sizeof(Carta));
    // proteção caso carta receber NULL
    if (carta != NULL) {
        //atribuindo os dados que vao ser passados na variavel carta
        *carta = *dados;
        // atribuindo valores de densidade e pibpercapta
        carta->densidade = (float) carta->populacao / carta->area;
        carta->pibPerCapta = (float) carta->pib / carta->populacao;
        carta->superPoder = (float) carta->populacao + carta->area + carta->pib + carta->qtdPontosTuristicos + carta->pibPerCapta + carta->area / carta->populacao; // o final é pra pegar o inverso da densidade
    }
    //retorna a carta criada
    return carta;
}
// func pra exibir os dados das cartas
void exibirCarta(Carta *carta) {
    printf("Carta %d\n", carta->id);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("População: %lu\n", carta->populacao);
    printf("Área: %f km²\n", carta->area);
    printf("PIB: %.2f bilhoes de reais\n", carta->pib);
    printf("Número de Pontos Turísticos %d\n", carta->qtdPontosTuristicos);+
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade);
    printf("PIB per Capita: %2f reais\n", carta->pibPerCapta);
}
// func que vai receber os valroes das cartas e comparar
void compararCartas(Carta* carta1, Carta* carta2) {
    printf("Comparação de Cartas:\n");
    printf("População: Carta %d venceu\n", (carta1->populacao > carta2->populacao) ? carta1->id: carta2->id);
    printf("Área: Carta %d venceu\n", (carta1->area > carta2->area) ? carta1->id: carta2->id);
    printf("PIB: Carta %d venceu\n", (carta1->pib > carta2->pib) ? carta1->id: carta2->id);
    printf("Pontos Turísticos: Carta %d venceu\n", (carta1->qtdPontosTuristicos > carta2->qtdPontosTuristicos) ? carta1->id: carta2->id);
    printf("Densidade Populacional: Carta %d venceu\n", (carta1->densidade > carta2->densidade) ? carta1->id: carta2->id);
    printf("PIB per Capita: Carta %d venceu\n", (carta1->pibPerCapta > carta2->pibPerCapta) ? carta1->id: carta2->id);
    printf("Super Poder: Carta %d venceu\n", (carta1->superPoder > carta2->superPoder) ? carta1->id: carta2->id);
}


int main(){
    // setlocale pra nao ficar bugando palavra com acento no print
    setlocale(LC_ALL, "pt_BR.UTF-8");
    // ta sem validaçã os dados digitados, como nao pediu pra validar nao fiz
    Carta* dados = dadosNovaCarta(1);
    Carta* carta1 = novaCarta(dados);
    free(dados);

    Carta* dados2 = dadosNovaCarta(2);
    Carta* carta2 = novaCarta(dados2);
    free(dados2);
    // caso queira exibir os dados da carta, só chamar a função a baixo, deixei comentado pois o desafio mestre nao
    // exibirCarta(carta1);

    // passo os dados das cartas 1 e 2 pra função comparar
    compararCartas(carta1, carta2);
    return 0;
}
