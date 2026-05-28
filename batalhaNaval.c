#include <stdio.h>

int main() {
    // Desafio Batalha Naval - MateCheck
    // Nivel Aventureiro - Tabuleiro completo e navios diagonais
    // Neste nivel, eu uso uma matriz 10x10 para representar o tabuleiro.
    // O numero 0 representa agua e o numero 3 representa parte de um navio.

    int tabuleiro[10][10];
    int tamanhoNavio = 3;

    // Coordenadas iniciais dos navios
    // Navio 1: vertical
    int linhaVertical = 1;
    int colunaVertical = 2;

    // Navio 2: horizontal
    int linhaHorizontal = 5;
    int colunaHorizontal = 4;

    // Navio 3: diagonal principal
    // A linha e a coluna aumentam juntas
    int linhaDiagonal1 = 0;
    int colunaDiagonal1 = 0;

    // Navio 4: diagonal secundaria
    // A linha aumenta e a coluna diminui
    int linhaDiagonal2 = 2;
    int colunaDiagonal2 = 7;

    // Aqui eu inicializo todo o tabuleiro com 0.
    // Isso significa que, no inicio, todas as posicoes sao agua.
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Aqui eu posiciono o navio vertical.
    // A linha muda e a coluna fica fixa.
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    // Aqui eu posiciono o navio horizontal.
    // A coluna muda e a linha fica fixa.
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // Aqui eu posiciono o primeiro navio diagonal.
    // A linha e a coluna aumentam ao mesmo tempo.
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = 3;
    }

    // Aqui eu posiciono o segundo navio diagonal.
    // A linha aumenta e a coluna diminui.
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = 3;
    }

    // Aqui eu mostro as coordenadas do navio vertical.
    printf("===== Coordenadas do Navio Vertical =====\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        printf("Parte %d: Linha %d, Coluna %d\n", i + 1, linhaVertical + i, colunaVertical);
    }

    printf("\n");

    // Aqui eu mostro as coordenadas do navio horizontal.
    printf("===== Coordenadas do Navio Horizontal =====\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        printf("Parte %d: Linha %d, Coluna %d\n", i + 1, linhaHorizontal, colunaHorizontal + i);
    }

    printf("\n");

    // Aqui eu mostro as coordenadas do primeiro navio diagonal.
    printf("===== Coordenadas do Navio Diagonal 1 =====\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        printf("Parte %d: Linha %d, Coluna %d\n", i + 1, linhaDiagonal1 + i, colunaDiagonal1 + i);
    }

    printf("\n");

    // Aqui eu mostro as coordenadas do segundo navio diagonal.
    printf("===== Coordenadas do Navio Diagonal 2 =====\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        printf("Parte %d: Linha %d, Coluna %d\n", i + 1, linhaDiagonal2 + i, colunaDiagonal2 - i);
    }

    printf("\n");

    // Aqui eu exibo o tabuleiro completo.
    // 0 = agua
    // 3 = navio
    printf("===== Tabuleiro Batalha Naval =====\n\n");

    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}