#include <stdio.h>

int main() {
    // Desafio Batalha Naval - MateCheck
    // Nivel Novato - Posicionamento dos Navios
    // Neste nivel, eu vou criar um tabuleiro 10x10 e posicionar dois navios:
    // um navio na vertical e outro navio na horizontal.

    // Aqui eu criei a matriz do tabuleiro.
    // A matriz tem 10 linhas e 10 colunas.
    int tabuleiro[10][10];

    // Aqui eu defini o tamanho dos navios.
    // Cada navio vai ocupar 3 posicoes no tabuleiro.
    int tamanhoNavio = 3;

    // Coordenadas iniciais do navio vertical.
    // Ele vai comecar na linha 1 e coluna 2.
    int linhaNavioVertical = 1;
    int colunaNavioVertical = 2;

    // Coordenadas iniciais do navio horizontal.
    // Ele vai comecar na linha 5 e coluna 4.
    int linhaNavioHorizontal = 5;
    int colunaNavioHorizontal = 4;

    // Aqui eu preencho todo o tabuleiro com 0.
    // O numero 0 representa agua, ou seja, uma posicao vazia.
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Aqui eu posiciono o navio vertical no tabuleiro.
    // A linha aumenta a cada repeticao e a coluna continua a mesma.
    // O numero 3 representa uma parte do navio.
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
    }

    // Aqui eu posiciono o navio horizontal no tabuleiro.
    // A coluna aumenta a cada repeticao e a linha continua a mesma.
    // O numero 3 representa uma parte do navio.
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
    }

    // Aqui eu mostro as coordenadas de cada parte do navio vertical.
    printf("===== Coordenadas do Navio Vertical =====\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        printf("Parte %d: Linha %d, Coluna %d\n", i + 1, linhaNavioVertical + i, colunaNavioVertical);
    }

    printf("\n");

    // Aqui eu mostro as coordenadas de cada parte do navio horizontal.
    printf("===== Coordenadas do Navio Horizontal =====\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        printf("Parte %d: Linha %d, Coluna %d\n", i + 1, linhaNavioHorizontal, colunaNavioHorizontal + i);
    }

    printf("\n");

    // Aqui eu exibo o tabuleiro completo no console.
    // 0 significa agua.
    // 3 significa parte de um navio.
    printf("===== Tabuleiro Batalha Naval =====\n\n");

    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}